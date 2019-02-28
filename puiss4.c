#include <stdio.h>
#include<stdlib.h>

#define L 6
#define C 7

int hauteur_pion(int y, int mat[L][C]){ // on calcule la hauteur du pion s'il y en a deja en dessous
        int x=5;
        while(mat[x][y]!=0){
                x--;
        }
        return x;
}

void initialiser_matrice(int mat[L][C]){ // on met la matrice  a  0
        int i,j;
        for(i=0;i<L;i++){
                for (j= 0;j<C;j++){
                        mat[i][j]=0;
                }
        }
}

void afficher_matrice(int mat[L][C]){ // fonction qui affiche la matrice selon les valeurs
        int i,j;
        for(i=0;i<L;i++){
                for (j= 0;j<C;j++){
                        if(mat[i][j]==0){
                                printf("   |");
                        }
                        else if(mat[i][j]==1){ //on affiche J(jaune) pour le joueur 1 et R(rouge) pour le joueur 2
                                printf(" J |");
                        }
                                else{
                                        printf(" R |");
                                }
                }
                printf("\n");
        }
}

void tour_joueur(int joueur, int mat[L][C]){ //fonction qui place le pion dans la grille
        int x,y;
        do{
                printf("Inscrivez la coordonnee X du pion (entre 1 et 7) : ");
                scanf("%d",&y);
                //va permettre de savoir la hauteur du pion
                x = hauteur_pion(y-1,mat);
                if(x<0){
                        printf("Colonne deja remplie ! \n");
                }
        }while(y<1 || y>7 || x<0);
        y--;
        if(joueur == 1){
                mat[x][y]=1;
                printf("le joueur 1 a mis son pion en %d %d \n",y+1, 5-x);
        }
        else{
                mat[x][y]=2;
                printf("le joueur 2 a mis son pion en %d %d \n",y+1, 5-x);
        }
        afficher_matrice(mat);
}

int gagne(int joueur, int mat[L][C]){ //fonction qui regarde si 4 pionts sont aligne horizontalement ou verticalement
        int i,j;

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

int main(){ //initialisation des entier, cahine de caractÃ¨res et fichier

        int mat[L][C], nb_jeton=42;
        initialiser_matrice(mat);
        //on fait chaque tour de jeu tant qu'il a les pions
        while(nb_jeton>0){
                printf("c'est au joueur 1 de jouer ! \n");
                tour_joueur(1,mat);
                //vÃ©rifie s'il gagne
                if(gagne(1, mat)){
                        printf("Le joueur 1 a gagné ! \n");
                        break;
                }
                printf("c'est au joueur 2 de jouer ! \n");
                tour_joueur(2,mat);
                if(gagne(2, mat)){
                        printf("Le joueur 2 a gagné ! \n");
                        break;
                }
                nb_jeton-=2;
        }
        if(nb_jeton == 0){
                printf("Match nul ! \n");
        }
}