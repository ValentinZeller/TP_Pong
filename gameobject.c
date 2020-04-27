#include "gameobject.h"

vect2D getObjPos(gameObject object) {
    return object.position;
}
char* getObjSprite(gameObject object) {
    return object.cSprite;
}
vect2D getHitboxPos(gameObject object) {
    return object.hitboxPos;
}
int getHiboxWidth(gameObject object) {
    return object.nHitboxWidth;
}
int getHitboxHeight(gameObject object) {
    return object.nHitboxHeight;
}

void setObjPos(gameObject *pObject, vect2D pos) {
    pObject->position = pos;
}
void setObjSprite(gameObject *pObject, char *sprite) {
    pObject->cSprite = sprite;
}
void setHitboxPos(gameObject *pObject, vect2D pos) {
    pObject->hitboxPos = pos;
}
void setHitboxWidth(gameObject *pObject, int width) {
    pObject->nHitboxWidth = width;
}
void setHitboxHeight(gameObject *pObject, int height) {
    pObject->nHitboxHeight = height;
}

gameObject initGameObject(vect2D pos, char* sprite, vect2D hitbox, int width, int height) {
    gameObject objTemp;
    setObjPos(&objTemp,pos);
    setObjSprite(&objTemp,sprite);
    setHitboxPos(&objTemp,hitbox);
    setHitboxWidth(&objTemp,width);
    setHitboxHeight(&objTemp,height);
    return objTemp;
}
