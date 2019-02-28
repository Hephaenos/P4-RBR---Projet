#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define L 6
#define C 7

// Fonction qui affiche une matrice
void afficher_matrice(int mat[L][C]){
        int i,j; // i et j sont respectivement la ligne i et la colonne j
        for(i=0;i<L;i++){
                for (j= 0;j<C;j++){
                        if(mat[i][j]==0){
                                printf("   |");
                        }
                        else if(mat[i][j]==1){ // Affichage pièce joueur 1
                                printf(" * |");
                        }
                                else{ // Affichage pièce joueur 2
                                        printf(" 0 |");
                                }
                }
                printf("\n");
        }
}
