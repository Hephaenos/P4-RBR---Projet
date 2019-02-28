#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define L 6
#define C 7

 // Permet de savoir à quel hauteur arrive la pièce dans la colonne choisit
int hauteur_piece(int y, int mat[L][C]){
        int x=5;
        while(mat[x][y]!=0){
                x--;
        }
        return x;
}
