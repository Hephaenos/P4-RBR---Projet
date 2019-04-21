#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <time.h>

SDL_Texture* tex_img_png(char * s, SDL_Renderer* renderer){

    SDL_RWops *rwop=SDL_RWFromFile(s, "rb");
	SDL_Surface *image=IMG_LoadPNG_RW(rwop);
	if(!image) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	SDL_Texture *image_btn_tex = SDL_CreateTextureFromSurface(renderer, image); 
	if(!image_btn_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
    return image_btn_tex;
}

/**
 * \fn SDL_Texture* tex_img_png(char * s, SDL_Renderer* renderer)
 * \brief Transforme du texte en format texture pour pouvoir l'afficher dans la fenêtre SDL
 * \param font : chemin d'accès vers la police d'écriture.
 * \param size : taille de la police
 * \param s : texte
 * \param color : couleur pour le texte
 * \param renderer : le renderer de la fenêtre.
 * \return Pointeur sur SDL_Texture
 */
SDL_Texture *tex_text(char* font,int size, char* s, SDL_Color color, SDL_Renderer* renderer){
    TTF_Font *policeTitre = NULL;
	if( (policeTitre = TTF_OpenFont(font, size)) == NULL){
        fprintf(stderr, "erreur chargement font : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface *texte = TTF_RenderUTF8_Blended(policeTitre, s, color);
    if(!texte){
        fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);
    if(!texte_tex){
        fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
    TTF_CloseFont(policeTitre); /* Doit être avant TTF_Quit() */
    return texte_tex;
}




void lancement_jeu(int i){
    printf("nombre recu i = %d \n \n", i);
}

int main(void){
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
    SDL_Rect txtDestRect, txtBvnRect, txtMenuRect[4], imgBtnRect, imgBGRect, txt_titre, nbjoueurRect[5];


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
    }age_BG_te

    renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        fprintf(stderr, "Erreur à la création du renderer\n");
        exit(EXIT_FAILURE);
    }

    SDL_Texture *texte_tex = tex_text("ChowFun.ttf",80,"Puissance 4",couleurBlanc,renderer);
<<<<<<< HEAD:SDL2/flo/flo_sdl_jeu.c
    SDL_Texture *texteMenu_tex[2], *nbjoueurtext[5];
    
    texteMenu_tex[0] = tex_text("ChowFun.ttf",20,"Choix du nombre de joueur : ",couleurNoire,renderer);
    texteMenu_tex[1] = tex_text("ChowFun.ttf",20,"Quitter",couleurBlanc,renderer);
    nbjoueurtext[0] = tex_text("ChowFun.ttf",40,"- 2 ",couleurNoire,renderer);
    nbjoueurtext[1] = tex_text("ChowFun.ttf",40,"- 3 ",couleurNoire,renderer);
    nbjoueurtext[2] = tex_text("ChowFun.ttf",40,"- 4 ",couleurNoire,renderer);
    nbjoueurtext[3] = tex_text("ChowFun.ttf",40,"- 5 ",couleurNoire,renderer);
    nbjoueurtext[4] = tex_text("ChowFun.ttf",40,"- 6 ",couleurNoire,renderer);
    
=======
    SDL_Texture *texteMenu_tex[2];

    texteMenu_tex[0] = tex_text("ChowFun.ttf",20,"Jouer",couleurNoire,renderer);
    texteMenu_tex[1] = tex_text("ChowFun.ttf",20,"Quitter",couleurNoire,renderer);

>>>>>>> b15154cd459597595a7999169395693328a65b69:SDL2/SDL_PROG/menu_sdl_jeu.c
    txtDestRect.x = 200;
    txtDestRect.y = 10;
    SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

    SDL_Texture *image_BG_tex = tex_img_png("Puissance4BG.png",renderer);
    //Chargement de l'image bouton
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
                        nbjoueurRect[0].x=70;
                        nbjoueurRect[0].y=260;
                        SDL_QueryTexture(nbjoueurtext[0], NULL, NULL, &(nbjoueurRect[0].w), &(nbjoueurRect[0].h));
                        SDL_RenderCopy(renderer, nbjoueurtext[0], NULL, &(nbjoueurRect[0]));
                        for(i=1;i<6;i++){
                            if(x<(nbjoueurRect[i-1].x + 60) && (nbjoueurRect[i-1].x)<x && y<(nbjoueurRect[i-1].y + 150) && nbjoueurRect[i-1].y<y){
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    SDL_DestroyWindow(pWindow);
                                    lancement_jeu(i+1);
                                    return 0;
                                }
                            }
                            nbjoueurRect[i].x = nbjoueurRect[i-1].x + 150;
                            nbjoueurRect[i].y= 260;
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
<<<<<<< HEAD:SDL2/flo/flo_sdl_jeu.c
=======

>>>>>>> b15154cd459597595a7999169395693328a65b69:SDL2/SDL_PROG/menu_sdl_jeu.c
    //Destruction de la fenetre
    if(pWindow != NULL) SDL_DestroyWindow(pWindow);
    return 0;

}
