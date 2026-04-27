#include "player.hpp"

Player::Player(){
    score = 0;
}

int Player::getScore() const {
    return score;
}

void Player::addToScore(int count){
    score += count;
}

void Player::resetScore(){
    score = 0;
}