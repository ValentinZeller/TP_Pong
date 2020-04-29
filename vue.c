//**********************************************
//Fichier : vue.c
//
//Classe :
//**********************************************

#include "vue.h"


//**********************************************************
//Description : Affichage du jeu
//Entree : Gestionnaire de la SDL
//         Sprite de la balle, du joueur, du joueur 2
//         Gestionnaire du jeu
//Sortie :
//**********************************************************
void displayGame(sdl_manager* sdl,sprite* balle, sprite* player1, sprite* player2,gameManager* manager) {
        SDLManager_ClearScreen(sdl->pRenderer);

        //Trait qui sépare l'écran en deux parties
        SDL_SetRenderDrawColor(sdl->pRenderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(sdl->pRenderer,WINDOWS_WIDTH/2,0,WINDOWS_WIDTH/2,WINDOWS_HEIGHT);

        //Score
        displayScore(sdl,manager->player1,100);
        displayScore(sdl,manager->player2,WINDOWS_WIDTH-150-5);

        //Balle et joueurs
        displaySprite(sdl,balle,0,0,getVectPosX(getObjPos(getBallObj(manager->balle))),getVectPosY(getObjPos(getBallObj(manager->balle))),getHiboxWidth(getBallObj(manager->balle)),getHitboxHeight(getBallObj(manager->balle)),0);
        displaySprite(sdl,player1,0,0,getVectPosX(getObjPos(getPlayerObj(manager->player1))),getVectPosY(getObjPos(getPlayerObj(manager->player1))),getHiboxWidth(getPlayerObj(manager->player1)),getHitboxHeight(getPlayerObj(manager->player1)),0);
        displaySprite(sdl,player2,0,0,getVectPosX(getObjPos(getPlayerObj(manager->player2))),getVectPosY(getObjPos(getPlayerObj(manager->player2))),getHiboxWidth(getPlayerObj(manager->player2)),getHitboxHeight(getPlayerObj(manager->player2)),0);

        SDLManager_Refresh(sdl->pRenderer,0);
}

//**********************************************************
//Description : Affichage du score
//Entree : Gestionnaire de la SDL
//         Un joueur
//         Position horizontale
//Sortie :
//**********************************************************
void displayScore(sdl_manager* sdl,player player, int nPosX) {
    SDL_Color color = {255,255,255,255};

    char str[12];
    sprintf(str, "%d", player.nScore);

    displayText(sdl,nPosX,10,40,40,color,str);
}

//**********************************************************
//Description : Affichage d'un texte
//Entree : Gestionnaire de la SDL
//         Position horizontale et verticale
//         Largeur et Hauteur
//         Couleur utilisée
//         Texte à afficher
//Sortie :
//**********************************************************
void displayText(sdl_manager* sdl,int nPosX, int nPosY, int nWidth, int nHeight, SDL_Color color, char* text) {
    TTF_Font *police = NULL;
    Sprite texte;

    if ((police = TTF_OpenFont("asset/bit5x5.ttf",22))==NULL) {
        printf("Erreur chargement de police %s\n",SDL_GetError());
    }

    texte.pSurface = TTF_RenderText_Solid(police,text,color);
    createSpriteTexture(sdl,&texte);
    displaySprite(sdl,&texte,0,0,nPosX,nPosY,nWidth,nHeight,0);

    TTF_CloseFont(police);
}

//**********************************************************
//Description : Affichage du menu
//Entree : Gestionnaire de la SDL
//Sortie :
//**********************************************************
void displayMenu(sdl_manager* sdl) {
    SDL_Color color = {255,255,255,255};

    displayText(sdl,WINDOWS_WIDTH/4,20,WINDOWS_WIDTH/2,WINDOWS_HEIGHT/4,color,"PONG");
    displayText(sdl,WINDOWS_WIDTH/2.5,WINDOWS_HEIGHT/2,WINDOWS_WIDTH/4,WINDOWS_HEIGHT/8,color,"START");
    displayText(sdl,WINDOWS_WIDTH/2.5,WINDOWS_HEIGHT/1.5,WINDOWS_WIDTH/4,WINDOWS_HEIGHT/8,color,"QUIT");

    SDLManager_Refresh(sdl->pRenderer,0);
}

//**********************************************************
//Description : Affichage de fin de partie
//Entree : Gestionnaire de la SDL et du jeu
//Sortie :
//**********************************************************
void displayEnd(sdl_manager* sdl, gameManager* manager) {
    SDL_Color white = {255,255,255,SDL_ALPHA_OPAQUE};
    SDLManager_ClearScreen(sdl->pRenderer);

    if (getPlayerScore(manager->player1) >= SCORE_MAX) {
        displayText(sdl,WINDOWS_WIDTH/4,WINDOWS_HEIGHT/3,WINDOWS_WIDTH/2,WINDOWS_HEIGHT/4,white,"VICTOIRE");
    } else {
        displayText(sdl,WINDOWS_WIDTH/4,WINDOWS_HEIGHT/3,WINDOWS_WIDTH/2,WINDOWS_HEIGHT/4,white,"DEFAITE");
    }
    SDLManager_Refresh(sdl->pRenderer,2500);
}
