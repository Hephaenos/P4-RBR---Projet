/**
* \file sdl_couleur.c
* \brief Fichier permettant aux joueurs de choisir leur couleur de pièce pour la partie
*/

#include "SDL_jeu.h"

void flo_suivant2(char * coul){
    printf("%s \n\n", coul);
}

/**
* \fn int flo_test_couleur(int reste_joueur, joueur_t tab[], int nb_bloquante, int place_joueur)
* \brief  Permet au  joueur de choisir la couleur qui lui sera attribué
* \param int reste_joueur : permet de savoir combien de joueur il reste
* \param joueur_t tab[] : permet de mettre les information que le joueur va sélectionner
* \param int nb_bloquante : permet de savoir combien le joueur aura de pièce bloquante
* \param int place_joueur : indice pour le tableau tab
*/

int flo_test_couleur(int reste_joueur, joueur_t tab[], int nb_bloquante, int place_joueur){
    printf("Il reste %d joueur \n", reste_joueur);
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    } 

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
    int x,y;
    /* Le pointeur vers la fenetre */
    SDL_Window* pWindow = NULL;
    /* Le pointeur vers la surface incluse dans la fenetre */
    SDL_Renderer *renderer=NULL;
    SDL_Rect txtDestRect,txtMenuRect[4], imgBtnRect, imgBGRect, txt_titre, nbjoueurRect[6];


    /* Une variable de couleur noire */
    SDL_Color couleurNoire = {0, 0, 0, 0};
    SDL_Color couleurBlanc = {255, 255, 255, 255};

    /* Création de la fenêtre */
    pWindow = SDL_CreateWindow("Puissance 4++",SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               800,
                               571,
                               SDL_WINDOW_SHOWN);
    
    if(!pWindow){
        fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        fprintf(stderr, "Erreur à la création du renderer\n");
        exit(EXIT_FAILURE);
    }

    SDL_Texture *texte_tex = tex_text("ChowFun.ttf",80,"Puissance 4",couleurBlanc,renderer);
    SDL_Texture *texteMenu_tex[2], *nbjoueurtext[6];

    char * couleur[6] = {"Vert","Rouge","Bleu","Orange","Gris","Jaune"};
    
    texteMenu_tex[0] = tex_text("ChowFun.ttf",20,"Choix du couleur de joueur : ",couleurNoire,renderer);
    texteMenu_tex[1] = tex_text("ChowFun.ttf",20,"Quitter",couleurBlanc,renderer);
    nbjoueurtext[0] = tex_text("ChowFun.ttf",30,couleur[0],couleurNoire,renderer);
    nbjoueurtext[1] = tex_text("ChowFun.ttf",30,couleur[1],couleurNoire,renderer);
    nbjoueurtext[2] = tex_text("ChowFun.ttf",30,couleur[2],couleurNoire,renderer);
    nbjoueurtext[3] = tex_text("ChowFun.ttf",30,couleur[3],couleurNoire,renderer);
    nbjoueurtext[4] = tex_text("ChowFun.ttf",30,couleur[4],couleurNoire,renderer);
    nbjoueurtext[5] = tex_text("ChowFun.ttf",30,couleur[5],couleurNoire,renderer);
    
    txtDestRect.x = 200;
    txtDestRect.y = 10;
    SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

    SDL_Texture *image_BG_tex = tex_img_png("Puissance4BG.png",renderer);
    /* Chargement de l'image bouton */
    SDL_Texture *image_btn_tex = tex_img_png("button2.png",renderer);

    if( pWindow )
    {
        int running = 1, i;
        while(running) {
            SDL_Event e;
            SDL_GetMouseState(&x,&y);
            SDL_StartTextInput();

            while(SDL_PollEvent(&e)) {
                switch(e.type) {
                    case SDL_QUIT: running = 0;break;
                    case SDL_MOUSEBUTTONDOWN:
                        
                    case SDL_WINDOWEVENT:
                        /* Le fond de la fenêtre sera blanc */
                        SDL_RenderClear(renderer);
                        
                        /* BACKGROUND */
                        imgBGRect.x = 0;
                        imgBGRect.y = 0;
                        
                        SDL_QueryTexture(image_BG_tex, NULL, NULL, &(imgBGRect.w), &(imgBGRect.h));

                        SDL_RenderCopy(renderer, image_BG_tex, NULL, &imgBGRect);
                        
                        /* Ajout du texte en noir */
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                        
                        
                        
                        
                        /* Positionnement du premier bouton */
                        imgBtnRect.x = 590;
                        imgBtnRect.y = 430;
                        txtMenuRect[0].x=258;
                        txtMenuRect[0].y=208;
                        txtMenuRect[1].x=610;
                        txtMenuRect[1].y=440;
                        SDL_QueryTexture(image_btn_tex, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
                        if(x<700 && 590<x && y<imgBtnRect.y+55 && imgBtnRect.y<y){
                            if(e.type == SDL_MOUSEBUTTONDOWN){

                                SDL_DestroyWindow(pWindow);
                                return 0;
                            }
                        }
                        nbjoueurRect[0].x=40;
                        nbjoueurRect[0].y=260;
                        SDL_QueryTexture(nbjoueurtext[0], NULL, NULL, &(nbjoueurRect[0].w), &(nbjoueurRect[0].h));
                        SDL_RenderCopy(renderer, nbjoueurtext[0], NULL, &(nbjoueurRect[0]));
                        for(i=1;i<7;i++){
                            if(x<(nbjoueurRect[i-1].x + 120) && (nbjoueurRect[i-1].x)<x && y<(nbjoueurRect[i-1].y + 30) && nbjoueurRect[i-1].y<y){
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    SDL_DestroyWindow(pWindow);
                                    tab[place_joueur].couleur=couleur[i-1][0];
                                    if(reste_joueur==0){
                                        return 0;
                                    }
                                    flo_suivant2(couleur[i-1]);
                                    flo_test_pseudo(--reste_joueur,tab,nb_bloquante,++place_joueur);
                                    return 0;
                                }
                            }
                            nbjoueurRect[i].x = nbjoueurRect[0].x + (i%3)*160;
                            if(i>2){
                                nbjoueurRect[i].y= 360;
                            }
                            else{
                                nbjoueurRect[i].y= 260;
                            }
                            SDL_QueryTexture(nbjoueurtext[i], NULL, NULL, &(nbjoueurRect[i].w), &(nbjoueurRect[i].h));
                            SDL_RenderCopy(renderer, nbjoueurtext[i], NULL, &(nbjoueurRect[i]));
                        }
                        txt_titre.x = 170;
                        txt_titre.y = 10;
                        SDL_QueryTexture(texte_tex, NULL, NULL, &(txt_titre.w), &(txt_titre.h));
                        SDL_RenderCopy(renderer, texte_tex, NULL, &(txt_titre));

                        SDL_RenderCopy(renderer, image_btn_tex, NULL, &imgBtnRect);
                        SDL_QueryTexture(texteMenu_tex[0], NULL, NULL, &(txtMenuRect[0].w), &(txtMenuRect[0].h));
                        SDL_RenderCopy(renderer, texteMenu_tex[0], NULL, &(txtMenuRect[0]));
                        SDL_QueryTexture(texteMenu_tex[1], NULL, NULL, &(txtMenuRect[1].w), &(txtMenuRect[1].h));
                        SDL_RenderCopy(renderer, texteMenu_tex[1], NULL, &(txtMenuRect[1]));
                        /* On fait le rendu */
                    SDL_RenderPresent(renderer);
                    break;
                }
            }
        }
    } else {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
    }
    /* Destruction de la fenetre */
    if(pWindow != NULL) SDL_DestroyWindow(pWindow);
    return 0;
}


