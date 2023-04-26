all:
	g++ -ISDL2 -Iutil -Isettings -Llib -o bin/pong src/*.cpp -lmingw32 -lSDL2 -lSDL2main