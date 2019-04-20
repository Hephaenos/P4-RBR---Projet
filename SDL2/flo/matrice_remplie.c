/** 
* \file matrice_remplie.c
* \brief Cette fonction va permettre de savoir si la matrice est remplie pour savoir s'il y a égalité
*/

#include "SDL_jeu.h"



int mat_remplie(case_t mat[L][C]){
    /* permet de savoir le nombre de colonne remplie*/
    int nb_colonne_remplie = 0;
    int j;
    for(j=0;j<C;j++){
        if(mat[L][j].piece1->type==1){ /* si c'est une pièce bloquante alors la colonne est remplie */
            nb_colonne_remplie++;
        }
        else if(mat[L][j].piece1->type==2 && mat[L][j].piece2->type==3){ /* S'il y a une piece pleine et creuse alors la colonn est remplie */
            nb_colonne_remplie++;
        }
    }
    if(nb_colonne_remplie==7){ /* Si toutes les colonnes sont remplies on retourne 1 */
        return 1;
    }
    return 0;
}
