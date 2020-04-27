#include "sprite.h"

//**********************************************************
//Description : Création d'une texture à partir d'une surface
//Entree : Le Sprite et SDL Manager
//Sortie :
//**********************************************************
void createSpriteTexture(sdl_manager* sdl, sprite* pSprite) {
    if (pSprite->pSurface) {
        pSprite->pTexture = SDL_CreateTextureFromSurface(sdl->pRenderer,pSprite->pSurface);
        SDL_FreeSurface(pSprite->pSurface);
    }
}

//**********************************************************
//Description : Chargement de l'image dans la surface
//Entree : Le sprite et le chemin d'accès à l'image
//Sortie :
//**********************************************************
void loadSpriteImage(sprite* pSprite, char* cImagePath) {
    pSprite->pSurface = IMG_Load(cImagePath);
    if (!pSprite->pSurface) {
        printf("Erreur au chargement de l'image : %s\n",IMG_GetError());
    }
}

//**********************************************************
//Description : Suppression d'un sprite
//Entree : Le sprite à supprimer
//Sortie :
//**********************************************************
void deleteSprite(sprite *pSprite) {
    if (pSprite->pTexture != NULL) {
        SDL_DestroyTexture(pSprite->pTexture);
    }
}

//**********************************************************
//Description : Affichage d'un sprite
//Entree : Le gestionnaire de la SDL
//         Le sprite à afficher
//         Position X,Y dans l'image
//         Position X,Y dans l'écran d'affichage
//         Largeur et Hauteur
//         Delai après affichage
//Sortie :
//**********************************************************
void displaySprite(sdl_manager* sdl,sprite* pSprite,int nSrcRectX, int nSrcRectY,int nDestRectX,int nDestRectY,int nWidth,int nHeight, int nDelay) {
    SDL_Rect srcRect;
    SDL_Rect destRect;


    if(pSprite->pTexture){

       srcRect.x=nSrcRectX;
       srcRect.y=nSrcRectY;

       srcRect.w=nWidth;
       srcRect.h=nHeight;


       destRect.x=nDestRectX;
       destRect.y=nDestRectY;


       destRect.w=srcRect.w;
       destRect.h=srcRect.h;


       SDL_RenderCopy(sdl->pRenderer, pSprite->pTexture, &srcRect, &destRect);

    }
}
