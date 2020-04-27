//**********************************************
//Fichier : vue.h
//
//Classe : sdl_manager
//Description : Gestion de l'affichage avec la SDL
//Attributs :
//
//Notes :
//**********************************************

#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED

#include "gamemanager.h"
#include "sdlmanager.h"
#include "sprite.h"
#include "player.h"


extern void displayScore(sdl_manager* sdl,player player,int nPosX);
extern void displayGame(sdl_manager* sdl,sprite* balle, sprite* player1, sprite* player2,gameManager* manager);
extern void displayMenu(sdl_manager* sdl);
extern void displayText(sdl_manager* sdl,int nPosX, int nPosY, int nWidth, int nHeight, SDL_Color color, char* text);
extern void displayEnd(sdl_manager* sdl, gameManager* manager);

#endif // VUE_H_INCLUDED
