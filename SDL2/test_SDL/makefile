
CC=gcc

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

PROG=P4_SDL
PROG2=sdl_test

all: sdl_text

sdl_text: P4_SDL.c
	${CC} -o ${PROG} P4_SDL.c ${LIBS} ${INCLUDES}

sdl_text: sdl_test.c
	${CC} -o ${PROG2} sdl_test.c ${LIBS} ${INCLUDES}

clean: 
	rm -f ${PROG}
	rm -f *.o


