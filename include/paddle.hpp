#ifndef PADDLE_HPP
#define PADDLE_HPP


// a class for pong game style paddles
class Paddle {

private:
    // coordinates and size
    int wallDistance;
    int size;
    int upperY;
    int lowerY;

public:
    Paddle(int startX, int startY, int PaddleSize);

    void update(int controllerY); // takes already mapped values from controller class
    int getX() const; // getter for border check (see ball.cpp)
    int getUpperY() const; // getter for border check
    int getLowerY() const; // getter for border check
};

#endif
