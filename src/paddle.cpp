#include "paddle.hpp"
#include "input_conf.hpp"

Paddle::Paddle(int startX, int startY, int paddleSize){
    wallDistance = startX;
    y = startY;
    size = paddleSize;
}

void Paddle::update(){     
}

int Paddle::getY() const{
    return y;
}