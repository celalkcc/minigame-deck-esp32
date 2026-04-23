#include "ball.hpp"
#include "conf.hpp"

// Constructor
Ball::Ball(int startX, int startY, int velocityX, int velocityY){
    x = startX;
    y = startY;
    veloX = velocityX;
    veloY = velocityY;
}

void Ball::resetToCenter(){
    y = SCREEN_HEIGHT / 2;
    x = SCREEN_WIDTH / 2;
}

void Ball::update(){
    y += veloY;
    x += veloX;
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

