#ifndef CONF_HPP
#define CONF_HPP

// screen settings
constexpr int SCREEN_WIDTH = 128;
constexpr int SCREEN_HEIGHT = 64;

// calculating the playing field from screen settings
constexpr int LEFT_BORDER = 0;
constexpr int RIGHT_BORDER = SCREEN_WIDTH - 1;
constexpr int UPPER_BORDER = 0;
constexpr int LOWER_BORDER =SCREEN_HEIGHT -1;

// Paddle settings
#pragma once   
extern int PADDLE_SIZE;

constexpr int WALL_DISTANCE = 10;

// peripherals and their pins
constexpr int LEFT_POTI = 10;
constexpr int RIGHT_POTI= 11;
// buttons
constexpr int LEFT = 4;
constexpr int RIGHT= 3;
constexpr int UP = 13;
constexpr int DOWN = 5;
constexpr int MIDDLE = 2;

constexpr int PASSIVE_BUZZER = 12;
constexpr int BUZZER_LEDC_CHANNEL = 0;

constexpr int DFPLAYER_RX = 17;
constexpr int DFPLAYER_TX = 18;
constexpr int dfPlayerStartVolume = 2;
constexpr int VOICE_OVERRANGE_START = 2;
constexpr int VOICE_OVER_RANGE_END = 19;


constexpr int LED_PIN = 14;
constexpr int NUMBER_OF_LEDS = 8;
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB



constexpr int RIGHT_PLAYER_BUTTON = 1;
constexpr int LEFT_PLAYER_BUTTON = 40;

// this determines the debouncing time (see button.cpp)
constexpr int BUTTON_DEBOUNCE_TIME = 500;

constexpr int midoriTalkingInterval = 100;

#endif

