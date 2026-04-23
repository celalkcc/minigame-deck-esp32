#include <Arduino.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "controller.hpp"
#include "ball.hpp"
#include "display.hpp"

Controller L(LEFT_POTI);
Controller R(RIGHT_POTI);

Paddle LeftPlayer(WALL_DISTANCE, 0, PADDLE_SIZE);
Paddle RightPlayer(RIGHT_BORDER - WALL_DISTANCE, 0, PADDLE_SIZE);
Ball mainBall(0, 0, 1, 1);
myDisplay oledScreen;

void pongBegin() {
    oledScreen.begin();
}

void pongUpdate() {
    LeftPlayer.update(L.getValue());
    RightPlayer.update(R.getValue());
    mainBall.update();
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
    mainBall.bounceX(LeftPlayer.getX(), LeftPlayer.getUpperY(), LeftPlayer.getLowerY());
    mainBall.bounceX(RightPlayer.getX(), RightPlayer.getUpperY(), RightPlayer.getLowerY());   
}

void pongDrawScreen() {
    oledScreen.clear();
    oledScreen.drawPixel(mainBall.getX(), mainBall.getY());
    oledScreen.drawPaddle(LeftPlayer.getX(), LeftPlayer.getUpperY(), LeftPlayer.getLowerY());
    oledScreen.drawPaddle(RightPlayer.getX(), RightPlayer.getUpperY(), RightPlayer.getLowerY());
    oledScreen.update();
}