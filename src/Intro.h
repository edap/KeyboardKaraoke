#pragma once
#include "ofMain.h"

class Intro{
public:
    Intro();
    void setup();
    void update(float pct);
    void draw();
    int getEndOfTitle();
    int getPaddingTop();
    int getWidthInstruction();
    
private:
    ofImage        image;
    ofMesh         mesh;
    ofTrueTypeFont font;
    ofColor        fontColor;
    string         instruction = "Type the song as fast as you can";
    string         title = "The Freddie Mercury Keyboard Karaoke";
    ofVec2f startPosition;
    ofVec2f endPosition;
    ofVec2f currentPosition;
    ofVec2f direction;
    int screenWidth;
    int screenHeight;
    int endOfTitle;
    int paddingTop;
    int heightFont;
};
