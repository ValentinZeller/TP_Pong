#include "player.h"

gameObject getPlayerObj(player joueur) {
    return joueur.obj;
}
int getPlayerSpeed(player joueur) {
    return joueur.nSpeed;
}
int getPlayerScore(player joueur) {
    return joueur.nScore;
}

void setPlayerObj(player *pJoueur,gameObject object) {
    pJoueur->obj = object;
}
void setPlayerSpeed(player *pJoueur, int speed) {
    pJoueur->nSpeed = speed;
}
void setPlayerScore(player *pJoueur, int score) {
    pJoueur->nScore = score;
}

player initPlayer(gameObject object, int speed, int score) {
    player playerTemp;
    setPlayerObj(&playerTemp,object);
    setPlayerSpeed(&playerTemp,speed);
    setPlayerScore(&playerTemp,score);
    return playerTemp;
}
