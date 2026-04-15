#ifndef DISPLAY_HPP
#define DISPLAY_HPP

class oled {
    public:
        oled();
        void clear();
        void drawPixel(int x, int y);
        void drawRectangle();
        void update();
};

#endif