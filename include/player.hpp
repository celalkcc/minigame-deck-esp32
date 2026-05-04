#ifndef PLAYER_HPP
#define PLAYER_HPP

// a class that manages players and their scores

class Player {
    private:
        int score = 0;

    public:
        Player();
        int getScore() const;           // getters for drawing the score (see display.cpp)
        void addToScore(int count);     // adds points to the players
        void resetScore();              // for starting a new game
};


#endif