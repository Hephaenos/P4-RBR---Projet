#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define L 6
#define C 7

const int BLOQUANTE = 1
const int PLEINE = 2
const int CREUSE = 3

// Choix des pièces, bloquantes, creuses ou pleines
typedef struct piece_s{
	int type;
	char couleur;
}piece_t

// Deux choix possibles par case avec les pièces pleines/bloquantes
typedef struct case_s{
  piece_t * piece1;
  piece_t * piece2;
}case_t

// Choix de la couleur, du pseudo pour chaque joueur
// Meme nombre de pièces bloquantes pour chaque joueur
typedef struct joueur_s{
  char pseudo[10];
  char couleur;
  int nb_bloq;
}joueur_t

joueur_t [i]



// Remplie toute la matrice a nulle
void initialiser_matrice(case_t mat[L][C]){
        int i,j; // i et j sont respectivement la ligne i et la colonne j
        for(i=0;i<L;i++){
                for (j= 0;j<C;j++){
                        mat[i][j]->piece1.type=NULL;
                        mat[i][j]->piece2.type=NULL;
                        mat[i][j]->piece1.couleur=NULL;
                        mat[i][j]->piece2.couleur=NULL;

                }
        }
}


// Creer un joueur avec comme choix le pseudo, la couleur et le nombre
//de pièce bloquante définie en parmaètre
void creer_joueur(joueur_t joueur,int bloquante){
  printf("Saisir le pseudo du joueur : ");
  scanf("%s",joueur.pseudo);
  printf("\nSaisir l'initiale de la couleur que vous voulez : ");
  scanf("%c",joueur.couleur);
  joueur.nb_bloq=bloquante;
}

// Renvoi le nombre de piece bloquante pour tous les joueurs
int choix_piece_bloquante(){
  int nb;
  printf("Saisir le nombre de pièce bloquante pour tous les joueurs : ");
  scanf("%i",&nb);
  return nb;
}
