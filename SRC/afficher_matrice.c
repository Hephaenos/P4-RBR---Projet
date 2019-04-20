/**
* \file afficher_matrice.c
* \brief Fonction qui permet d'afficher une matrice
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"../Include/P4.h"

/**
* \fn void afficher_matrice(case_t mat[L][C])
* \brief Affiche la matrice
* \param mat[L][C] : la matrice à afficher
*/
// Fonction qui affiche une matrice
void afficher_matrice(case_t mat[L][C]){
        int i,j; /* i et j sont respectivement la ligne i et la colonne j */
        for(i=0;i<L;i++){
                for (j= 0;j<C;j++){
                        if(mat[i][j].piece1==NULL && (mat[i][j]).piece2==NULL){
                          printf("      |");
                        }
                        else if((mat[i][j]).piece1!=NULL && mat[i][j].piece2==NULL){ /* Affichage pièce joueur 1 */
                            printf("%d %c   |", mat[i][j].piece1->type, mat[i][j].piece1->couleur);

                        }
                        else if(mat[i][j].piece1==NULL && mat[i][j].piece2!=NULL){
                            printf("    %d %c|", mat[i][j].piece2->type, mat[i][j].piece2->couleur);

                        }

                        else{
                            printf("%d %c   %d %c|", mat[i][j].piece1->type, mat[i][j].piece1->couleur, mat[i][j].piece2->type, mat[i][j].piece2->couleur);

                        }
                }
                printf("\n");
        }
}
