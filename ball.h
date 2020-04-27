#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "gameobject.h"

typedef struct ball {
    gameObject obj;
    int nVelocity;
    vect2D direction;
}ball, Ball;

extern gameObject getBallObj(ball balle);
extern int getBallVelocity(ball balle);
extern vect2D getBallDirection(ball balle);

extern void setBallObj(ball *pBalle, gameObject object);
extern void setBallVelocity(ball *pBalle,int veloc);
extern void setBallDirection(ball *pBalle,vect2D drct);

extern ball initBall(gameObject object, int veloc, vect2D drct);
#endif // BALL_H_INCLUDED
