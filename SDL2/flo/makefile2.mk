
CC=gcc
OPTS=-g -o
CFLAGS=-W -Wall
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=./../lib/
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR}

PROG=flo_sdl_pseudo

all: flo_sdl_pseudo

flo_sdl_pseudo: ${FICHIER_O}
	${CC} ${OPTS} ${PROG} flo_sdl_pseudo.c ${LIBS} ${INCLUDES} ${CFLAGS}
	rm -f *.o
	./${PROG}

clean :
	rm -f *.o
	rm -f ${PROG}