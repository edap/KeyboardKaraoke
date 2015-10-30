#include "End.h"

End::End(){
    
};

void End::setup(int _totalPoints){
    defineLevels(_totalPoints);
    font.load("BEBAS.ttf", 60, true, false, true, 0.4, 72);
    fontColor = ofColor(0,166,144);
    screenHeight = ofGetHeight();
    screenWidth = ofGetWidth();
    paddingTop = 70;
    currentMessage = youFailMessage;
}

void End::update(int _actualPoints){
    cout << currentMessage << endl;
    if (_actualPoints >= youLooseLevel && _actualPoints < youWinLevel ) {
        currentMessage = youLooseMessage;
    }else if (_actualPoints >= youWinLevel){
        currentMessage = youWinMessage;
    }else{
        currentMessage = youFailMessage;
    };
}


void End::draw(){
    // title
    ofSetColor(fontColor.r, fontColor.g,fontColor.b);
    float fontMessageWidth = font.stringWidth(currentMessage);
    float fontMessageHeight = font.stringHeight(currentMessage);
    font.drawStringAsShapes(currentMessage,
                            (screenWidth - fontMessageWidth)/2,
                            (ofGetHeight()/2 + fontMessageHeight/2)
    );
}

void End::defineLevels(int _totalPoints){
    int onePercent = _totalPoints / 100;
    youWinLevel = onePercent * 90;
    youLooseLevel = onePercent * 60;
    youFailLevel = onePercent * 30;
    cout << youWinLevel << endl;
    cout << youLooseLevel << endl;
    cout << youFailLevel << endl;
}