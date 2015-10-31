#include "ofApp.h"

// --------------------------------------------------------------
void ofApp::setup(){
    // on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
    // use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.
    fontSize = 50;
    font.load("BEBAS.ttf", fontSize, true, false, true, 0.4, 72);
    ofSetEscapeQuitsApp(false); // prevent an oF app from closing on the esc-key.
    colorTextToType = ofColor(0,166,144);
    colorTextTyped = ofColor(249,150,0);
    colorBgGradientFirst = ofColor(100,0,117);
    colorBgGradientSecond = ofColor(252,0,94);
    
    intro.setup();
    player.setup();
    final.setup();
    currentState = FINISHED;
    setupMenu();
    setupExitButton();
    setupPlayAgainButton();
    setupShader();
    doShader = false;
};

void ofApp::update(){
    menu->update();
    exitButton->update();
    playAgainButton->update();
    final.update(score.actualPoints);

    if(currentState == PLAY && player.songIsLoaded()){
        if(player.songIsNotFinished()){
            lyric.update(player.getTime());
            player.update();
        }else{
            player.stop();
            currentState = FINISHED;
        }
    }
}

void ofApp::draw(){
    switch (currentState) {
        case INTRO:
            drawIntro();
            break;
        case PLAY:
            drawPlay();
            break;
        case FINISHED:
            drawFinished();
            break;
        default:
            menu->draw();
            exitButton->draw();
            break;
    }
}

// SETUP HELPERS --------------------------------------------------------------
void ofApp::setupMenu(){
    vector<string> options = {"Bohemian Rhapsody", "Radio Gaga", "Biclycle", "Under Pressure"};
    menu = new ofxDatGuiDropdown("SELECT A SONG", options);
    menu->setTemplate(new GuiTemplate());
    menu->setOpacity(0.5);
    int fromTop = intro.getPaddingTop();
    menu->setOrigin(intro.getEndOfTitle() - menu->getWidth(), fromTop);
    menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    // let's have it open by default
    //menu->expand();
}

void ofApp::setupExitButton(){
    exitButton = new ofxDatGuiButton("EXIT");
    exitButton->setTemplate(new GuiTemplate());
    exitButton->setOpacity(0.5);
    exitButton->setWidth(70);
    exitButton->onButtonEvent(this, &ofApp::onButtonEvent);
    int fromTop = intro.getPaddingTop();
    exitButton->setOrigin(
                          intro.getEndOfTitle() - intro.getWidthInstruction()/2,
                          fromTop
                          );
}

void ofApp::setupPlayAgainButton(){
    playAgainButton = new ofxDatGuiButton("AGAIN");
    playAgainButton->setTemplate(new GuiTemplate());
    playAgainButton->setOpacity(0.5);
    playAgainButton->setWidth(90);
    playAgainButton->onButtonEvent(this, &ofApp::onButtonEvent);
    int fromTop = intro.getPaddingTop();
    int xPosition = abs(exitButton->getX() - ofGetWidth()) - playAgainButton->getWidth();
    playAgainButton->setOrigin(
                               xPosition,
                               fromTop
                               );
}

void ofApp::setupSong(string song = "BohemianRhapsody"){
    player.loadSong(song + ".mp3");
    lyric.setup(song + ".lrc", fontSize, colorTextTyped, colorTextToType);
    score.setup(lyric.textWithMilliseconds, fontSize, colorTextTyped, colorTextToType);
    final.defineLevels(score.totPoints);
}

// DRAW HELPERS --------------------------------------------------------------
void ofApp::drawPlayMessage(){
    // title
    string msg = "Press Enter when you are ready to type";
    ofSetColor(colorTextTyped.r, colorTextTyped.g,colorTextTyped.b);
    float fontMessageWidth = font.stringWidth(msg);
    float fontMessageHeight = font.stringHeight(msg);
    font.drawStringAsShapes(msg,
                            (ofGetWidth()/2 - fontMessageWidth/2),
                            (ofGetHeight()/2 + fontMessageHeight/2)
                            );
}

void ofApp::drawPlay(){
    if( doShader ){
        applyShader();
    }
    ofBackgroundGradient(colorBgGradientFirst, colorBgGradientSecond, OF_GRADIENT_CIRCULAR);
    if (songStarted) {
        player.draw();
        lyric.draw();
        score.draw();
    }else{
        drawPlayMessage();
    }
    if( doShader ){
        shader.end();
    }
}

void ofApp::drawIntro(){
    if( doShader ){
        applyShader();
    }
    ofBackgroundGradient(colorBgGradientFirst, colorBgGradientSecond, OF_GRADIENT_CIRCULAR);
    intro.draw();
    if( doShader ){
        shader.end();
    }
    
    menu->draw();
    exitButton->draw();
}

void ofApp::drawFinished(){
    if( doShader ){
        applyShader();
    }
    ofBackgroundGradient(colorBgGradientFirst, colorBgGradientSecond, OF_GRADIENT_CIRCULAR);
    final.draw();
    if( doShader ){
        shader.end();
    }
    playAgainButton->draw();
    exitButton->draw();
}


// GENERAL HELPERS --------------------------------------------------------------
void ofApp::backToIntro(){
    songStarted = false;
    player.stop();
    currentState = INTRO;
    setupMenu();
}

void ofApp::startSongFromBeginning(){
    songStarted = true;
    player.play();
}

// SHADERS --------------------------------------------------------------
void ofApp::applyShader(){
    shader.begin();
    shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
    shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
}

void ofApp::setupShader(){
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
    }else{
        shader.load("shaders/noise.vert", "shaders/noise.frag");
    }
#endif
}

// EVENTS --------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    setup();
}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e){
    string selectedSong = e.target->getLabel();
    if (selectedSong == "RADIO GAGA") {
        setupSong("RadioGaga");
    };
    if (selectedSong == "BOHEMIAN RHAPSODY") {
        setupSong("BohemianRhapsody");
    };
    currentState = PLAY;
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e){
    if (e.target == exitButton){
        player.stop();
        ofExit();
    }
    if (e.target == playAgainButton){
        backToIntro();
    }
}

void ofApp::keyPressed  (int key){
    cout << key << endl;
    if(key == 27){ //pressing esc to return to the main menu
        backToIntro();
    }
    if(key == 13 && songStarted == false && currentState == PLAY){ //pressing intro to star to play
        startSongFromBeginning();
    }
    if(lyric.letterCatched(key)){
        score.onePointMore();
    }
}