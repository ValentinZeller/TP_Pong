#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "gameobject.h"

typedef struct ball {
    gameObject obj;
    int nVelocity;
    float fltBallDirectionX, fltBallDirectionY;
}ball, Ball;

extern gameObject getBallObj(ball balle);
extern int getBallVelocity(ball balle);
extern float getBallDirectionX(ball balle);
extern float getBallDirectionY(ball balle);

extern void setBallObj(ball *pBalle, gameObject object);
extern void setBallVelocity(ball *pBalle,int veloc);
extern void setBallDirectionX(ball *pBalle,float drctX);
extern void setBallDirectionY(ball *pBalle,float drctY);

extern ball initBall(gameObject object, int veloc, float drctX, float drctY);
#endif // BALL_H_INCLUDED
