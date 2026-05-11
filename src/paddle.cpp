#include "paddle.hpp"
#include "controller.hpp"
#include "pong.hpp"

Paddle::Paddle(int startX, int controllerY, int paddleSize){
    wallDistance = startX;
    size = PADDLE_SIZE;
    defaultSize = 0;
    upperY = controllerY;
    lowerY = upperY + size;
}

void Paddle::update(int controllerY){   
    size = PADDLE_SIZE; 
    upperY = controllerY;
    lowerY = upperY + size;
}

int Paddle::getX() const {
    return wallDistance;
}
int Paddle::getUpperY() const{
    return upperY;
}

int Paddle::getLowerY() const {
    return lowerY;
}


int Paddle::getPaddleSize() {
    return size;
}

void Paddle::halfSize() {
    size = size/2;
}

void Paddle::resetSize() {
    size = defaultSize;
}

void Paddle::setDefaultSize() {
    defaultSize = size;
}