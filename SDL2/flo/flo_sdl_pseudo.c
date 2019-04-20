/**
* \file sdl_pseudo.c
* \brief Fichier permettant aux joueurs de choisir leur pseudonymes durant la partie
*/
#include "SDL_jeu.h"


void flo_suivant(char * pse){
    printf("%s \n\n", pse);
}


int flo_test_pseudo(int reste_joueur, joueur_t tab[], int nb_bloquante, int place_joueur){
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

    char * pseudo[6] = {"Alpha","Delta","Beta","Omega","Epsilon","Champion"};
    
    texteMenu_tex[0] = tex_text("ChowFun.ttf",20,"Choix du Pseudo de joueur : ",couleurNoire,renderer);
    texteMenu_tex[1] = tex_text("ChowFun.ttf",20,"Quitter",couleurBlanc,renderer);
    nbjoueurtext[0] = tex_text("ChowFun.ttf",30,pseudo[0],couleurNoire,renderer);
    nbjoueurtext[1] = tex_text("ChowFun.ttf",30,pseudo[1],couleurNoire,renderer);
    nbjoueurtext[2] = tex_text("ChowFun.ttf",30,pseudo[2],couleurNoire,renderer);
    nbjoueurtext[3] = tex_text("ChowFun.ttf",30,pseudo[3],couleurNoire,renderer);
    nbjoueurtext[4] = tex_text("ChowFun.ttf",30,pseudo[4],couleurNoire,renderer);
    nbjoueurtext[5] = tex_text("ChowFun.ttf",30,pseudo[5],couleurNoire,renderer);
    
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
                                flo_suivant(0);
                                return 0;
                            }
                        }
                        nbjoueurRect[0].x=40;
                        nbjoueurRect[0].y=260;
                        SDL_QueryTexture(nbjoueurtext[0], NULL, NULL, &(nbjoueurRect[0].w), &(nbjoueurRect[0].h));
                        SDL_RenderCopy(renderer, nbjoueurtext[0], NULL, &(nbjoueurRect[0]));
                        for(i=1;i<7;i++){
                            if(x<(nbjoueurRect[i-1].x + 130) && (nbjoueurRect[i-1].x)<x && y<(nbjoueurRect[i-1].y + 40) && nbjoueurRect[i-1].y<y){
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    SDL_DestroyWindow(pWindow);
                                    flo_suivant(pseudo[i-1]);
                                    tab[place_joueur].pseudo=pseudo[i-1];
                                    tab[place_joueur].nb_bloq=nb_bloquante;
                                    flo_test_couleur(reste_joueur,tab,nb_bloquante,place_joueur);
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
