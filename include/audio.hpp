#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <Arduino.h>
#include "conf.hpp"
#include "output.hpp"
#include "DFRobotDFPlayerMini.h"
#include "input.hpp"

class Audio{
    private:
        GameOutput& output;
        InputState& input;
        HardwareSerial dfSerial;
        DFRobotDFPlayerMini myDFPlayer;
        unsigned volume;
        int buzzerTimer;
        unsigned currentSong;
    public:
        Audio(GameOutput& output, InputState& input);              // reads the game state from output abstraction layer
        void playTone(int freq, int duration);  // used by other funcitons to play melodys
        void colision();                        // small blip
        void someoneJustScored();                  // plays a downgoing melody because someone lost a point
        void actionButton();
        void musicControl();
};



#endif