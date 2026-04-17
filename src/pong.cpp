#include <Arduino.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "input_conf.hpp"
#include "ball.hpp"
#include "display.hpp"

Controller L(LEFT_POTI);
Controller R(RIGHT_POTI);

Paddle LeftPlayer(WALL_DISTANCE, LEFT_POTI, PADDLE_SIZE);
Paddle RightPlayer(SCREEN_HEIGHT - WALL_DISTANCE, RIGHT_POTI, PADDLE_SIZE);
Ball mainBall(0, 0, 1, 1);
myDisplay oledScreen;

// playing field
constexpr int UPPER_BORDER = 0;
constexpr int LOWER_BORDER = SCREEN_HEIGHT -1;
constexpr int LEFT_BORDER = 0;
constexpr int RIGHT_BORDER = SCREEN_WIDTH -1;

void pongUpdate() {
    mainBall.resetToCenter();
    LeftPlayer.update(L.getMappedValue());
    RightPlayer.update(R.getMappedValue());
    mainBall.update();
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
    //mainBall. bounceX()
}

void pongDrawScreen() {
    oledScreen.clear();
    oledScreen.drawPixel(mainBall.getX(), mainBall.getY());
    //oledScreen.drawRectangle(LeftPlayer.getX(), LeftPlayer.)


}