#include "SDL_jeu.h"


// Remplie toute la matrice a nulle
void initialiser_matrice(case_t mat[L][C]){
        int i,j; // i et j sont respectivement la ligne i et la colonne j
        for(i=0;i<L;i++){
                for(j=0;j<C;j++){
                        mat[i][j].piece1 = malloc(sizeof(piece_t));
                        mat[i][j].piece2 = malloc(sizeof(piece_t));
                        mat[i][j].piece1->type=0;
                        mat[i][j].piece2->type=0;
                        mat[i][j].piece1->couleur='/';
                        mat[i][j].piece2->couleur='/';
                }
        }
}


// Creer un joueur avec comme choix le pseudo, la couleur et le nombre
// de pièce bloquante définie en parmaètre
void creer_joueur(joueur_t * joueur,int bloquante){
  joueur->pseudo=malloc(sizeof(char *));  
  printf("\n Saisir le pseudo du joueur : ");
  scanf("%s",joueur->pseudo);
  printf("\n Saisir l'initiale de la couleur que vous voulez : ");
  scanf("%s",&joueur->couleur);
  joueur->nb_bloq=bloquante;
}

// Renvoi le nombre de piece bloquante pour tous les joueurs
int choix_piece_bloquante(void){
  int nb;
  printf("Saisir le nombre de pièce bloquante pour tous les joueurs : ");
  scanf("%d",&nb);
  return nb;
}

void initialiser_joueur(int nb_joueur, joueur_t tab[]){ 
	int i;
	int nb_bloquante ;
        nb_bloquante = choix_piece_bloquante();
	for(i=0;i<nb_joueur;i++){
	        creer_joueur(&(tab[i]), nb_bloquante);
                printf("\n %s %c %d \n",tab[i].pseudo ,tab[i].couleur, tab[i].nb_bloq );
	}
}