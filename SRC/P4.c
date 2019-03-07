#include <stdio.h>
#include<stdlib.h>
#include"../Include/P4.h"
#include"../Include/afficher_matrice.h"
#include"../Include/gagne.h"
#include"../Include/hauteur_piece.h"
#include"../Include/initialise.h"
#include"../Include/tour_joueur.h"


#define L 6
#define C 7
#define BLOQUANTE  1
#define PLEINE 2
#define CREUSE 3


int main(){ //initialisation des entier, cahine de caractÃ¨res et fichier
        fprintf(stderr,"1");
        case_t mat[L][C];
        fprintf(stderr,"1");
        int nb_joueur,joueur, nb_jeton = 42;
        initialiser_matrice(mat);
        fprintf(stderr,"1");
        do{
                printf("Inscrire le nombre de joueur (entre 1 et 6) : ");
                scanf("%d",&nb_joueur);     
        }while(nb_joueur<1 || nb_joueur>6);
        joueur_t tab[nb_joueur];
        initialiser_joueur(nb_joueur,tab);
        //on fait chaque tour de jeu tant qu'il a les pions
        while(nb_jeton>0){
                for(joueur = 0 ;!(gagne(tab[joueur-1],mat)); (joueur++)%nb_joueur){
                        printf("C'est à %s de joueur !", tab[joueur].pseudo);
                        tour_joueur(tab[joueur],mat);                       
                }
                nb_jeton-=nb_joueur;
        } //tous les pions sont dÃ©pensÃ©s donc match nul
        if(nb_jeton == 0){
                printf("Match nul ! \n");
        }
        else{
                printf("C'est %s qui a gagné ! ", tab[joueur-1].pseudo);
        }
        free(mat);
        return 0;
}
