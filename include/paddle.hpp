#ifndef PADDLE_HPP
#define PADDLE_HPP

class Paddle {

private:
    int wallDistance;
    int size;
    int upperY;
    int lowerY;

public:
    Paddle(int startX, int startY, int PaddleSize);

    void update(int controllerY);
    int getX() const;
    int getUpperY() const;
    int getLowerY() const;
};

#endif
