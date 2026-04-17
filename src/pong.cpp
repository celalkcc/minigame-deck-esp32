#include <Arduino.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "controller.hpp"
#include "ball.hpp"
#include "display.hpp"

Controller L(LEFT_POTI);
Controller R(RIGHT_POTI);

Paddle LeftPlayer(WALL_DISTANCE, L.getValue(), PADDLE_SIZE);
Paddle RightPlayer(SCREEN_WIDTH - WALL_DISTANCE, L.getValue(), PADDLE_SIZE);
Ball mainBall(0, 0, 1, 1);
myDisplay oledScreen;


void pongUpdate() {
    LeftPlayer.update(L.getValue());
    RightPlayer.update(R.getValue());
    mainBall.update();
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
    //mainBall. bounceX();
}

void pongDrawScreen() {
    oledScreen.clear();
    oledScreen.drawPixel(mainBall.getX(), mainBall.getY());
    oledScreen.drawPaddle(LeftPlayer.getX(), LeftPlayer.getUpperY(), LeftPlayer.getLowerY());
    oledScreen.update();
}