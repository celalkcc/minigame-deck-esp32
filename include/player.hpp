

class Player {
    private:
        int score = 0;

    public:
        Player();
        int getScore() const;
        void addToScore(int count);
        void resetScore();
};