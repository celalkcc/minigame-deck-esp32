#include "display.hpp"
#include "conf.hpp"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



constexpr int OLED_RESET = -1;
constexpr int SCREEN_ADDRESS = 0x3C;

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    
myDisplay::myDisplay() {
}

void myDisplay::begin() {
    Wire.begin(); 
    if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        while(true); 
    }
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

void myDisplay::drawScore(int scoreL, int scoreR) {
    oled.setTextSize(1);
    oled.setTextColor(WHITE);

  // Left player
    oled.setCursor(30, 0);
    oled.print(scoreL);

    // Right player
    oled.setCursor(90, 0);
    oled.print(scoreR);
}

void myDisplay::drawCenterLine() {
    int centerX = SCREEN_WIDTH / 2;

    for (int y = 0; y < SCREEN_HEIGHT; y += 6) {
      oled.drawLine(centerX, y, centerX, y + 1, WHITE);
    }
}
