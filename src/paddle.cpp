#include "paddle.hpp"

Paddle::Paddle(int startX, int startY, int paddleSize){
    wallDistance = startX;
    y = startY;
    size = paddleSize;
}

void Paddle::update(){
    // update the paddlePosition
}

int Paddle::getY() const{
    return y;
}