#include "audio.hpp"
#include "conf.hpp"
#include "DFRobotDFPlayerMini.h"
#include "input.hpp"


Audio::Audio(GameOutput& output, InputState& input) 
:   output(output),
    input(input),
    dfSerial(1),
    myDFPlayer(),
    volume(dfPlayerStartVolume)
{
    ledcSetup(BUZZER_LEDC_CHANNEL, 2000, 8);
    ledcAttachPin(PASSIVE_BUZZER, BUZZER_LEDC_CHANNEL);
    dfSerial.begin(9600, SERIAL_8N1, DFPLAYER_RX, DFPLAYER_TX);
    delay(1000);
    if (!myDFPlayer.begin(dfSerial)) {
        Serial.println("DFPlayer error");
        while(true);
    }
    myDFPlayer.volume(15);
    myDFPlayer.playFolder(1,1);

}

void Audio::playTone(int freq, int duration) {
    ledcWriteTone(BUZZER_LEDC_CHANNEL, freq);
    delay(duration);
}

void Audio::colision() {
    if(output.wallColision || output.paddleColision) {
        ledcWriteTone(BUZZER_LEDC_CHANNEL, 2100);
        delay(10);
        ledcWriteTone(BUZZER_LEDC_CHANNEL, 0);
        output.wallColision = 0;
        output.paddleColision = 0;
    }
}

void Audio::someoneJustScored() {
    if (output.ballOutsidePlayingField) {
        myDFPlayer.advertise(random(VOICE_OVERRANGE_START, VOICE_OVER_RANGE_END));
        playTone(880, 80);   // A5
        playTone(660, 100);  // E5


        ledcWriteTone(BUZZER_LEDC_CHANNEL, 0); // stop
        output.ballOutsidePlayingField = 0;
    }
}

void Audio::actionButton(){
    if(output.actionButton){
        myDFPlayer.advertise(1);
        output.actionButton = 0;
    }
}

void Audio::musicControl() {
    if(input.up) {
        myDFPlayer.volumeUp();
    }
    if(input.down) {
        myDFPlayer.volumeDown();
    }
    if(input.left) {
        myDFPlayer.previous();
    }
    if(input.right) {
        myDFPlayer.next();
    }
}




