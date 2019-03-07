#include <stdlib.h>
#include <stdio.h>

#define L 6
#define C 7

// Remplie toute la matrice a nulle
void initialiser_matrice(case_t mat[L][C]);

// Creer un joueur avec comme choix le pseudo, la couleur et le nombre
//de pièce bloquante définie en parmaètre
void creer_joueur(joueur_t joueur,int bloquante);

// Renvoi le nombre de piece bloquante pour tous les joueurs
int choix_piece_bloquante(){