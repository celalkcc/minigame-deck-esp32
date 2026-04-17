#include "display.hpp"
#include "conf.hpp"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


constexpr int OLED_RESET = -1;
constexpr int SCREEN_ADDRESS = 0X3c;

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

myDisplay::myDisplay() {
    oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); 
    oled.clearDisplay();
}

void myDisplay::clear() {
    oled.clearDisplay();
}

void myDisplay::drawPixel(int x, int y) {
    oled.drawPixel(x, y, WHITE);
}

void myDisplay::update() {
    oled.display();
}

void myDisplay::drawPaddle(int x, int upperY, int lowerY) {
    oled.drawLine(x, upperY, x, lowerY, WHITE);
}


