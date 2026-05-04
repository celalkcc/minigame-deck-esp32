#ifndef OUTPUT_HPP
#define OUTPUT_HPP


// a structure for games to communicate to hardware

struct GameOutput {
    bool wallColision;                  // bumping into walls      
    bool paddleColision;                // bumping into players
    bool ballOutsidePlayingField;       // someone scored
    unsigned scoreLeft;                 // for neopixel
    unsigned scoreRight;                // also for neopixel
};



#endif