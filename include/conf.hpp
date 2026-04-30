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
constexpr int PADDLE_SIZE= 12;
constexpr int WALL_DISTANCE = 10;

// peripherals and their pins
constexpr int LEFT_POTI = 10;
constexpr int RIGHT_POTI= 11;
// buttons
constexpr int LEFT = 4;
constexpr int RIGHT= 3;
constexpr int UP = 5;
constexpr int DOWN = 6;
constexpr int MIDDLE = 2;

constexpr int PASSIVE_BUZZER = 12;

constexpr int DFPLAYER_RX = 17;
constexpr int DFPLAYER_TX = 18;


constexpr int RIGHT_PLAYER_BUTTON = 1;
constexpr int LEFT_PLAYER_BUTTON = 7;

// this determines the debouncing time (see button.cpp)
constexpr int BUTTON_DEBOUNCE_TIME = 200;

#endif

