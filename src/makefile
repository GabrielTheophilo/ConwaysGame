CC=g++
CFLAGS=
DELETAVEIS=main.o conwaysgame.o allegro.o a.exe
CPFLAGS=-lallegro -lallegro_image -lallegro_font -lallegro_ttf

all: main

main: main.o conwaysgame.o allegro.o
		${CC} ${CFLAGS} main.o ${CPFLAGS}

main.o: main.cpp
		${CC} ${CFLAGS} -c main.cpp 

regras.o: regras.cpp
		${CC} ${CFLAGS} -c regras.cpp
		
conwaysgame.o: conways_game.h conways_game.cpp
		${CC} ${CFLAGS} -c conways_game.cpp

allegro.o: allegro.h
		${CC} ${CFLAGS} -c allegro.h

clean:
		-del ${DELETAVEIS}