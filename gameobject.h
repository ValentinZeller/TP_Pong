#ifndef GAMEObject_H_INCLUDED
#define GAMEObject_H_INCLUDED

#include "vect2D.h"

typedef struct gameobject{
    vect2D position, hitboxPos;
    char *cSprite;
    int nHitboxWidth, nHitboxHeight;
} gameobject, gameObject, GameObject;

extern vect2D getObjPos(gameObject object);
extern char* getObjSprite(gameObject object);
extern vect2D getHitboxPos(gameObject object);
extern int getHiboxWidth(gameObject object);
extern int getHitboxHeight(gameObject object);

extern void setObjPos(gameObject *pObject, vect2D pos);
extern void setObjSprite(gameObject *pObject, char *sprite);
extern void setHitboxPos(gameObject *pObject, vect2D pos);
extern void setHitboxWidth(gameObject *pObject, int width);
extern void setHitboxHeight(gameObject *pObject, int height);

extern gameObject initGameObject(vect2D pos, char* sprite, vect2D hitbox, int width, int height);
#endif // GAMEObject_H_INCLUDED
