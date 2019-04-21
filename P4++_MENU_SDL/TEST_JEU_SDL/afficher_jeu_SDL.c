/**
 * \file afficher_jeuSDL.c
 * \brief Regroupe les fonctions pour la mise en place du jeu dans un environnement graphique.
 * \author Mario Hotaj
 * \date 4 mars 2019
 */

#include "SDL_jeu.h"
#define EGALITE 'E'

static SDL_Texture *image_caseNorm_tex;
static SDL_Texture *image_casePoss_tex;
static SDL_Texture *image_noir_tex;
static SDL_Texture *image_blanc_tex;
static SDL_Texture *image_cible_tex;
static SDL_Rect imgBtnRect;
static SDL_Renderer *renderer_temp;

/**
 * \fn void init_jeuSDL(SDL_Renderer* renderer)
 * \brief Initialise tout les données nécessaire pour l'affichage du plateau
 * \param SDL_Renderer* renderer : renderer de la page.
 * \return void
 */
void init_jeuSDL(SDL_Renderer* renderer){
    image_caseNorm_tex = tex_img_png("./img/caseNorm.png",renderer);
    image_casePoss_tex = tex_img_png("./img/casePoss.png",renderer);
    //PION NOIR
    image_noir_tex = tex_img_png("./img/noir.png",renderer);
    //PION BLANC
    image_blanc_tex = tex_img_png("./img/blanc.png",renderer);
    image_cible_tex = tex_img_png("./img/cible.png",renderer);
    //POSITION ET TAILLE CASE
    imgBtnRect.x = 0;
    imgBtnRect.y = 0;
    SDL_QueryTexture(image_caseNorm_tex, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
    //
    renderer_temp=renderer;
}

/**
 * \fn afficher_matriceSDL(int* joueur)
 * \brief Affiche le plateau de jeu avec les pions et affiche les coup possible en fonctions du tour du joueur
 * \param int* joueur : renderer de la page.
 * \return void
 */
void afficher_matriceSDL(char joueur){
    SDL_Texture *temp;
    int i=0,j=0;

    for(i=0;i<N;i++){
        imgBtnRect.y = i*82;
        imgBtnRect.x = 0;
        for(j=0;j<N;j++){
            if(coup_valide(mat,i,j,joueur)){
                temp = image_casePoss_tex;
            }else{
                temp = image_caseNorm_tex;
            }
            SDL_RenderCopy(renderer_temp, temp, NULL, &imgBtnRect);
            if(mat[i][j] == NOIR){
                SDL_RenderCopy(renderer_temp, image_noir_tex, NULL, &imgBtnRect);
            }
            else if(mat[i][j] == BLANC){
                SDL_RenderCopy(renderer_temp, image_blanc_tex, NULL, &imgBtnRect);
            }
            imgBtnRect.x += 82;
        }
    }
}

/**
 * \fn afficher_matriceSDL(int* joueur)
 * \brief La fonction permet de savoir si le jeu est terminé ou non.
 * \param void
 * \return entier
 */
int partie_termineeSDL(void){
        int i, j, nb_noir, nb_blanc, cpt;

    /* On compte les pions noirs et les blancs */
    nb_noir = 0;
    nb_blanc = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (mat[i][j] == VIDE && ((peut_jouer(mat, NOIR) || peut_jouer(mat, BLANC)))) {
                return 0; /* La partie n'est pas finie */
            } else {
                if (mat[i][j] == NOIR) nb_noir++;
                else if (mat[i][j] == BLANC) nb_blanc++;
            }
        }
    }

    /* Rangement des pions par couleur et affichage de la grille */
    cpt = 0;
    for (i=0; i<N; i++){
        imgBtnRect.y = i*82;
        imgBtnRect.x = 0;
        for (j=0; j<N; j++) {
            SDL_RenderCopy(renderer_temp, image_caseNorm_tex, NULL, &imgBtnRect);
            if (cpt < nb_noir)
                SDL_RenderCopy(renderer_temp, image_noir_tex, NULL, &imgBtnRect);
            else if ((cpt >= nb_noir) && (cpt < nb_noir + nb_blanc))
                SDL_RenderCopy(renderer_temp, image_blanc_tex, NULL, &imgBtnRect);
            cpt++;
            imgBtnRect.x += 82;
        }
    }
    return 1;
}

/**
 * \fn afficher_matriceSDL(int* joueur)
 * \brief La fonction permet de savoir qui a gagné, et aussi si on a match nul.
 * \param void
 * \return char soit NOIR, BLANC ou EGALITE qui sont des constantes contenant un caractère.
 */
char afficher_gagnant(void){
    int nb_noir, nb_blanc;
    calculer_score(mat,&nb_noir,&nb_blanc);
    /* Fin de partie, on affiche le gagnant */
    if (nb_noir > nb_blanc) return NOIR;
    else if (nb_blanc > nb_noir) return BLANC;
    else return EGALITE;
};

void afficher_cibleSDL(int x,int y){
    SDL_Texture *temp;
    int i=0,j=0;

    for(i=0;i<N;i++){
        imgBtnRect.y = i*82;
        imgBtnRect.x = 0;
        for(j=0;j<N;j++){
            if(i==x && j==y){
                temp = image_cible_tex;
            }else{
                temp = image_caseNorm_tex;
            }
            SDL_RenderCopy(renderer_temp, temp, NULL, &imgBtnRect);
            if(mat[i][j] == NOIR){
                SDL_RenderCopy(renderer_temp, image_noir_tex, NULL, &imgBtnRect);
            }
            else if(mat[i][j] == BLANC){
                SDL_RenderCopy(renderer_temp, image_blanc_tex, NULL, &imgBtnRect);
            }
            imgBtnRect.x += 82;
        }
    }
    SDL_RenderPresent(renderer_temp);
    sleep(1);
}
