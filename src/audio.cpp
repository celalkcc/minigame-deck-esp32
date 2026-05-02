#include "audio.hpp"
#include "conf.hpp"
Audio::Audio(GameOutput& output) 
:   output(output)
{
    ledcSetup(BUZZER_LEDC_CHANNEL, 2000, 8);
    ledcAttachPin(PASSIVE_BUZZER, BUZZER_LEDC_CHANNEL);
    volume = dfPlayerStartVolume;
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
        /*playTone(392, 180);  // G4
        playTone(370, 180);  // F#4
        playTone(330, 220);  // E4
        playTone(262, 400);  // C4

        ledcWriteTone(BUZZER_LEDC_CHANNEL, 0); // stop
        output.ballOutsidePlayingField = 0;
        */
        playTone(880, 80);   // A5
        playTone(660, 100);  // E5


        ledcWriteTone(BUZZER_LEDC_CHANNEL, 0); // stop
        output.ballOutsidePlayingField = 0;
    }
}


