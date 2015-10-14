#pragma once
#include "ofMain.h"

class Letter{
public:
    Letter(string strLetter, ofVec2f cursorPosition, ofColor color);
    void setup();
    void update(float point);
    void draw();
    
    string strLetter;
    ofColor color;
    ofVec2f startPosition;
    ofVec2f endPosition;
    ofVec2f currentPosition;
    ofVec2f direction;
    
    int alpha = 255;
};