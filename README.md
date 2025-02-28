# dsa-queue-simulator
This project aims to simulate an efficient traffic light management system using Queue Data Structures and Algorithms to optimize vehicle movement at intersections.

# Features
  1. real-time traffic simulation
  2. Queue-based traffic management
  3. Priority handling for emergency vehicles
  4. Vehicle turning mechanics (left, right, straight)

# Prerequirement
 1. gcc,g++ compiler
 2. SDL2 Library
 3. MinGW for windows

# Installing SDL2
 ## On Windows
 1. 1. Download SDL2 development libraries from [SDL's website](https://github.com/libsdl-org/SDL).
2. Extract the contents to your project directory.
3. Create these folders in your project if they don't exist:
   - `include` (for SDL2 header files)
   - `lib` (for SDL2 library files)
   - `bin` (for executable output)

## Project Structure
 DSA-Queue-Simulator/
 
 ├── bin/
 ├── src/
   ├── include/
   ├── lib/
 └── README.md

 # Building the project
   1. Clone the repository:

   ```sh
   git clone https://github.com/sunitishrestha/dsa-Queue-Simulator.git
   cd dsa-Queue-Simulator

 2. Compile both program
   # For main simulator
```sh
gcc -I src/include -L src/lib -o bin/main.exe src/main.c src/simulation.c -lmingw32 -lSDL2main -lSDL2

  # For vechicle generator:
   ```sh
gcc -o bin/generator src/generator.c src/simulation.c  -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2


# Running the simulation
1. Start vechile generator
   ```sh
   .\bin\generator.exe

2. in seperate terminal,run main simulator
 ```sh
 .\bin\main.exe


# Code Structure
 ## Code Structure

- `main.c` : Program entry point and main simulation loop
- `header.h` : Header file containing structs and function declarations
- `simulation.c` : Implementation of traffic simulation logic
- `generator.c` : Vehicle generation logic

 ## Controlls
  1. The simulation runs automatically without user input
  2. Close the window to exit the program

# References

For more details on SDL2, visit the official documentation: [SDL2 Documentation](https://wiki.libsdl.org/)
