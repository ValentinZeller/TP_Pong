#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "gameobject.h"

typedef struct player {
    gameObject obj;
    int nSpeed, nScore;
} player, Player;

extern gameObject getPlayerObj(player joueur);
extern int getPlayerSpeed(player joueur);
extern int getPlayerScore(player joueur);

extern void setPlayerObj(player *pJoueur,gameObject object);
extern void setPlayerSpeed(player *pJoueur, int speed);
extern void setPlayerScore(player *pJoueur, int score);

extern player initPlayer(gameObject object, int speed, int score);

#endif // PLAYER_H_INCLUDED
