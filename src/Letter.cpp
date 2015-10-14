#include "letter.h"

Letter::Letter(string _strLetter, ofVec2f _cursorPosition, ofColor _color){
    strLetter = _strLetter;
    //when no right typed letter was entered, the _cursorPosition has negative values
    if(_cursorPosition.x <= 0)
        startPosition = ofVec2f(0, 0);
    else
        startPosition = _cursorPosition;
    color = _color;
    endPosition = ofVec2f(startPosition.x, ofGetHeight()/2);
    direction = startPosition - endPosition;
}

void Letter::setup(){
    
}

void Letter::update(float pct){
    currentPosition = endPosition + direction * pct;
}

void Letter::draw(){
    
}




