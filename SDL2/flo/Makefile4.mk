CC=gcc
OPTS=-g -o
CFLAGS=-W -Wall
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib/
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR}


flo_SDL : flo_SDL.o flo_choix_nbBloq.o flo_sdl_jeu.o flo_sdl_pseudo.o flo_sdl_couleur.o fonc_texture.o 
	gcc  -g flo_SDL.o flo_choix_nbBloq.o flo_sdl_jeu.o flo_sdl_pseudo.o flo_sdl_couleur.o fonc_texture.o -o flo_SDL ${LIBS} ${INCLUDES} ${CFLAGS}

flo_SDL.o : flo_SDL.c SDL_jeu.h
	gcc -c flo_SDL.c ${LIBS} ${INCLUDES} ${CFLAGS}

flo_choix_nbBloq.o : flo_choix_nbBloq.c SDL_jeu.h
	gcc -c flo_choix_nbBloq.c ${LIBS} ${INCLUDES} ${CFLAGS}

flo_sdl_jeu.o : flo_sdl_jeu.c SDL_jeu.h
	gcc -c flo_sdl_jeu.c ${LIBS} ${INCLUDES} ${CFLAGS}

flo_sdl_pseudo.o : flo_sdl_pseudo.c SDL_jeu.h
	gcc -c flo_sdl_pseudo.c ${LIBS} ${INCLUDES} ${CFLAGS}

flo_sdl_couleur.o : flo_sdl_couleur.c SDL_jeu.h
	gcc -c flo_sdl_couleur.c ${LIBS} ${INCLUDES} ${CFLAGS}

fonc_texture.o : fonc_texture.c SDL_jeu.h
	gcc -c fonc_texture.c ${LIBS} ${INCLUDES} ${CFLAGS}

clean :
	rm  *.o
	rm flo_SDL
