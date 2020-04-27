#ifndef SDLMANAGER_H_INCLUDED
#define SDLMANAGER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "SDL.h" //Appel de la bibliothèque SDL2
#include "SDL_image.h" //Appel de la bibliothèque SDL2_image
#include "SDL_ttf.h" //Appel de la bibliothèque SDL2 ttf

typedef struct sdl_manager{
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
}sdl_manager;

extern void SDLManager_Init(sdl_manager *sdl);
extern void SDLManager_ClearScreen(SDL_Renderer *pRenderer);
extern void SDLManager_Refresh(SDL_Renderer *pRenderer,int nDelay);
extern void SDLManager_Stop(sdl_manager *sdl);

#endif // SDLMANAGER_H_INCLUDED
