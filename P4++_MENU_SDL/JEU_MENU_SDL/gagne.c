/**
* \file gagne.c
* \brief C'est la fonction avec laquelle on vérifie si un joueur à gagné ou pas
*/
#include "SDL_jeu.h"
/**
* \fn int gagne(joueur_t * joueur, case_t mat[L][C])
* \brief fonction qui vérifie si 4 pièces sont alignées
* \param * joueur : un pointeur sur une structure joueur qui représente le joueur qui joue
* \param mat[L][C] : la matrice dans laquelle on vérifie si les 4 pièces sont alignées
*/

int gagne(joueur_t * joueur, case_t mat[L][C]){
        int i,j;  /* i et j étant les lignes et les colonnes de notre matrice */
       
        for(i=L-1;i>(L/2);i--){   /* on regarde verticalement */
                for(j=0;j<C;j++){
                        if(mat[i][j].piece1->couleur == joueur->couleur || mat[i][j].piece2->couleur == joueur->couleur){
                                if(mat[i-1][j].piece1->couleur  == joueur->couleur || mat[i-1][j].piece2->couleur == joueur->couleur){
                                        if(mat[i-2][j].piece1->couleur == joueur->couleur || mat[i-2][j].piece2->couleur == joueur->couleur){
                                            if(mat[i-3][j].piece1->couleur == joueur->couleur || mat[i-3][j].piece2->couleur == joueur->couleur){
                                                    return 1;
                                            }  
                                        }
                                }
                        } 
                }
        }

        for(i=L-1;i>0;i--){                                                                                       /* on regarde horizontalement */
                for(j=0;j<=((C/2));j++){
                        if(mat[i][j].piece1->couleur == joueur->couleur || mat[i][j].piece2->couleur == joueur->couleur){
                                if(mat[i][j+1].piece1->couleur  == joueur->couleur || mat[i][j+1].piece2->couleur == joueur->couleur){
                                        if(mat[i][j+2].piece1->couleur == joueur->couleur || mat[i][j+2].piece2->couleur == joueur->couleur){
                                            if(mat[i][j+3].piece1->couleur == joueur->couleur || mat[i][j+3].piece2->couleur == joueur->couleur){
                                                    return 1;
                                            }  
                                        }
                                }
                        } 
                }
        }

        for(i=L-1;i>(L/2);i--){                                                                                   /* on teste en diagonale de gauche a droite du bas vers le haut */
                for(j=0;j<=(C/2);j++){
                        if(mat[i][j].piece1->couleur == joueur->couleur || mat[i][j].piece2->couleur == joueur->couleur){
                                if(mat[i-1][j+1].piece1->couleur  == joueur->couleur || mat[i-1][j+1].piece2->couleur == joueur->couleur){
                                        if(mat[i-2][j+2].piece1->couleur == joueur->couleur || mat[i-2][j+2].piece2->couleur == joueur->couleur){
                                            if(mat[i-3][j+3].piece1->couleur == joueur->couleur || mat[i-3][j+3].piece2->couleur == joueur->couleur){
                                                    return 1;
                                            }  
                                        }
                                }
                        } 
                }
        }

        for(i=L-1;i>(L/2);i--){                                                                                   /* on teste en diagonale de droite a gauche du bas vers le haut */
                for(j=C-1;j>=(C/2);j--){
                        if(mat[i][j].piece1->couleur == joueur->couleur || mat[i][j].piece2->couleur == joueur->couleur){
                                if(mat[i-1][j-1].piece1->couleur  == joueur->couleur || mat[i-1][j-1].piece2->couleur == joueur->couleur){
                                        if(mat[i-2][j-2].piece1->couleur == joueur->couleur || mat[i-2][j-2].piece2->couleur == joueur->couleur){
                                            if(mat[i-3][j-3].piece1->couleur == joueur->couleur || mat[i-3][j-3].piece2->couleur == joueur->couleur){
                                                    return 1;
                                            }  
                                        }
                                }
                        } 
                }
        }
        
        return 0;
}
