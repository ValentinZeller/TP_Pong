#include "gamemanager.h"

void initGame(gameManager* manager) {
    manager->balle = initBall(initGameObject(initVect(WINDOWS_WIDTH/2,WINDOWS_HEIGHT/2),"asset/ball.png",initVect(WINDOWS_WIDTH/2,WINDOWS_HEIGHT/2),BALL_SIZE,BALL_SIZE),BALL_SPEED,initVect(-1,-1));
    manager->player1 = initPlayer(initGameObject(initVect(PLAYER1_X,PLAYER_Y),"asset/player.png",initVect(PLAYER1_X,PLAYER_Y),PLAYER_WIDTH,PLAYER_HEIGHT),PLAYER_SPEED,0);
    manager->player2 = initPlayer(initGameObject(initVect(PLAYER2_X,PLAYER_Y),"asset/player.png",initVect(PLAYER2_X,PLAYER_Y),PLAYER_WIDTH,PLAYER_HEIGHT),PLAYER_SPEED,0);
}

void MoveBall(gameManager *manager) {
    int nSpeed = getBallVelocity(manager->balle);
    int ballX = getVectPosX(getObjPos(getBallObj(manager->balle)));
    int ballY = getVectPosY(getObjPos(getBallObj(manager->balle)));

    if (ballY  <= 0) {
        manager->balle.direction.nPosY = 1;
    } else if (ballY >= WINDOWS_HEIGHT ) {
        manager->balle.direction.nPosY = -1;
    }

    if (collision(ballX,ballY,getPlayerObj(manager->player1))) {
        manager->balle.direction.nPosX = 1;
        manager->balle.nVelocity += 1;
    } else if (collision(ballX,ballY,getPlayerObj(manager->player2))) {
        manager->balle.direction.nPosX = -1;
        manager->balle.nVelocity += 1;
    } else if (ballX < 0) {
        manager->player2.nScore += 1;
        manager->balle.nVelocity = BALL_SPEED;
        respawnBall(manager);
    } else if (ballX > WINDOWS_WIDTH ) {
        manager->player1.nScore += 1;
        manager->balle.nVelocity = BALL_SPEED;
        respawnBall(manager);
    }


    manager->balle.obj.position.nPosX += nSpeed*getVectPosX(getBallDirection(manager->balle));
    manager->balle.obj.position.nPosY += nSpeed*getVectPosY(getBallDirection(manager->balle));

}

void MovePlayer(gameManager *manager, int nVertical) {
    if ((getVectPosY(getObjPos(getPlayerObj(manager->player1)))+getHitboxHeight(getPlayerObj(manager->player1)) < WINDOWS_HEIGHT) && (nVertical > 0)) {
        manager->player1.obj.position.nPosY += getPlayerSpeed(manager->player1)*nVertical;
        manager->player1.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player1)*nVertical;
    }
    if ((getVectPosY(getObjPos(getPlayerObj(manager->player1))) > 0) && (nVertical < 0)) {
        manager->player1.obj.position.nPosY += getPlayerSpeed(manager->player1)*nVertical;
        manager->player1.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player1)*nVertical;
    }
}

void MoveIA(gameManager *manager) {
    int player2Y = getVectPosY(getObjPos(getPlayerObj(manager->player2)));
    int player2H = getHitboxHeight(getPlayerObj(manager->player2));
    int ballY = getVectPosY(getObjPos(getBallObj(manager->balle)));

    if (player2Y > ballY) {
        manager->player2.obj.position.nPosY += getPlayerSpeed(manager->player2)*-1;
        manager->player2.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player2)*-1;
    } else if (player2Y+player2H < ballY) {
        manager->player2.obj.position.nPosY += getPlayerSpeed(manager->player2);
        manager->player2.obj.hitboxPos.nPosY += getPlayerSpeed(manager->player2);
    }

}

int collision(int collideAX, int collideAY, gameObject colliderB) {
    int isCollision = 0;

    int nLeftB = getVectPosX(getHitboxPos(colliderB));
    int nTopB = getVectPosY(getHitboxPos(colliderB));
    int nRightB = nLeftB + getHiboxWidth(colliderB);
    int nBottomB = nTopB + getHitboxHeight(colliderB);

    if ((collideAX >= nLeftB) && (collideAX <= nRightB) && (collideAY >= nTopB) && (collideAY <= nBottomB)) {
        isCollision = 1;
    }

    return isCollision;
}

void respawnBall(gameManager *manager) {
    manager->balle.obj.position.nPosX = WINDOWS_WIDTH/2;
    manager->balle.obj.position.nPosY = WINDOWS_HEIGHT/2;
}

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
