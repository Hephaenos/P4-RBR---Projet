#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"../Include/P4.h"


#define L 6
#define C 7
#define BLOQUANTE  1
#define PLEINE 2
#define CREUSE 3

 // Permet de savoir à quelle hauteur arrive la pièce dans la colonne choisit
int hauteur_piece(int j, case_t mat[L][C], int type_piece){
        int i=L-1;
        if(type_piece==BLOQUANTE){
          while(mat[i][j].piece1!=NULL && mat[i][j].piece2!=NULL){
                i--;
          }
          return i;
        }
        else if(type_piece==PLEINE){
          while(mat[i][j].piece1->type!=BLOQUANTE && mat[i][j].piece1->type!=PLEINE){
                i--;
          }
          return i;
        }
        else{
          while(mat[i][j].piece1->type!=BLOQUANTE && mat[i][j].piece2->type!=CREUSE){
                i--;
          }
          return i;
        }
}
