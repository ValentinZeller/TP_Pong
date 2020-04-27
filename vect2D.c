#include "vect2D.h"

int getVectPosX(vect2D position) {
    return position.nPosX;
}
int getVectPosY(vect2D position) {
    return position.nPosY;
}
void setVectPosX(vect2D *pPosition,int nX) {
    pPosition->nPosX = nX;
}
void setVectPosY(vect2D *pPosition,int nY) {
    pPosition->nPosY = nY;
}

vect2D addVect(vect2D vect1,vect2D vect2) {
    vect2D vectTemp;
    setVectPosX(&vectTemp,getVectPosX(vect1)+getVectPosX(vect2));
    setVectPosY(&vectTemp,getVectPosY(vect1)+getVectPosY(vect2));
    return vectTemp;
}
vect2D sousVect(vect2D vect1, vect2D vect2) {
    vect2D vectTemp;
    setVectPosX(&vectTemp,getVectPosX(vect1)-getVectPosX(vect2));
    setVectPosY(&vectTemp,getVectPosY(vect1)-getVectPosY(vect2));
    return vectTemp;
}
vect2D scaleVect(vect2D vect1, int scalar) {
    vect2D vectTemp;
    setVectPosX(&vectTemp,getVectPosX(vect1)*scalar);
    setVectPosY(&vectTemp,getVectPosY(vect1)*scalar);
    return vectTemp;
}
int prodScalVect(vect2D vect1,vect2D vect2) {
    return getVectPosX(vect1)*getVectPosX(vect2)+getVectPosY(vect1)*getVectPosY(vect2);
}
vect2D prodVect(vect2D vect1,vect2D vect2) {
    vect2D vectTemp;
    setVectPosX(&vectTemp,getVectPosY(vect1)-getVectPosY(vect2));
    setVectPosY(&vectTemp,getVectPosX(vect1)-getVectPosX(vect2));
    return vectTemp;
}

vect2D initVect(int nX, int nY) {
    vect2D vectTemp;
    setVectPosX(&vectTemp,nX);
    setVectPosY(&vectTemp,nY);
    return vectTemp;
}
