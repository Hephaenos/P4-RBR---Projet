#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */

void pause();

int main(int argc, char *argv[]){
  int statut = EXIT_FAILURE;
  SDL_Window * window = NULL;                                                        // Initialisation des interfaces que l'on aura besoin pour faire fonctionner la SDL
  SDL_Renderer * renderer = NULL;
  SDL_Texture * texture = NULL;
  TTF_Font * police = NULL;
  SDL_Rect rect = {100, 100, 100, 100}, dst = {0, 0, 0, 0};                         // (x,y,largeur,hauteur)
  SDL_Color rouge = {255, 0, 0, 255}, bleu = {0, 0, 255, 255};


  if(SDL_Init(SDL_INIT_VIDEO)!=0){                                                      // SDL_Init renvoie 0 si tout se passe bien sinon un nombre négatif
    fprintf(stdout,"Échec de l'initialisation de la SDL %s\n",SDL_GetError());
    goto Quit;
  }
	if(TTF_Init() == -1){
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());          // Initialisation TTF
		goto Quit;
	}

  window = SDL_CreateWindow("Puissance 4++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,        // Création de la fenêtre SDL
                              800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if(window == NULL){
      fprintf(stderr, "Erreur SDL_CreateWindow : %s\n",SDL_GetError());                       // Vérification si la fenêtre a bien été crée
      goto Quit;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);                        // Création du rendu de la fenêtre
  if(renderer == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());                   // Test pour voir si le rendu se fait bien
        goto Quit;
  }

  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                             SDL_TEXTUREACCESS_TARGET, 500, 500);
  if(texture == NULL){
    fprintf(stderr, "Erreur SDL_CreateTexture : %s\n", SDL_GetError());
    goto Quit;
  }

  if(window){
		int running = 1;
		while(running){
			SDL_Event e;
			while(SDL_PollEvent(&e)){
				switch(e.type){
					case SDL_QUIT: running = 0;
					break;
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera blanc */
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
								SDL_RenderClear(renderer);
                SDL_SetRenderTarget(renderer, texture);
   /* La texture est la cible de rendu, maintenant, on dessine sur la texture. */
                SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);               // r: rouge || g: vert || b: bleu || a: intensité
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, rouge.r, rouge.g, rouge.b, rouge.a);
                SDL_RenderFillRect(renderer, &rect);                                        /* On dessine un rectangle rouge sur la texture. */
                SDL_SetRenderTarget(renderer, NULL);                                        /* Le renderer est la cible de rendu. */
   /* On récupère les dimensions de la texture, on la copie sur le renderer
      et on met à jour l’écran. */
                SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
                SDL_RenderCopy(renderer, texture, NULL, &dst);

                SDL_RenderPresent(renderer);
							break;
						}
					break;
				}
			}
		}
	}
  else {
	  fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

  statut = EXIT_SUCCESS;

Quit:                                                                                           // Destruction des pointeurs si jamais ils sont existant sinon ne rien faire
  if(texture != NULL){
     SDL_DestroyTexture(texture);
  }
  if(renderer != NULL){
    SDL_DestroyRenderer(renderer);
  }
  if(window != NULL){
    SDL_DestroyWindow(window);
  }
  SDL_Quit();
  return statut;
}
