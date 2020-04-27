#include "ball.h"

gameObject getBallObj(ball balle) {
    return balle.obj;
}
int getBallVelocity(ball balle) {
    return balle.nVelocity;
}
vect2D getBallDirection(ball balle) {
    return balle.direction;
}

void setBallObj(ball *pBalle, gameObject object) {
    pBalle->obj = object;
}
void setBallVelocity(ball *pBalle,int veloc) {
    pBalle->nVelocity = veloc;
}
void setBallDirection(ball*pBalle, vect2D drct) {
    pBalle->direction = drct;
}

ball initBall(gameObject object, int veloc, vect2D drct) {
    ball ballTemp;
    setBallObj(&ballTemp,object);
    setBallVelocity(&ballTemp,veloc);
    setBallDirection(&ballTemp,drct);
    return ballTemp;
}
