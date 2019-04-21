/**
* \file tour_joueur.c
* \brief Fichier où se touvent les fonctions permettant de savoir quel type de pièce le joueur joue, quel joueur joue et où la pièce va être positionée
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"../Include/P4.h"
#include"../Include/hauteur_piece.h"
#include"../Include/afficher_matrice.h"


/**
* \fn void joue_bloquante(joueur_t * joueur, case_t mat[L][C])
* \brief Place une pièce bloquante dans la matrice
* \param * joueurs : pointeur sur joueur
* \param mat[L][C] : matrice où le joueur met sa pièce
*/
void joue_bloquante(joueur_t * joueur, case_t mat[L][C]){
        int i,j; /* i et j sont respectivement la ligne i et la colonne j */
        do{
          printf("Choisir la colonne où vous voulez mettre votre pièce bloquante (entre 1 et %i) : ",C);
          scanf("%d",&j);
          i = hauteur_piece(j-1,mat, BLOQUANTE); /* Permet de savoir la hauteur du pion */
          if(i<0){
            printf("Colonne déjà remplie ! \n Choisissez une autre colonne\n");
          }
  }while(j<1 || j>C || i<0);

  j--;
  mat[i][j].piece1->type = BLOQUANTE;
  mat[i][j].piece1->couleur = joueur->couleur;
  joueur->nb_bloq--;

}


/**
* \fn void joue_pleine(joueur_t * joueur, case_t mat[L][C])
* \brief place une pièce pleine dans la matrice
* \param * joueurs : pointeur sur joueur
* \param mat[L][C] : matrice où le joueur met sa pièce
*/
void joue_pleine(joueur_t * joueur, case_t mat[L][C]){
        int i,j; /* i et j sont respectivement la ligne i et la colonne j */
        do{
          printf("Choisir la colonne où vous voulez mettre votre pièce pleine (entre 1 et %i) : ",C);
          scanf("%d",&j);
          i = hauteur_piece(j-1,mat, PLEINE); /* Permet de savoir la hauteur du pion */
          if(i<0){
            printf("Coup impossible ! \n Choisissez une autre colonne\n");
          }
        }while(j<1 || j>C || i<0);
        
        j--;

  mat[i][j].piece1->type = PLEINE;
  mat[i][j].piece1->couleur = joueur->couleur;

}


/**
* \fn void joue_creuse(joueur_t * joueur, case_t mat[L][C])
* \brief Place une pièce creuse dans la matrice
* \param * joueurs : pointeur sur joueur
* \param mat[L][C] : matrice où le joueur met sa pièce
*/
void joue_creuse(joueur_t * joueur, case_t mat[L][C]){
        int i,j; /* i et j sont respectivement la ligne i et la colonne j */
        do{
          printf("Choisir la colonne où vous voulez mettre votre pièce creuse (entre 1 et %i) : ",C);
          scanf("%d",&j);
          i = hauteur_piece(j-1,mat, CREUSE);
           /* Permet de savoir la hauteur du pion */
          if(i<0){
            printf("Colonne déjà remplie ! \n Choisissez une autre colonne\n");
          }
        }while(j<1 || j>C || i<0);
        j--;
        mat[i][j].piece2->type = CREUSE;
        mat[i][j].piece2->couleur = joueur->couleur;

}


/**
* \fn void tour_joueur(joueur_t * joueur, case_t mat[L][C])
* \brief Permet de choisir au joueur de placer sa pièce dans la colonne choisit
* \param * joueurs : pointeur sur joueur
* \param mat[L][C] : matrice où le joueur met sa pièce
*/
void tour_joueur(joueur_t * joueur, case_t mat[L][C]){
        int i,j; /* i et j sont respectivement la ligne i et la colonne j */
        int piece; /* Choix de la pièce dans le switch */

        do
        {   /* Affichage de choix de la piece à jouer */

          printf("\nChoix de la pièce à jouer : \n");
          printf(" 1 - Joue une pièce bloquante\n");
          printf(" 2 - Joue une pièce pleine\n");
          printf(" 3 - Joue une pièce creuse\n");
          printf("Votre choix : ");
          scanf("%i",&piece);
          if(piece == 1 && joueur->nb_bloq==0){
            printf("Vous n'avez plus de piece bloquante ! ");
            piece = 0; /* valeur pour recommencer le do while */
          }
        }while(piece<1 || piece >3);
        switch(piece){  /* Traitement du choix de l'utilisateur */
          case 1: joue_bloquante(joueur, mat); break;
          case 2: joue_pleine(joueur, mat); break;
          case 3: joue_creuse(joueur, mat); break;
          default: printf("Erreur, votre choix doit être compris entre 1 et 3");
        }
        afficher_matrice(mat);
}
