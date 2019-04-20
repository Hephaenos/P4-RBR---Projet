#include "SDL_jeu.h"




int lancement_jeu(int i){
    if(i==0){
       return choix_nbJoueur();
    }
    if(i==1){
        printf("0 \n \n \n");
    }
    return 0;
}


int main(void){
    case_t mat[L][C];
    initialiser_matrice(mat);
    int nb_joueur,nb_bloquante,joueur;
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
    SDL_Rect txtDestRect, txtMenuRect[2], imgBtnRect, imgBGRect, txt_titre;


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
    SDL_Texture *texteMenu_tex[2];
    
    texteMenu_tex[0] = tex_text("ChowFun.ttf",20,"Jouer",couleurNoire,renderer);
    texteMenu_tex[1] = tex_text("ChowFun.ttf",20,"Quitter",couleurNoire,renderer);
    
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
                        imgBtnRect.x = 350;
                        imgBtnRect.y = 200;
                        txtMenuRect[0].x=378;
                        txtMenuRect[0].y=208;
                        txtMenuRect[1].x=370;
                        txtMenuRect[1].y=305;
                        SDL_QueryTexture(image_btn_tex, NULL, NULL, &(imgBtnRect.w), &(imgBtnRect.h));
                        for(i=0;i<2;i++){
                            if(x<460 && 350<x && y<imgBtnRect.y+55 && imgBtnRect.y<y){
                                if(e.type == SDL_MOUSEBUTTONDOWN){
                                    SDL_DestroyWindow(pWindow);
                                    if(i==0){
                                        nb_joueur = choix_nbJoueur();
                                        fprintf(stderr,"nb_joueur = %d \n", nb_joueur);
                                        joueur_t * tab = malloc(sizeof(joueur_t)*nb_joueur);
                                        fprintf(stderr,"nb_joueur2 = %d \n", nb_joueur);
                                        do{
                                            nb_bloquante = choix_nbBloq();
                                        }while(nb_bloquante>42);
                                        flo_test_pseudo(--nb_joueur,tab,nb_bloquante,0);
                                        //On vérifie que les informations sont bien enregistrés
                                        for(int test = 0;test<=nb_joueur;test++){
                                            fprintf(stderr,"joueur %d pseudo = %s, couleur = %c, nbBloq = %d \n",test,tab[test].pseudo,tab[test].couleur,tab[test].nb_bloq);
                                        }
                                        for(joueur = 0 ;!mat_remplie(mat); joueur++, ){             
                                            joueur=joueur%nb_joueur;
                                            printf("C'est à %s de joueur !", tab[joueur].pseudo);
                                            tour_joueur(&tab[joueur],mat);
                                            if((gagne(&tab[(joueur%nb_joueur)],mat)))
                                                break;          
                                        }
                                        if(mat_remplie(mat)){
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

                                    }
                                    return 0;
                                }
                            }
                            txt_titre.x = 170;
                            txt_titre.y = 10;
                            SDL_QueryTexture(texte_tex, NULL, NULL, &(txt_titre.w), &(txt_titre.h));
                            SDL_RenderCopy(renderer, texte_tex, NULL, &(txt_titre));

                            SDL_RenderCopy(renderer, image_btn_tex, NULL, &imgBtnRect);

                            SDL_QueryTexture(texteMenu_tex[i], NULL, NULL, &(txtMenuRect[i].w), &(txtMenuRect[i].h));
                            SDL_RenderCopy(renderer, texteMenu_tex[i], NULL, &(txtMenuRect[i]));
                            imgBtnRect.y += 90;
                        }
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

