#ifndef __SDL_JEU_H__
#define __SDL_JEU_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../gest_matrice.h"
#include "../define.h"
#include "../min_max.h"
#include <string.h>
#include <time.h>
#define SOLO 0
#define DUO 1
#define ONLINE 2
#define QUITTER 3

Mix_Music *music;
t_matrice mat;

int song;
//TEXTURE
SDL_Texture* tex_img_png(char * s, SDL_Renderer* renderer);
SDL_Texture* tex_text(char* font,int size, char* s, SDL_Color color, SDL_Renderer* renderer);
void init_jeuSDL(SDL_Renderer* renderer);

//AFFICHAGE MATRICE / JEU
void afficher_matriceSDL(char joueur);
void afficher_cibleSDL(int x,int y);
int partie_termineeSDL(void);
char afficher_gagnant(void);


//JEU : INTERFACE GRAPHIQUE
int lancement_jeu(int modeJeu);
int menu_SDL(void);

#endif
