#include "paddle.hpp"
#include "controller.hpp"
#include "pong.hpp"

Paddle::Paddle(int startX, int controllerY, int paddleSize){
    wallDistance = startX;
    size = paddleSize;
    upperY = controllerY;
    lowerY = upperY + PADDLE_SIZE;
}

void Paddle::update(int controllerY){     
    upperY = controllerY;
    lowerY = upperY + PADDLE_SIZE;
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