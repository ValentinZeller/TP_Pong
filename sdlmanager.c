#include "sdlmanager.h"

//**********************************************************
//Description : Initialisation de la SDL et du gestionnaire de de la SDL
//Entree : Le gestionnaire de la SDL
//Sortie :
//**********************************************************
void SDLManager_Init(sdl_manager *sdl) {
    sdl->pWindow = NULL;
    sdl->pRenderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL_Init Error: %s\n",SDL_GetError());;
        return EXIT_FAILURE;
    }

    sdl->pWindow = SDL_CreateWindow("Une fenetre SDL",SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, WINDOWS_WIDTH, WINDOWS_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (sdl->pWindow == NULL) { //Si la fenêtre est vide, on stop le programme
        printf("Erreur lors de la creation d'une fenetre : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    sdl->pRenderer = SDL_CreateRenderer(sdl->pWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (sdl->pRenderer == NULL) {//Si le renderer est vide, on stop le programme
        printf("Erreur lors de la création du render : %s\n",SDL_GetError());
        return EXIT_FAILURE;

    }
    IMG_Init(IMG_INIT_PNG);
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
}

//**********************************************************
//Description : Remettre l'affichage en noir
//Entree : Gestionnaire de la SDL
//Sortie :
//**********************************************************
void SDLManager_ClearScreen(SDL_Renderer *pRenderer) {
    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
    SDL_RenderClear(pRenderer);
}

//**********************************************************
//Description : Raffraichissement de l'affichage
//Entree : Le gestionnaire de la SDL et le delais d'affichage
//Sortie :
//**********************************************************
void SDLManager_Refresh(SDL_Renderer *pRenderer,int nDelay) {
    SDL_RenderPresent(pRenderer);
    SDL_Delay(nDelay);
}


//**********************************************************
//Description : Arrêt de la SDL
//Entree : Le gestionnaire de la SDL
//Sortie :
//**********************************************************
void SDLManager_Stop(sdl_manager *sdl) {

    /* Libération des instances */
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(sdl->pRenderer); //Suppression du renderer
    SDL_DestroyWindow(sdl->pWindow); //Suppression de la fenêtre

    SDL_Quit();  //Fin de la SDL
}
