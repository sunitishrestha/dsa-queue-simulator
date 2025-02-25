all:
	gcc -o bin/generator src/generator.c src/simulation.c  -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2
	gcc -I src/include -L src/lib -o bin/main.exe src/main.c src/simulation.c -lmingw32 -lSDL2main -lSDL2