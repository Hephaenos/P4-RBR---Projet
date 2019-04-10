#include "SDL_jeu.h"


void lancement_jeu3(int i){
    printf("nombre recu i = %d \n \n", i);
}

int choix_nbBloq(void){
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
    //Le pointeur vers la fenetre
    SDL_Window* pWindow = NULL;
    //Le pointeur vers la surface incluse dans la fenetre
    SDL_Renderer *renderer=NULL;
    SDL_Rect txtDestRect,txtMenuRect[4], imgBtnRect, imgBGRect, txt_titre, nbPieceBloRect[11];


    // Une variable de couleur noire
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
    SDL_Texture *texteMenu_tex[2], *nbPieceBlotext[11];
    
    texteMenu_tex[0] = tex_text("ChowFun.ttf",20,"Choix de pièce(s) bloquante(s) : ",couleurNoire,renderer);
    texteMenu_tex[1] = tex_text("ChowFun.ttf",20,"Quitter",couleurBlanc,renderer);
    nbPieceBlotext[0] = tex_text("ChowFun.ttf",40," 0 ",couleurNoire,renderer);
    nbPieceBlotext[1] = tex_text("ChowFun.ttf",40," 1 ",couleurNoire,renderer);
    nbPieceBlotext[2] = tex_text("ChowFun.ttf",40," 2 ",couleurNoire,renderer);
    nbPieceBlotext[3] = tex_text("ChowFun.ttf",40," 3 ",couleurNoire,renderer);
    nbPieceBlotext[4] = tex_text("ChowFun.ttf",40," 4 ",couleurNoire,renderer);
    nbPieceBlotext[5] = tex_text("ChowFun.ttf",40," 5 ",couleurNoire,renderer);
    nbPieceBlotext[6] = tex_text("ChowFun.ttf",40," 6 ",couleurNoire,renderer);
    nbPieceBlotext[7] = tex_text("ChowFun.ttf",40," 7 ",couleurNoire,renderer);
    nbPieceBlotext[8] = tex_text("ChowFun.ttf",40," 8 ",couleurNoire,renderer);
    nbPieceBlotext[9] = tex_text("ChowFun.ttf",40," 9 ",couleurNoire,renderer);
    nbPieceBlotext[10] = tex_text("ChowFun.ttf",40,"Val",couleurNoire,renderer);
    
    txtDestRect.x = 200;
    txtDestRect.y = 10;
    SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

    SDL_Texture *image_BG_tex = tex_img_png("Puissance4BG.png",renderer);
    //Chargement de l'image bouton
    SDL_Texture *image_btn_tex = tex_img_png("button2.png",renderer);

    if( pWindow )
    {
        int running = 1, i, val = -1;
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
                        //SDL_SetRenderDrawColor(renderer, 24, 124, 58, 255);
                        SDL_RenderClear(renderer);
                        
                        //BACKGROUND
                        imgBGRect.x = 0;
                        imgBGRect.y = 0;
                        
                        SDL_QueryTexture(image_BG_tex, NULL, NULL, &(imgBGRect.w), &(imgBGRect.h));

                        SDL_RenderCopy(renderer, image_BG_tex, NULL, &imgBGRect);
                        
                        /* Ajout du texte en noir */
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                        
                        
                        //SDL_RenderDrawLine(renderer,0,130,1080,130);
                        
                        //Positionnement du premier bouton
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
                                lancement_jeu(0);
                                return 0;
                            }
                        }
                        nbPieceBloRect[0].x=180;
                        nbPieceBloRect[0].y=260;
                        SDL_QueryTexture(nbPieceBlotext[0], NULL, NULL, &(nbPieceBloRect[0].w), &(nbPieceBloRect[0].h));
                        SDL_RenderCopy(renderer, nbPieceBlotext[0], NULL, &(nbPieceBloRect[0]));
                        for(i=1;i<12;i++){
                            if(x<(nbPieceBloRect[i-1].x + 40) && (nbPieceBloRect[i-1].x)<x && y<(nbPieceBloRect[i-1].y + 40) && nbPieceBloRect[i-1].y<y){
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    if(val != -1 && (i-1)!= 10){
                                        val = val * 10 + (i-1);
                                    }
                                    else if(val == -1 && (i-1)!= 10) {
                                        val = (i-1);
                                    }
                                    else if((i-1) == 10){
                                        SDL_DestroyWindow(pWindow);
                                        lancement_jeu3(val);
                                        return val;
                                    }
                                }
                            }
                            if(i>5){
                                nbPieceBloRect[i].y= nbPieceBloRect[0].y+100;
                            }
                            else{
                                nbPieceBloRect[i].y= nbPieceBloRect[0].y;
                            }
                            nbPieceBloRect[i].x = nbPieceBloRect[0].x + (i%6)*70;
                            SDL_QueryTexture(nbPieceBlotext[i], NULL, NULL, &(nbPieceBloRect[i].w), &(nbPieceBloRect[i].h));
                            SDL_RenderCopy(renderer, nbPieceBlotext[i], NULL, &(nbPieceBloRect[i]));
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
                        /*
                        imgBtnRect.x = 1000;
                        imgBtnRect.y = 570;
                        if(song==PLAY){
                            temp_music = image_pause_tex;
                            Mix_ResumeMusic();
                        }else{
                            temp_music = image_play_tex;
                            Mix_PauseMusic();
                        }
                        SDL_QueryTexture(temp_music, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
                        SDL_RenderCopy(renderer, temp_music, NULL, &imgBtnRect);*/

                        /* On fait le rendu ! */
                    SDL_RenderPresent(renderer);
                    break;
                }
            }
        }
    } else {
        fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
    }
    //Destruction de la fenetre
    if(pWindow != NULL) SDL_DestroyWindow(pWindow);
    return 0;

}