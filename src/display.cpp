#include "display.hpp"
#include "conf.hpp"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


constexpr int OLED_RESET = -1;
constexpr int SCREEN_ADDRESS = 0X3c;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

myDisplay::myDisplay() {
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); 
    display.clearDisplay();
}

void myDisplay::clear() {
    display.clearDisplay();
}

void myDisplay::drawPixel(int x, int y) {
    display.drawPixel(x, y, WHITE);
}

void myDisplay::update() {
    display.display();
}

void myDisplay::drawRectangle(int x, int y, int height, int width, int color) {
    display.drawRect(x, y, width, height, WHITE);
}


