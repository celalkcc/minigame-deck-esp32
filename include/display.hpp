#ifndef DISPLAY_HPP
#define DISPLAY_HPP

class myDisplay {
    public:
        myDisplay();
        void begin();
        void clear();
        void drawPixel(int x, int y);
        void drawPaddle(int x, int upperY, int lowerY);
        void drawScore(int scoreL, int scoreR);
        void update();
        void drawCenterLine();
};

#endif