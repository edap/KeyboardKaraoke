#include "Player.h"

Player::Player(){
    
}

void Player::play(){
    ofPlayer.play();
}

void Player::setup(string file){
    ofPlayer.load(file);
    ofPlayer.setVolume(0.75f);
    ofPlayer.setMultiPlay(false);
    playerPostion = ofVec2f(0, 0);
};

void Player::update(){
    ofSoundUpdate();
};

int Player::getTime(){
    return ofPlayer.getPositionMS();
};

void Player::draw(){
    if(debug){
        ofSetColor(100, 200, 100);
        ofDrawRectangle(playerPostion.x,playerPostion.y,ofGetWidth(),100);
        ofSetColor(0, 0, 0);

        string tempStr = "click and drag\npct done: "+
            ofToString(ofPlayer.getPositionMS())+"\nspeed: "
            +ofToString(ofPlayer.getSpeed());
        ofDrawBitmapString(tempStr, 10,10);
    }
};