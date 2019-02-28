#include <stdio.h>
#include<stdlib.h>
#include"afficher_matrice.h"
#include"hauteur_piece.h"
#include"initialiser_matrice.h"
#include"tour_joueur.h"

#define L 6
#define C 7

int gagne(int joueur, int mat[L][C]){ //fonction qui regarde si 4 pionts sont aligne horizontalement ou verticalement
        int i,j;
        for(i=0;i<(L/2);i++){ //on regarde verticalement
                for(j=0;j<C;j++){
                        if(mat[i][j]==joueur && mat[i+1][j]==joueur && mat[i+2][j]==joueur && mat[i+3][j]==joueur){
                                return 1;
                        }
                }
        }
        for(i=0;i<L;i++){//on regarde horizontalement
                for(j=0;j<((C/2)+1);j++){
                        if(mat[i][j]==joueur && mat[i][j+1]==joueur && mat[i][j+2]==joueur && mat[i][j+3]==joueur){
                                return 1;
                        }
                }
        }
        return 0;
}

int main(){ //initialisation des entier, cahine de caractÃ¨res et fichier
        int mat[L][C], nb_jeton=42;
        initialiser_matrice(mat);
        //on fait chaque tour de jeu tant qu'il a les pions
        while(nb_jeton>0){
                printf("C'est au joueur 1 de jouer ! \n");
                tour_joueur(1,mat);
                //vÃ©rifie s'il gagne
                if(gagne(1, mat)){
                        printf("Le joueur 1 gagne ! \n");
                        break;
                }
                printf("c'est au joueur 2 de jouer ! \n");
                tour_joueur(2,mat);
                if(gagne(2, mat)){
                        printf("Le joueur 2 gagne ! \n");
                        break;
                }
                nb_jeton-=2;
        } //tous les pions sont dÃ©pensÃ©s donc match nul
        if(nb_jeton == 0){
                printf("Match nul ! \n");
        }
}
