#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <header.h>

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool running = true;
    Uint32 lastVehicleSpawn = 0;
    const Uint32 SPAWN_INTERVAL = 500; // Spawn a vehicle every 500ms

    srand(time(NULL));

    initializeSDL(&window, &renderer);

    // Initialize vehicles
    Vehicle vehicles[MAX_VEHICLES] = {0};
    int vehicleCount = 0;

    // Initialize traffic lights
    TrafficLight lights[4];
    initializeTrafficLights(lights);

    // Initialize statistics
    Statistics stats = {
        .vehiclesPassed = 0,
        .totalVehicles = 0,
        .vehiclesPerMinute = 0,
        .startTime = SDL_GetTicks()
    };

    // Initialize queues
    for (int i = 0; i < 4; i++) {
        initQueue(&laneQueues[i]);
    }

    while (running) {
        handleEvents(&running);

        // Spawn new vehicles periodically
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastVehicleSpawn >= SPAWN_INTERVAL && vehicleCount < MAX_VEHICLES) {
            Direction spawnDirection = (Direction)(rand() % 4);
            Vehicle* newVehicle = createVehicle(spawnDirection);
            
            // Find empty slot for new vehicle
            for (int i = 0; i < MAX_VEHICLES; i++) {
                if (!vehicles[i].active) {
                    vehicles[i] = *newVehicle;
                    vehicles[i].active = true;
                    vehicleCount++;
                    stats.totalVehicles++;
                    break;
                }
            }
            
            free(newVehicle);
            lastVehicleSpawn = currentTime;
        }

        // Update vehicles
        for (int i = 0; i < MAX_VEHICLES; i++) {
            if (vehicles[i].active) {
                updateVehicle(&vehicles[i], lights);

                // Check if vehicle has passed through intersection
                if (!vehicles[i].active) {
                    stats.vehiclesPassed++;
                    vehicleCount--;
                }
            }
        }

        // Update traffic lights
        updateTrafficLights(lights);

        // Update statistics
        float minutes = (SDL_GetTicks() - stats.startTime) / 60000.0f;
        if (minutes > 0) {
            stats.vehiclesPerMinute = stats.vehiclesPassed / minutes;
        }

        renderSimulation(renderer, vehicles, lights, &stats);

        SDL_Delay(16); // Cap at ~60 FPS
    }

    cleanupSDL(window, renderer);
    return 0;
}