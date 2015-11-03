#include "Intro.h"

Intro::Intro(){

};

void Intro::setup(){
    font.load("BEBAS.ttf", 60, true, false, true, 0.4, 72);
    font.setSpaceSize(25.0);
    fontColor = ofColor(0,166,144);
    screenHeight = ofGetHeight();
    screenWidth = ofGetWidth();
    paddingTop = 100;
    heightFont = font.stringHeight(title);
    endOfTitle = (screenWidth -font.stringWidth(title))/2 + font.stringWidth(title);
    //img
    bool succ = true;
    succ = image.load("freddie.png");
    if (!succ) {
        cerr << "loading image failed ...\n";
        
    }
    //img position
    currentPosition = ofVec2f(screenWidth - (image.getWidth()/2), 0);
    endPosition = ofVec2f(screenWidth - (image.getWidth()/2), screenHeight);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    int w = image.getWidth();
    int h = image.getHeight();
    int y_offset = screenHeight - h; //position the img to bottom - center
    int x_offset = (screenWidth - w) / 2;
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            ofVec3f pos((x + x_offset), (y + y_offset), 0.0);
            mesh.addVertex(pos);
            mesh.addColor(c);
        }
    }
}

void Intro::update(float pct){
    currentPosition = endPosition + direction * pct;
}

int Intro::getEndOfTitle(){
    return endOfTitle;
}

int Intro::getWidthInstruction(){
   return font.stringWidth(instruction);
}

int Intro::getPaddingTop(){
    return (heightFont +  heightFont/2 + paddingTop);
}

void Intro::draw(){
    //freddie
    mesh.draw();

    // title
    ofSetColor(fontColor.r, fontColor.g,fontColor.b);
    float fontTitleWidth = font.stringWidth(title);
    font.drawStringAsShapes(title, (screenWidth - fontTitleWidth)/2, paddingTop );

    // instructions, with font scaled 50%
    ofPushMatrix();
        float fontInstructionWidth = font.stringWidth(instruction);
        ofScale(0.5, 0.5, 1);
        ofSetColor(fontColor.r, fontColor.g,fontColor.b);
        font.drawStringAsShapes(instruction,
                                (endOfTitle*2 - fontInstructionWidth),
                                (heightFont*2 + paddingTop*2)
        );
    ofPopMatrix();
}