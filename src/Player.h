#pragma once
#include "ofMain.h"

class Player{

public:
    Player();
    void setup();
    void play();
    void stop();
    void update();
    void draw();
    int getTime();
    void loadSong(string file);
    bool songIsNotFinished();
    bool songIsLoaded();
    ofVec2f playerPostion;
    bool debug = false;
    ofSoundPlayer ofPlayer;
    ofTrueTypeFont	font;
    
private:
};

