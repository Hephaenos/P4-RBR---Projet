
CC=gcc
OPTS=-g -o
CFLAGS=-W -Wall
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=./../lib/
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR}

PROG=flo_SDL

all: flo_SDL

flo_SDL: ${FICHIER_O}
	${CC} ${OPTS} ${PROG} flo_SDL.c ${LIBS} ${INCLUDES} ${CFLAGS}
	rm -f *.o
	./${PROG}

clean :
	rm -f *.o
	rm -f ${PROG}