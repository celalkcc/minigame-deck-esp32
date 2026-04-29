#ifndef BALL_HPP
#define BALL_HPP

// a class that manages ball(s)

class Ball {

private:
    // coordinates of the ball
    int x;
    int y;
    // ball speed AND direction (+/-)
    int veloX;
    int veloY;

public:
    Ball();
    void resetToCenter(); // resets the ball after someone scored

    void update(bool xFlag, bool yFlag); // updates the coordinates if the flags are true
    
    void bounceX(int leftBounceBorder, int upperY, int lowerY); // checks for bouncing off the paddles
    void bounceY(int upperBounceBorder, int lowerBounceBorder); // checks for bouncing of the walls

    // coordinate getters for printing the ball
    int getX() const; 
    int getY() const;

    // checks if the ball left the playing field (someone scored)
    bool checkScoreLeft();
    bool checkScoreRight();
};

#endif
