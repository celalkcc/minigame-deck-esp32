#ifndef BALL_HPP
#define BALL_HPP

class Ball {

private:
    int x;
    int y;
    int veloX;
    int veloY;

public:
    Ball(int startX, int startY, int velocityX, int velocityY);
    void resetToCenter();

    void update();
    
    void bounceX(int leftBounceBorder, int upperY, int lowerY);
    void bounceY(int upperBounceBorder, int lowerBounceBorder);

    int getX() const;
    int getY() const;
};

#endif
