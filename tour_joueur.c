#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "afficher_matrice.h"
#include "hauteur_piece.h"

#define L 6
#define C 7

 // Permet de choisir au joueur de placer sa pièce dans la colonne choisit
void tour_joueur(int joueur, int mat[L][C]){
        int i,j; // i et j sont respectivement la ligne i et la colonne j
        do{
                printf("Choisir la colonne où vous voulez mettre votre pièce (entre 1 et 7) : ");
                scanf("%d",&j);
                i = hauteur_piece(j-1,mat); //Permet de savoir la hauteur du pion
                if(i<0){
                        printf("Colonne déjà remplie ! \n");
                }
        }while(j<1 || j>7 || i<0);
        j--;

        if(joueur == 1){
                mat[i][j]=1;
                printf("le joueur 1 place son pion en %d %d \n",j+1, 5-i);
        }
        else{
                mat[i][j]=2;
                printf("le joueur 2 place son pion en %d %d \n",j+1, 5-i);
        }
        afficher_matrice(mat);
}
