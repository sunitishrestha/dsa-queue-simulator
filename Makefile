all:
	gcc -o bin/generator src/generator.c src/traffic_simulation.c  -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2