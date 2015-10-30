#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Lyric.h"
#include "Intro.h"
#include "End.h"
#include "Score.h"
#include "ofxDatGui.h"
#include "GuiTemplate.h"
#include "States.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void setupMenu();
        void setupSong(string songName);
        void startSongFromBeginning();
    
		void keyPressed(int key);
		void windowResized(int w, int h);
    
        int             fontSize;
        bool            songStarted = false;
        ofColor         colorTextToType;
        ofColor         colorTextTyped;
        ofColor         colorBgGradientFirst;
        ofColor         colorBgGradientSecond;
        Player          player;
        Lyric           lyric;
        Score           score;
        Intro           intro;
        End             final;
        ofTrueTypeFont	font;

private:
    void applyShader();
    void setupShader();
    void setupExitButton();
    void setupPlayAgainButton();
    void backToIntro();
    void drawPlayMessage();
    void drawPlay();
    void drawIntro();
    void drawFinished();
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
    ofxDatGuiDropdown* menu;
    ofxDatGuiButton*   exitButton;
    ofxDatGuiButton*   playAgainButton;
    states             currentState;
    ofShader           shader;
    bool               doShader;

		
};
