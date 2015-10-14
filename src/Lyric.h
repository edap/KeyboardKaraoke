#pragma once
#include "ofMain.h"
#include "Parser.h"
#include "Letter.h"
#include "penner.h"

class Lyric{
public:
    Lyric();
    void setup(string filename, ofColor colorTextToType, ofColor colorTextTyped);
    void update(int time);
    void draw();

    bool letterCatched(int key);
    
    string currentSentence;
    string sentenceToType;
    stringstream typedSentenceCorrect;
    
    int positionReachedInCurrentSentence;
    ofVec2f positionCurrentSentence;
    map<int, string> textWithMilliseconds;
    map<int,string>::iterator textWithMsIterator;
    
    vector<Letter> wrongTyped;
    
    int lyricsBoxHeight;
    ofVec2f center;
    ofColor colorTextToType;
    ofColor colorTextTyped;
    
private:
    void load(string filename);
    void drawErrors();
    ofTrueTypeFont	font;
};
