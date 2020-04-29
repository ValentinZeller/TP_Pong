#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "const.h"
#include "ball.h"
#include "player.h"
#include <stdlib.h>
#include <math.h>

typedef struct gamemanager{
    player player1, player2; //Player 1 à gauche, Player 2 à droite
    ball balle;
    gameObject join,quit;
} gamemanager, GameManager, gameManager;

extern void initGame(gameManager *manager);
extern void MoveBall(gameManager *manager);
extern void MovePlayer(gameManager *manager, int nVertical);
extern int collision(int collideAX, int collideAY, gameObject colliderB);
extern void respawnBall(gameManager* manager);
extern void initMenu(gameManager* manager);
void MoveIA(gameManager *manager);
#endif // GAMEMANAGER_H_INCLUDED
