#include "Player.h"

Player::Player(){
    
}

void Player::play(){
    ofPlayer.play();
}

void Player::stop(){
    // sofPlayer.stop() does not unload the sound
    // and you are checking soundIsLoaded on each update
    ofPlayer.stop();
    ofPlayer.unloadSound();
}

void Player::setup(){
    ofPlayer.setVolume(0.75f);
    ofPlayer.setMultiPlay(false);
    //ofPlayer.setSpeed(32.0);
    playerPostion = ofVec2f(0, 0);
};

void Player::update(){
    ofSoundUpdate();
};

int Player::getTime(){
    return ofPlayer.getPositionMS();
};

void Player::loadSong(string file){
    ofPlayer.load(file);
};

bool Player::songIsNotFinished(){
    return ofPlayer.getPosition() < 0.974;
};

bool Player::songIsLoaded(){
    return ofPlayer.isLoaded();
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