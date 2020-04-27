#include "gamemanager.h"
#include "vue.h"

int mainGame(sdl_manager* sdl,gameManager* manager);

int main(int argc, char *argv[])
{
    sdl_manager sdl;
    gameManager manager;
    SDL_Event event;

    SDLManager_Init(&sdl);
    SDLManager_ClearScreen(sdl.pRenderer);

    initMenu(&manager);
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN :
                    if (collision(event.button.x,event.button.y,manager.join)) {
                        mainGame(&sdl,&manager);
                    }
                    else if (collision(event.button.x,event.button.y,manager.quit)) {
                        SDLManager_Stop(&sdl);
                        return 0;
                    }
                    break;
            }
        }
        SDLManager_ClearScreen(sdl.pRenderer);
        displayMenu(&sdl);
    }

    return 0;
}

int mainGame(sdl_manager* sdl,gameManager* manager) {
    sprite balle,player1,player2;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    SDL_Event event;

    initGame(manager);
    loadSpriteImage(&balle,getObjSprite(getBallObj(manager->balle)));
    createSpriteTexture(sdl,&balle);
    loadSpriteImage(&player1,getObjSprite(getPlayerObj(manager->player1)));
    createSpriteTexture(sdl,&player1);
    loadSpriteImage(&player2,getObjSprite(getPlayerObj(manager->player2)));
    createSpriteTexture(sdl,&player2);

    while((getPlayerScore(manager->player1) < SCORE_MAX) && (getPlayerScore(manager->player2) < SCORE_MAX)) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //Si l'utilisateur clique, fin du programme
                case SDL_KEYDOWN :
                    //Arrêt de la SDL
                    if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                        deleteSprite(&player2);
                        deleteSprite(&player1);
                        deleteSprite(&balle);
                        return 0;
                    }
                    break;
            }
        }
        /* Mouvement du joueur */
        if (keystates[SDL_SCANCODE_UP])
            MovePlayer(manager,-1);
        else if (keystates[SDL_SCANCODE_DOWN])
            MovePlayer(manager, 1);

        MoveBall(manager);

        MoveIA(manager);
        displayGame(sdl,&balle,&player1,&player2,manager);
    }
    displayEnd(sdl,manager);
    deleteSprite(&player2);
    deleteSprite(&player1);
    deleteSprite(&balle);
    return 0;
}
