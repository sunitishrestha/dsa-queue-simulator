all:
	g++ -I src/include -L src/lib -o bin/main src/main.cpp -lmingw32 -lSDL2main -lSDL2