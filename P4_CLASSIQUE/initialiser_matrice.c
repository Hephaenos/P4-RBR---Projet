#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define L 6
#define C 7

// Remplie toute la matrice avec des 0
void initialiser_matrice(int mat[L][C]){
        int i,j; // i et j sont respectivement la ligne i et la colonne j
        for(i=0;i<L;i++){
                for (j= 0;j<C;j++){
                        mat[i][j]=0;
                }
        }
}
