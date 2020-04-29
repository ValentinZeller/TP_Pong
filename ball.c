#include "ball.h"

gameObject getBallObj(ball balle) {
    return balle.obj;
}
int getBallVelocity(ball balle) {
    return balle.nVelocity;
}
float getBallDirectionX(ball balle) {
    return balle.fltBallDirectionX;
}

float getBallDirectionY(ball balle) {
    return balle.fltBallDirectionY;
}

void setBallObj(ball *pBalle, gameObject object) {
    pBalle->obj = object;
}
void setBallVelocity(ball *pBalle,int veloc) {
    pBalle->nVelocity = veloc;
}
void setBallDirectionX(ball*pBalle, float drctX) {
    pBalle->fltBallDirectionX = drctX;
}
void setBallDirectionY(ball*pBalle, float drctY) {
    pBalle->fltBallDirectionY = drctY;
}

ball initBall(gameObject object, int veloc, float drctX,float drctY) {
    ball ballTemp;
    setBallObj(&ballTemp,object);
    setBallVelocity(&ballTemp,veloc);
    setBallDirectionX(&ballTemp,drctX);
    setBallDirectionY(&ballTemp,drctY);
    return ballTemp;
}
