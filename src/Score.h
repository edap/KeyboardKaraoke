#pragma once

#include "ofMain.h"
#include "Parser.h"

class Score{
public:
    Score();
    void setup(map<int, string> textWithMilliseconds, ofColor colorTextTyped, ofColor colorTextToType);
    void onePointMore();
    void draw();
    
    int totPoints;
    int actualPoints;
    ofColor colorTextTyped;
    ofColor colorTextToType;
    ofVec2f scorePositon;
    ofVec2f paddingRightTop;
    ofTrueTypeFont font;

};


