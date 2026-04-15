#include "display.hpp"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

constexpr int SCREEN_WIDTH = 128;
constexpr int SCREEN_HEIGHT = 64;
constexpr int OLED_RESET = -1;
constexpr int SCREEN_ADDRESS = 0X3c;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

oled::oled() {
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); 
    display.clearDisplay();
}

void oled::clear() {
    display.clearDisplay();
}

void oled::drawPixel(int x, int y) {
    display.drawPixel(x, y, WHITE);
}

void oled::update() {
    display.display();
}

void oled::drawRectangle() {

}

