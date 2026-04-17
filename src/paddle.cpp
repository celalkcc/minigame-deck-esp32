#include "paddle.hpp"
#include "controller.hpp"
#include "pong.hpp"

Paddle::Paddle(int startX, int controllerY, int paddleSize){
    wallDistance = startX;
    size = paddleSize;
    upperY = controllerY;
    lowerY = upperY + size;
}

void Paddle::update(int controllerY){     
   upperY = controllerY;
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