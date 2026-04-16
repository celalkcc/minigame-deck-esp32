#ifndef DISPLAY_HPP
#define DISPLAY_HPP

class myDisplay {
    public:
        myDisplay();
        void clear();
        void drawPixel(int x, int y);
        void drawRectangle(int x, int y, int height, int width, int color);
        void update();
};

#endif