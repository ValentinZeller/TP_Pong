#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "sdlmanager.h"

typedef struct sprite {
    SDL_Surface *pSurface;
    SDL_Texture *pTexture;
} sprite, Sprite;

extern void createSpriteTexture(sdl_manager* sdl, sprite* pSprite);
extern void loadSpriteImage(sprite* pSprite, char* cImagePath);
extern void deleteSprite(sprite *pSprite);
extern void displaySprite(sdl_manager* sdl,sprite* pSprite,int nSrcRectX, int nSrcRectY,int nDestRectX,int nDestRectY,int nWidth,int nHeight, int nDelay);
#endif // SPRITE_H_INCLUDED
