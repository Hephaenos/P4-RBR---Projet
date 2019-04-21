/**
* \file P4.c
* \brief Notre main
*/

#include <stdio.h>
#include<stdlib.h>
#include"../Include/P4.h"
#include"../Include/afficher_matrice.h"
#include"../Include/gagne.h"
#include"../Include/hauteur_piece.h"
#include"../Include/initialise.h"
#include"../Include/tour_joueur.h"





int main(){ /* initialisation des entier, cahine de caractÃ¨res et fichier */
        case_t mat[L][C];
        int nb_joueur,joueur, nb_jeton = 42,i,j;
        initialiser_matrice(mat);
        do{
                printf("Inscrire le nombre de joueur (entre 1 et 6) : ");
                scanf("%d",&nb_joueur);     
        }while(nb_joueur<1 || nb_joueur>6);
        joueur_t tab[nb_joueur];
        initialiser_joueur(nb_joueur,tab);
        afficher_matrice(mat);


        /* on fait chaque tour de jeu tant qu'il a les pions */
                for(joueur = 0 ;nb_jeton>0; joueur++, nb_jeton--){
                        joueur=joueur%nb_joueur;
                        printf("C'est à %s de joueur !", tab[joueur].pseudo);
                        tour_joueur(&tab[joueur],mat);
                        if((gagne(&tab[(joueur%nb_joueur)],mat)))
                                break;          
                }
                nb_jeton-=nb_joueur;
         /* tous les pions sont dÃ©pensÃ©s donc match nul */
        if(nb_jeton == 0){
                printf("Match nul ! \n");
        }
        else{
                printf("C'est %s qui a gagné ! \n", tab[joueur].pseudo);
        }
        
        for(i=0;i<L;i++){
                for(j=0;j<C;j++){
                        free(mat[i][j].piece1);
                        free(mat[i][j].piece2);
                }
        }
        
        return 0;
}
