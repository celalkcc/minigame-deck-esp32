#include "paddle.hpp"
#include "input_conf.hpp"
#include "pong.hpp"

Paddle::Paddle(int startX, int startY, int paddleSize){
    wallDistance = startX;
    size = paddleSize;
    upperY = startY;
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