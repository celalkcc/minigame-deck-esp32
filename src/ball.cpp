#include "ball.hpp"
#include "conf.hpp"

// Constructor
Ball::Ball(){
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT / 2;
    veloX = 1;
    veloY = 1;
}

void Ball::resetToCenter(){
    y = SCREEN_HEIGHT / 2;
    x = SCREEN_WIDTH / 2;
}

void Ball::update(bool xFlag, bool yFlag){
    if (yFlag){
        y += veloY;
    }
    if (xFlag){
        x += veloX;
    }
}

void Ball::bounceX(int xBounceBorder, int upperY, int lowerY){
    if (xBounceBorder < (SCREEN_WIDTH/2)) {
        if ((x == xBounceBorder + 1) && (y >= upperY) && (y <= lowerY)) {
            veloX = - veloX;
        }
    } else {
        if ((x == xBounceBorder - 1) && (y >= upperY) && (y <= lowerY)) {
            veloX = - veloX;
        }
    }
}



void Ball::bounceY(int upperBounceBorder, int lowerBounceBorder){
    if (y <= upperBounceBorder || y >= lowerBounceBorder) {
        veloY = - veloY;
    }
}   

int Ball::getX() const{
    return x;
}

int Ball::getY() const{
    return y;
}

bool Ball::checkScoreLeft() {
    int ballX = x;
    bool leftPlayerScored = 0;
    if (ballX >= RIGHT_BORDER) {
        leftPlayerScored = 1;
    }
    return leftPlayerScored;
}
bool Ball::checkScoreRight() {
    int ballX = x;

    bool rightPlayerScored = 0;
    if (ballX <= LEFT_BORDER) {
        rightPlayerScored = 1;
    }
    return rightPlayerScored;
}


