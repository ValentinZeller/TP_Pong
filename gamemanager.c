#include "gamemanager.h"

//**********************************************************
//Description : Initialisation du jeu
//Entree : Gestionnaire du jeu
//Sortie :
//**********************************************************

void initGame(gameManager* manager) {
    //Création de la balle
    manager->balle = initBall(initGameObject(initVect(WINDOWS_WIDTH/2,WINDOWS_HEIGHT/2),"asset/ball.png",initVect(WINDOWS_WIDTH/2,WINDOWS_HEIGHT/2),BALL_SIZE,BALL_SIZE),BALL_SPEED,-1,-1);
    //Création du joueur 1
    manager->player1 = initPlayer(initGameObject(initVect(PLAYER1_X,PLAYER_Y),"asset/player.png",initVect(PLAYER1_X,PLAYER_Y),PLAYER_WIDTH,PLAYER_HEIGHT),PLAYER_SPEED,0);
    //Création du joueur 2 (IA)
    manager->player2 = initPlayer(initGameObject(initVect(PLAYER2_X,PLAYER_Y),"asset/player.png",initVect(PLAYER2_X,PLAYER_Y),PLAYER_WIDTH,PLAYER_HEIGHT),PLAYER_SPEED-1,0);
}

//**********************************************************
//Description : Gestion du déplacement de balle
//Entree : Gestionnaire du jeu
//Sortie :
//**********************************************************
void MoveBall(gameManager *manager) {
    int nSpeed = getBallVelocity(manager->balle); //Vitesse de la balle
    int ballX = getVectPosX(getObjPos(getBallObj(manager->balle))); //Position horizontale de la balle
    int ballY = getVectPosY(getObjPos(getBallObj(manager->balle)));//Position verticale de la balle

    //Si la balle percute le haut ou le bas de l'écran, elle va dans la direction opposée en Y
    if (ballY  <= 0 || ballY+(BALL_SIZE/2) >= WINDOWS_HEIGHT) {
        manager->balle.fltBallDirectionY *= -1;
    }

    //Si la balle percute un joueur, elle va dans la direction opposée en X, avec une direction en Y selon à quelle endroit elle percute le joueur et plus vite
    if (collision(ballX,ballY,getPlayerObj(manager->player1))) {
        manager->balle.fltBallDirectionX = 1;
        manager->balle.nVelocity += 1;

        //La balle est redirigée selon sa position relative au centre de la raquette du joueur
        manager->balle.fltBallDirectionY = ((ballY - getVectPosY(getHitboxPos(getPlayerObj(manager->player1))))/(getHitboxHeight(getPlayerObj(manager->player1))/2)-0.5);
    } else if (collision(ballX,ballY,getPlayerObj(manager->player2))) {
        manager->balle.fltBallDirectionX = -1;
        manager->balle.nVelocity += 1;

        //La balle est redirigée selon sa position relative au centre de la raquette du joueur
        manager->balle.fltBallDirectionY = ((ballY - getVectPosY(getHitboxPos(getPlayerObj(manager->player2))))/(getHitboxHeight(getPlayerObj(manager->player2))/2)-0.5);
    }

    else if (ballX < 0) {
    //Si la balle atteint le bord gauche, le joueur 2 marque un point et la balle est remise au centre
        manager->player2.nScore += 1;
        manager->balle.nVelocity = BALL_SPEED;
        respawnBall(manager);
    } else if (ballX > WINDOWS_WIDTH ) {
        //Si la balle atteint le bord droit, le joueur 1 marque un point et la balle est remise au centre
        manager->player1.nScore += 1;
        manager->balle.nVelocity = BALL_SPEED;
        respawnBall(manager);
    }

    //Déplacement effectué
    manager->balle.obj.position.nPosX += nSpeed*getBallDirectionX(manager->balle);
    manager->balle.obj.position.nPosY += nSpeed*getBallDirectionY(manager->balle);

}

//**********************************************************
//Description : Gestion du déplacement du joueur
//Entree : Gestionnaire du jeu
//Sortie :
//**********************************************************
void MovePlayer(gameManager *manager, int nVertical) {
    //Si le joueur veut se déplacer vers le haut et qu'il n'est pas en haut de l'écran, alors il se déplace vers le haut
    if ((getVectPosY(getObjPos(getPlayerObj(manager->player1)))+getHitboxHeight(getPlayerObj(manager->player1)) < WINDOWS_HEIGHT) && (nVertical > 0)) {
        manager->player1.obj.position.nPosY += getPlayerSpeed(manager->player1)*nVertical;
        manager->player1.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player1)*nVertical;
    }
    //Si le joueur veut se déplacer vers le bas et qu'il n'est pas en bas de l'écran, alors il se déplace vers le bas
    if ((getVectPosY(getObjPos(getPlayerObj(manager->player1))) > 0) && (nVertical < 0)) {
        manager->player1.obj.position.nPosY += getPlayerSpeed(manager->player1)*nVertical;
        manager->player1.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player1)*nVertical;
    }
}


//**********************************************************
//Description : Gestion du déplacement de l'IA
//Entree : Gestionnaire du jeu
//Sortie :
//**********************************************************
void MoveIA(gameManager *manager) {
    int player2Y = getVectPosY(getObjPos(getPlayerObj(manager->player2))); //Position verticale de l'IA
    int player2H = getHitboxHeight(getPlayerObj(manager->player2)); // Hauteur de la hitbox de l'IA
    int ballY = getVectPosY(getObjPos(getBallObj(manager->balle)));// Position verticale de la balle

    //Si l'IA est au dessus de la balle, elle va vers le bas
    if (player2Y > ballY) {
        manager->player2.obj.position.nPosY += getPlayerSpeed(manager->player2)*-1;
        manager->player2.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player2)*-1;
    } else if (player2Y+player2H < ballY) {
    //Si l'IA est en dessous de la balle, elle va vers le haut
        manager->player2.obj.position.nPosY += getPlayerSpeed(manager->player2);
        manager->player2.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player2);
    }

}

//**********************************************************
//Description : Gestion des collisions entre la balle et les joueurs
//Entree : collideAX : position horizontale d'un objet (balle)
//         collideAY : position verticale d'un objet (balle)
//          colliderB : objet (joueur)
//Sortie : 0 s'il n'y a pas collision, 1 s'il y a collision
//**********************************************************
int collision(int collideAX, int collideAY, gameObject colliderB) {
    int isCollision = 0;//Stock s'il y a collision ou non

    int nLeftB = getVectPosX(getHitboxPos(colliderB)); //Position horizontale du côté gauche du joueur
    int nTopB = getVectPosY(getHitboxPos(colliderB));//Position verticale du côté haut du joueur
    int nRightB = nLeftB + getHiboxWidth(colliderB);//Position horizontal du côté droit du joueur
    int nBottomB = nTopB + getHitboxHeight(colliderB);//Position verticale du côté bas du joueur

    //Si la position de la balle est comprise dans les positions du joueur, alors il y a collision
    if ((collideAX+(BALL_SIZE/2) >= nLeftB) && (collideAX-(BALL_SIZE/2) <= nRightB) && (collideAY+(BALL_SIZE/2) >= nTopB) && (collideAY-(BALL_SIZE/2) <= nBottomB)) {
        isCollision = 1;
    }

    return isCollision;
}

//**********************************************************
//Description : Remise au centre
//Entree : Gestionnaire du jeu
//Sortie :
//**********************************************************
void respawnBall(gameManager *manager) {
    manager->balle.obj.position.nPosX = WINDOWS_WIDTH/2;
    manager->balle.obj.position.nPosY = WINDOWS_HEIGHT/2;
}

//**********************************************************
//Description : Iniialisation du menu
//Entree : Gestionnaire du jeu
//Sortie :
//**********************************************************
void initMenu(gameManager* manager) {
    manager->join.hitboxPos.nPosX = WINDOWS_WIDTH/2.5;
    manager->join.hitboxPos.nPosY = WINDOWS_HEIGHT/2;
    manager->join.nHitboxWidth = WINDOWS_WIDTH/4;
    manager->join.nHitboxHeight = WINDOWS_HEIGHT/8;

    manager->quit.hitboxPos.nPosX = WINDOWS_WIDTH/2.5;
    manager->quit.hitboxPos.nPosY = WINDOWS_HEIGHT/1.5;
    manager->quit.nHitboxWidth = WINDOWS_WIDTH/4;
    manager->quit.nHitboxHeight = WINDOWS_HEIGHT/8;
}


