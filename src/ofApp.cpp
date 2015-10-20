#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
    // use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.
    colorTextToType = ofColor(54,166,144);
    colorTextTyped = ofColor(249,64,128);
    colorBgGradientFirst = ofColor(255,207,117);
    colorBgGradientSecond = ofColor(252,116,94);
    player.setup();
    currentState = INTRO;
    setupMenu();
}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e){
    setupSong();
    currentState = PLAY;
}

//--------------------------------------------------------------
void ofApp::update(){
    menu->update();

    if(currentState == PLAY && player.songIsLoaded()){
        if(player.songIsNotFinished()){
            lyric.update(player.getTime());
            player.update();
        }else{
            player.stop();
            currentState == FINISHED;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(colorBgGradientFirst, colorBgGradientSecond, OF_GRADIENT_CIRCULAR);
    switch (currentState) {
        case INTRO:
            menu->draw();
            break;
        case PLAY:
            player.draw();
            lyric.draw();
            score.draw();
            break;
        case FINISHED:
            showFinalMenu();
            break;
        default:
            menu->draw();
            break;
    }
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

void ofApp::setupMenu(){
    vector<string> options = {"BohemianRhapsody", "RadioGaga", "Biclycle"};

    menu = new ofxDatGuiDropdown("SELECT A COLOR", options);
    menu->setOrigin(ofGetWidth()/2 - menu->getWidth()/2, ofGetHeight()/2 - menu->getHeight()/2 - 100);
    menu->setOrigin(ofGetWidth()/2 - menu->getWidth()/2, ofGetHeight()/2 - menu->getHeight()/2 - 100);

    // let's set the stripe of each option to its respective color //
    //for (int i=0; i<menu->size(); i++) menu->getChildAt(i)->setStripeColor(colors[i]);

    menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    // finally let's have it open by default //
    menu->expand();
}

void ofApp::setupSong(){
    // http://en.cppreference.com/w/cpp/language/default_arguments
    player.loadSong("BohemianRhapsody.mp3");
    lyric.setup("BohemianRhapsody.lrc", colorTextTyped, colorTextToType);
    score.setup(lyric.textWithMilliseconds, colorTextTyped, colorTextToType);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

void ofApp::showFinalMenu(){
    //show a message with 2 button
    // one for exit and one to go back to intro and choose another song
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
