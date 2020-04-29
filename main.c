#include "gamemanager.h"
#include "vue.h"

int mainGame(sdl_manager* sdl,gameManager* manager);

int main(int argc, char *argv[])
{
    sdl_manager sdl; //Gestion de la SDL
    gameManager manager;// Gestion du jeu
    SDL_Event event;// Gestion des événements

    //Initialisation de la SDL
    SDLManager_Init(&sdl);

    //Reset de l'affichage à l'écran
    SDLManager_ClearScreen(sdl.pRenderer);

    //Initilisation du menu
    initMenu(&manager);
    //Menu titre pour commencer ou quitter
    while (1) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEBUTTONDOWN :
                    //Si l'utilisateur clique sur la zone "START", on commence la partie
                    if (collision(event.button.x,event.button.y,manager.join)) {
                        mainGame(&sdl,&manager);
                    }
                    //Si l'utilisateur clique sur la zone "QUIT", fin du programme
                    else if (collision(event.button.x,event.button.y,manager.quit)) {
                        SDLManager_Stop(&sdl);
                        return 0;
                    }
                    break;
            }
        }
        //Reset de l'affichage à l'écran
        SDLManager_ClearScreen(sdl.pRenderer);
        //Affichage du menu
        displayMenu(&sdl);
    }

    return 0;
}

//**********************************************************
//Description : Gestion du jeu
//Entree : Gestionnaire de la SDL et du jeu
//Sortie :
//**********************************************************
int mainGame(sdl_manager* sdl,gameManager* manager) {
    sprite balle,player1,player2; //Sprites de la balle, joueur 1 et joueur 2
    const Uint8* keystates = SDL_GetKeyboardState(NULL); // Gestion des inputes claviers
    SDL_Event event; //Gestion des événements (pour quitter en cours de parties)

    //Initialiation du jeu
    initGame(manager);

    //Chargement et création des sprites
    loadSpriteImage(&balle,getObjSprite(getBallObj(manager->balle)));
    createSpriteTexture(sdl,&balle);
    loadSpriteImage(&player1,getObjSprite(getPlayerObj(manager->player1)));
    createSpriteTexture(sdl,&player1);
    loadSpriteImage(&player2,getObjSprite(getPlayerObj(manager->player2)));
    createSpriteTexture(sdl,&player2);

    //Tant qu'aucun joueur n'a atteint le score max, la partie continue
    while((getPlayerScore(manager->player1) < SCORE_MAX) && (getPlayerScore(manager->player2) < SCORE_MAX)) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                //Si l'utilisateur appuye sur echap, fin de la partie
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

        //Mouvement du joueur
        if (keystates[SDL_SCANCODE_UP])
            MovePlayer(manager,-1);
        else if (keystates[SDL_SCANCODE_DOWN])
            MovePlayer(manager, 1);

        //Mouvement de l'IA
        MoveIA(manager);

        //Mouvement de la balle
        MoveBall(manager);


        //Affichage du jeu
        displayGame(sdl,&balle,&player1,&player2,manager);
    }
    //Ecran de fin (victoire ou défaite)
    displayEnd(sdl,manager);
    //Arrêt de la SDL
    deleteSprite(&player2);
    deleteSprite(&player1);
    deleteSprite(&balle);
    return 0;
}
