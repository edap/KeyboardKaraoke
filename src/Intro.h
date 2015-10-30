#pragma once
#include "ofMain.h"

class Intro{
public:
    Intro();
    void setup();
    void update();
    void draw();
    int getEndOfTitle();
    int getPaddingTop();
    
private:
    ofImage        image;
    ofMesh         mesh;
    ofTrueTypeFont font;
    ofColor        fontColor;
    string         instruction = "Type the song as fast as you can";
    string         title = "The Freddie Mercury Karaoke Keyboard";
    int screenWidth;
    int screenHeight;
    int endOfTitle;
    int paddingTop;
    int heightFont;
};
