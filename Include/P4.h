#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  char pseudo[10];
  char couleur;
  int nb_bloq;
}joueur_t;