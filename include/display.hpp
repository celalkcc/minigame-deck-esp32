#ifndef DISPLAY_HPP
#define DISPLAY_HPP

// display interface

class myDisplay {
    public:
        myDisplay();
        void begin();                                   // initialize display
        void clear();
        void drawPixel(int x, int y);
        void drawPaddle(int x, int upperY, int lowerY); //draws a line as a paddle
        void drawScore(int scoreL, int scoreR);         // draws two numbers to the playing field
        void update();                                  // displays the changes
        void drawCenterLine();                          // marks the middle of playing field
        void drawBitmap();                              // drawing images
};

#endif