#include "Final.h"

Final::Final(){
    
};

void Final::setup(){
    font.load("BEBAS.ttf", 60, true, false, true, 0.4, 72);
    fontColor = ofColor(0,166,144);
    screenHeight = ofGetHeight();
    screenWidth = ofGetWidth();
    paddingTop = 70;
    currentMessage = youFailMessage;
}

void Final::update(int _actualPoints){
    if (_actualPoints >= youLooseLevel && _actualPoints < youWinLevel ) {
        currentMessage = youLooseMessage;
    }else if (_actualPoints >= youWinLevel){
        currentMessage = youWinMessage;
    }else{
        currentMessage = youFailMessage;
    };
}


void Final::draw(){
    ofSetColor(fontColor.r, fontColor.g,fontColor.b);
    float fontMessageWidth = font.stringWidth(currentMessage);
    float fontMessageHeight = font.stringHeight(currentMessage);
    font.drawStringAsShapes(currentMessage,
                            (screenWidth - fontMessageWidth)/2,
                            (screenHeight/2 + fontMessageHeight/2)
    );
}

void Final::defineLevels(int _totalPoints){
    int onePercent = _totalPoints / 100.00;
    youWinLevel = onePercent * 90;
    youLooseLevel = onePercent * 60;
    youFailLevel = onePercent * 30;
}