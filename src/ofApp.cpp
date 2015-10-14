#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
    // use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.
    colorTextToType = ofColor(54,166,144);
    colorTextTyped = ofColor(249,64,128);
    colorBgGradientFirst = ofColor(251,172,79);
    colorBgGradientSecond = ofColor(255,207,117);
    player.setup("BohemianRhapsody.mp3");
    lyric.setup("BohemianRhapsody.lrc", colorTextTyped, colorTextToType);
    score.setup(lyric.textWithMilliseconds, colorTextTyped, colorTextToType);
}

//--------------------------------------------------------------
void ofApp::update(){
    lyric.update(player.getTime());
    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(colorBgGradientFirst, colorBgGradientSecond, OF_GRADIENT_CIRCULAR);
    player.draw();
    lyric.draw();
    score.draw();
}

void ofApp::startSongFromBeginning(){
    player.play();
}
//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    if(lyric.letterCatched(key)){
        score.onePointMore();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    startSongFromBeginning();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    setup();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
