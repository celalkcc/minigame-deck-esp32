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

void Ball::bounceX(int leftBounceBorder, int rightBounceBorder){
    if ((x <= leftBounceBorder || x >= rightBounceBorder) && y) {
        x = x * -1;
    }
}

void Ball::bounceY(int upperBounceBorder, int lowerBounceBorder){
    if (y <= upperBounceBorder || y >= lowerBounceBorder) {
        y = y * -1;
    }
}   

int Ball::getX() const{
    return x;
}

int Ball::getY() const{
    return y;
}

