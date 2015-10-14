#pragma once
#include "ofMain.h"

class Player{

public:
    Player();
    void setup(string filename);
    void play();
    void update();
    void draw();
    int getTime();
    ofVec2f playerPostion;
    bool debug = false;
    ofSoundPlayer ofPlayer;
    ofTrueTypeFont	font;
    
private:
};

