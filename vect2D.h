#ifndef VECT2D_H_INCLUDED
#define VECT2D_H_INCLUDED

typedef struct vect2D {
    int nPosX, nPosY;
} vect2D, Vect2D;

extern int getVectPosX(vect2D position);
extern int getVectPosY(vect2D position);

extern void setVectPosX(vect2D *pPosition,int nX);
extern void setVectPosY(vect2D *pPosition,int nY);

extern vect2D addVect(vect2D vect1,vect2D vect2);
extern vect2D sousVect(vect2D vect1, vect2D vect2);
extern vect2D scaleVect(vect2D vect1, int scalar);
extern int prodScalVect(vect2D vect1,vect2D vect2);
extern vect2D prodVect(vect2D vect1,vect2D vect2);

extern vect2D initVect(int nX, int nY);

#endif // VECT2D_H_INCLUDED
