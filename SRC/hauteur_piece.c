/**
* \file hauteur_piece.c
* \brief Fonction qui permet de voir si la colonne est remplie ou non
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"../Include/P4.h"


#define L 6
#define C 7
#define BLOQUANTE  1
#define PLEINE 2
#define CREUSE 3

/**
* \fn int hauteur_piece(int j, case_t mat[L][C], int type_piece)
* \brief  Permet de savoir à quelle hauteur arrive la pièce dans la colonne choisit
* \param mat[L][C] : la matrice où l'on fait les vérifications
* \param type_piece : le type de la pièce à mettre dans la matrice
*/

int hauteur_piece(int j, case_t mat[L][C], int type_piece){
        int i=L-1;
        if(type_piece==BLOQUANTE){
          while(i>=0 && (mat[i][j].piece1->type!=0 || mat[i][j].piece2->type!=0)){
                i--;
          }
          return i;
        }
        else if(type_piece==PLEINE){
          while(i>=0 && (mat[i][j].piece1->type==BLOQUANTE || mat[i][j].piece1->type==PLEINE)){
                i--;
          }
          return i;
        }
        else{
          while(i>=0 && (mat[i][j].piece1->type==BLOQUANTE || mat[i][j].piece2->type==CREUSE)){
                i--;
          }
          return i;
        }
}
