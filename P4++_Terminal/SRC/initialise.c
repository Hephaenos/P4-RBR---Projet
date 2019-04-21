/**
* \file initialise.c
* \brief Fichier où se touvent les fonctions d'initialisation des matrices, des structures joueur et pièces
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"../Include/P4.h"


/**
* \fn void initialiser_matrice(case_t mat[L][C])
* \brief Remplie toute la matrice a nulle
* \param mat[L][C] : la matrice où l'on fait les vérifications
*/

void initialiser_matrice(case_t mat[L][C]){
        int i,j; /* i et j sont respectivement la ligne i et la colonne j */
        for(i=0;i<L;i++){
                for(j=0;j<C;j++){
                        mat[i][j].piece1 = malloc(sizeof(piece_t));
                        mat[i][j].piece2 = malloc(sizeof(piece_t));
                        mat[i][j].piece1->type=0;
                        mat[i][j].piece2->type=0;
                        mat[i][j].piece1->couleur='/';
                        mat[i][j].piece2->couleur='/';
                }
        }
}


/**
* \fn void creer_joueur(joueur_t * joueur,int bloquante)
* \brief Creer un joueur avec comme choix le pseudo et la couleur
* \param * joueurs : 
* \param bloquante : le nombre de pièces bloquantes que l'on donnera aux joueurs
*/

void creer_joueur(joueur_t * joueur,int bloquante){
  joueur->pseudo=malloc(sizeof(char *));  
  printf("\n Saisir le pseudo du joueur : ");
  scanf("%s",joueur->pseudo);
  printf("\n Saisir l'initiale de la couleur que vous voulez : ");
  scanf("%s",&joueur->couleur);
  joueur->nb_bloq=bloquante;
}


/**
* \fn int choix_piece_bloquante(void)
* \brief Renvoi le nombre de piece bloquante pour tous les joueurs
*/

int choix_piece_bloquante(void){
  int nb;
  printf("Saisir le nombre de pièce bloquante pour tous les joueurs : ");
  scanf("%d",&nb);
  return nb;
}


/**
* \fn int hauteur_piece(int j, case_t mat[L][C], int type_piece)
* \brief  Permet d'initialiser un joueur
* \param nb_joueur : la taile du tableau
* \param tab[] : tableau dans lequel les informations des joueurs seront enregistrées
*/
void initialiser_joueur(int nb_joueur, joueur_t tab[]){ 
	int i;
	int nb_bloquante ;
        nb_bloquante = choix_piece_bloquante();
	for(i=0;i<nb_joueur;i++){
	        creer_joueur(&(tab[i]), nb_bloquante);
                printf("\n %s %c %d \n",tab[i].pseudo ,tab[i].couleur, tab[i].nb_bloq );
	}
}
