#include <stdlib.h>
#include <stdio.h>

#define L 6
#define C 7

// Permet de choisir au joueur de placer sa pièce dans la colonne choisit
void joue_bloquante(joueur_t * joueur, case_t mat[L][C]);

void joue_pleine(joueur_t * joueur, case_t mat[L][C]);

void joue_creuse(joueur_t * joueur, case_t mat[L][C]);

void tour_joueur(joueur_t * joueur, case_t mat[L][C]);

