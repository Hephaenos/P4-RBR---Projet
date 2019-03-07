#include <stdio.h>
#include<stdlib.h>

#define L 6
#define C 7

// fonction qui regarde si 4 pièces sont alignés
int gagne(int joueur, int mat[L][C]){
        int i,j;                                                                                                // i et j étant les lignes et les colonnes de notre matrice

        for(i=L;i>(L/2);i--){                                                                                   //on regarde verticalement
                for(j=0;j<C;j++){
                        if(mat[i][j] == joueur && mat[i-1][j] == joueur && mat[i-2][j] == joueur && mat[i-3][j] == joueur){
                                return 1;
                        }
                }
        }

        for(i=L;i>0;i--){                                                                                       //on regarde horizontalement
                for(j=0;j<=((C/2));j++){
                        if(mat[i][j] == joueur && mat[i][j+1] == joueur && mat[i][j+2] == joueur && mat[i][j+3] == joueur){
                                return 1;
                        }
                }
        }

        for(i=L;i>(L/2);i--){                                                                                   // on teste en diagonale de gauche a droite du bas vers le haut
                for(j=0;j<=(C/2);j++){
                        if(mat[i][j] == joueur && mat[i-1][j+1] == joueur && mat[i-2][j+2] == joueur && mat[i-3][j+3] == joueur){
                                return 1;
                        }
                }
        }

        for(i=L;i>(L/2);i--){                                                                                   // on teste en diagonale de droite a gauche du bas vers le haut
                for(j=C;j>=(C/2);j--){
                        if(mat[i][j] == joueur && mat[i-1][j-1] == joueur && mat[i-2][j-2] == joueur && mat[i-3][j-3] == joueur){
                                return 1;
                        }
                }
        }

        return 0;
}