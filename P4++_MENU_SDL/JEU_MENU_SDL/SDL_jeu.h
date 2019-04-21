#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <time.h>

#define L 6
#define C 7
#define BLOQUANTE  1
#define PLEINE 2
#define CREUSE 3

// Choix des pièces, bloquantes, creuses ou pleines
typedef struct piece_s{
	int type;
	char couleur;
}piece_t;

// Deux choix possibles par case avec les pièces pleines/bloquantes
typedef struct case_s{
  piece_t * piece1;
  piece_t * piece2;
}case_t;

// Choix de la couleur, du pseudo pour chaque joueur
// Meme nombre de pièces bloquantes pour chaque joueur
typedef struct joueur_s{
  char * pseudo;
  char couleur;
  int nb_bloq;
}joueur_t;



//TEXTURE
SDL_Texture* tex_img_png(char * s, SDL_Renderer* renderer);
SDL_Texture* tex_text(char* font,int size, char* s, SDL_Color color, SDL_Renderer* renderer);
void init_jeuSDL(SDL_Renderer* renderer);

//AFFICHAGE MATRICE / JEU
void afficher_matriceSDL(char joueur);
void afficher_cibleSDL(int x,int y);
int partie_termineeSDL(void);
char afficher_gagnant(void);


//menu: INTERFACE GRAPHIQUE
int lancement_jeu(int modeJeu);
void lancement_jeu2(int i);
void lancement_jeu3(int i);
int menu_SDL(void);
int choix_nbJoueur(void);
int choix_nbBloq(void);
int flo_test_pseudo(int reste_joueur, joueur_t tab[], int nb_bloquante, int place_joueur);
int flo_test_couleur(int reste_joueur, joueur_t tab[], int nb_bloquante, int place_joueur);

// Jeu terminal
void afficher_matrice(case_t mat[L][C]);
int gagne(joueur_t * joueur, case_t mat[L][C]);
int hauteur_piece(int y, case_t mat[L][C], int type_piece);
void initialiser_matrice(case_t mat[L][C]);
void joue_bloquante(joueur_t * joueur, case_t mat[L][C]);
void joue_pleine(joueur_t * joueur, case_t mat[L][C]);
void joue_creuse(joueur_t * joueur, case_t mat[L][C]);
void tour_joueur(joueur_t * joueur, case_t mat[L][C]);
int mat_remplie(case_t mat[L][C]);