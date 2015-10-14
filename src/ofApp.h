#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Lyric.h"
#include "Score.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void startSongFromBeginning();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofColor         colorTextToType;
        ofColor         colorTextTyped;
        ofColor         colorBgGradientFirst;
        ofColor         colorBgGradientSecond;
        Player          player;
        Lyric           lyric;
        Score           score;
        ofTrueTypeFont	font;
		
};
