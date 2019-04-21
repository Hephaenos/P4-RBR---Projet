#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
  int statut = EXIT_FAILURE, x, y;
  SDL_Window * window = NULL;                                                        // Initialisation des interfaces que l'on aura besoin pour faire fonctionner la SDL
  SDL_Renderer * renderer = NULL;
  TTF_Font * police = NULL;
  SDL_Rect rect = {100, 100, 100, 100}, dst = {0, 0, 0, 0};                         // (x,y,largeur,hauteur)
  SDL_Color rouge = {255, 0, 0, 255}, bleu = {0, 0, 255, 255};
  SDL_Rect txtDestRect, txtBvnRect, txtMenuRect[4], imgBtnRect, imgBGRect;

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


  if(SDL_Init(SDL_INIT_VIDEO)!=0){                                                      // SDL_Init renvoie 0 si tout se passe bien sinon un nombre négatif
    fprintf(stdout,"Échec de l'initialisation de la SDL %s\n",SDL_GetError());
    goto Quit;
  }
	if(TTF_Init() == -1){
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());          // Initialisation TTF
		goto Quit;
	}

  window = SDL_CreateWindow("Puissance 4++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,        // Création de la fenêtre SDL
                              1000, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if(window == NULL){
      fprintf(stderr, "Erreur SDL_CreateWindow : %s\n",SDL_GetError());                       // Vérification si la fenêtre a bien été crée
      goto Quit;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);                        // Création du rendu de la fenêtre
  if(renderer == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());                   // Test pour voir si le rendu se fait bien
        goto Quit;
  }

SDL_Texture * image_BG_tex = tex_img_png("p4++.png",renderer);

  if(window){
		int running = 1;
		while(running){
			SDL_Event e;
      SDL_GetMouseState(&x,&y);                                                             // Nous prenons les coordonées du clic de la souris pour pouvoir gérer la colonne où mettre la pièce
			while(SDL_PollEvent(&e)){
				switch(e.type){
					case SDL_QUIT: running = 0;
					     break;
					case SDL_WINDOWEVENT:
							/* Le fond de la fenêtre sera blanc */
              SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
							SDL_RenderClear(renderer);

              //BACKGROUND
              imgBGRect.x = 0;
              imgBGRect.y = 100;

              SDL_QueryTexture(image_BG_tex, NULL, NULL, &(imgBGRect.w), &(imgBGRect.h));
              SDL_RenderCopy(renderer, image_BG_tex, NULL, &imgBGRect);
              
              if(x>0 && x<142 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 1
                if(e.type == SDL_MOUSEBUTTONDOWN){
                  SDL_DestroyWindow(window);
                  printf("1");
                }
              }
              else if(x>143 && x<285 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 2
                SDL_DestroyWindow(window);
                printf("2");
              }
              else if(x>286 && x<428 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 3
                SDL_DestroyWindow(window);
                printf("3");
              }
              else if(x>429 && x<571 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 4
                SDL_DestroyWindow(window);
                printf("4");
              }
              else if(x>572 && x<714 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 5
                SDL_DestroyWindow(window);
                printf("5");
              }
              else if(x>715 && x<857 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 6
                SDL_DestroyWindow(window);
                printf("6");
              }
              else if(x>858 && x<1000 && y>110 && y<790){
                // positionnement de la pièce dans la colonne 7
                SDL_DestroyWindow(window);
                printf("7");
              }
              SDL_RenderPresent(renderer);
				}
			}
		}
	}
  else {
	  fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

  statut = EXIT_SUCCESS;

Quit:                                                                                           // Destruction des pointeurs si jamais ils sont existant sinon ne rien faire
  if(renderer != NULL){
    SDL_DestroyRenderer(renderer);
  }
  if(window != NULL){
    SDL_DestroyWindow(window);
  }
  SDL_Quit();
  return statut;
}
