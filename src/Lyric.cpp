#include "Lyric.h"
#include "Parser.h"

Lyric::Lyric(){
    
};

void Lyric::setup(string _filename, ofColor _colorTextToType, ofColor _colorTextTyped){
    load(_filename);
    textWithMsIterator = textWithMilliseconds.begin();
    currentSentence = "";
    lyricsBoxHeight = 300;
    font.load("bebas.ttf", 30, true, false, true, 0.4, 72);
    //font.setSpaceSize(6.0);
    //font.setLetterSpacing(1.0);
    center = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    colorTextTyped = _colorTextTyped;
    colorTextToType = _colorTextToType;
    
    
    #ifdef TARGET_OPENGLES
        shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
    #else
        if(ofIsGLProgrammableRenderer()){
            shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
        }else{
            shader.load("shaders/noise.vert", "shaders/noise.frag");
        }
    #endif
        
        doShader = true;
    };

void Lyric::update(int timeInMS){
    if (timeInMS >= textWithMsIterator->first) {
        //init next sentence
        currentSentence = textWithMsIterator->second;
        string parsed = Parser::stringWithValidChars(currentSentence, "[a-z_0-9]");
        sentenceToType = ofToLower(parsed);
        
        //empty previously typed sentence and errors
        positionReachedInCurrentSentence = 0;
        typedSentenceCorrect.str(string());
        ++textWithMsIterator;
    }
};

void Lyric::draw(){
    ofPushMatrix();
        ofTranslate(center.x, center.y);

        //sentence to read
        string toRead = currentSentence;
        ofSetColor(colorTextTyped.r, colorTextTyped.g,colorTextTyped.b);
        ofRectangle readBounds = font.getStringBoundingBox(toRead, 0, 0);
        if( doShader ){
            shader.begin();
            //we want to pass in some varrying values to animate our type / color
            shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
            shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
            
            //we also pass in the mouse position
            //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
            shader.setUniform2f("mouse", ofGetWidth()/2, ofGetHeight()/2 );
            
        }
        font.drawStringAsShapes(currentSentence, -readBounds.width/2, -readBounds.height );

    
        //typed sentence
        string strCorrect = typedSentenceCorrect.str();
        ofSetColor(colorTextToType.r, colorTextToType.g,colorTextToType.b);
        ofRectangle keyCorrectBounds = font.getStringBoundingBox(strCorrect, 0, 0);
        int strCorrectHalfWidth = + keyCorrectBounds.width/2;
        //finally draw our text
        font.drawStringAsShapes(strCorrect, -strCorrectHalfWidth, +readBounds.height);
    
        //errors
        positionCurrentSentence = ofVec2f(strCorrectHalfWidth, keyCorrectBounds.height/2);
        drawErrors();
        if( doShader ){
            shader.end();
        }
    
    ofPopMatrix();
};


bool Lyric::letterCatched(int _key){
    if (!Parser::isValidKey(_key, "[a-z_0-9]")){ return false; };
    
    string typedString(1, _key);
    if (typedString == sentenceToType.substr(positionReachedInCurrentSentence,1)){
        typedSentenceCorrect <<  typedString;
        positionReachedInCurrentSentence ++;
        return true;
    }else{
        Letter tmpLetter(typedString, positionCurrentSentence, colorTextTyped);
        wrongTyped.push_back(tmpLetter);
        return false;
    }
}

void Lyric::drawErrors(){
    vector<Letter>::iterator it;
    for(it = wrongTyped.begin(); it!= wrongTyped.end(); it++){
        it->alpha -= 2;
        if(it->alpha >= 0){
            float pct = Penner::easeInExpo(it->alpha, 0.0, 1.0, 255);
            it->update(pct);
            ofSetColor(colorTextToType.r, colorTextToType.g,colorTextToType.b, it->alpha);
            font.drawStringAsShapes(it->strLetter, it->currentPosition.x, it->currentPosition.y);
        }
        
    }
}

void Lyric::load(string filename){
    ofFile file;
    file.open(ofToDataPath(filename), ofFile::ReadWrite, false);
    string line;
    while(getline(file,line)){
        if(line.empty() == false) {
            string time = Parser::stringWithValidChars(line, "[0-9]+:[0-9]+");
            if(time.length() > 0 && time!= "00:00"){
                int min = stoi(time.substr(0,2)) * 60000;
                int secs = stoi(time.substr(3,2)) * 1000;
                int milliseconds = min + secs;
                string sentence = Parser::stringWithValidChars(line, "[^0-9_:\\[\\]]");
                textWithMilliseconds.insert(make_pair(milliseconds, sentence));
            }
        }
    }
}
