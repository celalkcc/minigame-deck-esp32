#include <Arduino.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "input_conf.hpp"
#include "ball.hpp"


void gameInit() {
    Paddle LeftPlayer(WALL_DISTANCE, LEFT_POTI, PADDLE_SIZE);
    Paddle RightPlayer(SCREEN_HEIGHT - WALL_DISTANCE, RIGHT_POTI, PADDLE_SIZE);
    Ball mainBall(0, 0, 1, 1);
    }