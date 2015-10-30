#pragma once
#include "ofMain.h"

class End{
public:
    End();
    void setup(int _totalPoints);
    void update(int _actualPoints);
    void draw();
    
private:
    void defineLevels(int _totalPoints);
    ofTrueTypeFont font;
    ofColor        fontColor;
    string         currentMessage;
    string         youWinMessage = "You are a champion!";
    string         youLooseMessage = "You could have been a champion";
    string         youFailMessage = "You are definitely not a champion";
    int            youWinLevel = 0;
    int            youLooseLevel = 0;
    int            youFailLevel = 0;
    int            screenWidth;
    int            screenHeight;
    int            paddingTop;
    int            heightFont;
};
