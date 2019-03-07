#include <stdio.h>
#include<stdlib.h>
#include"afficher_matrice.h"
#include"hauteur_piece.h"
#include"initialiser_matrice.h"
#include"tour_joueur.h"
#include"gagne.h"

#define L 6
#define C 7

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
