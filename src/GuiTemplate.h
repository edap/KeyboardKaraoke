#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class GuiTemplate : public ofxDatGuiTemplate
{
public:
    GuiTemplate() {
        row.width   = 320;
        row.height  = 36;
        row.padding = 4;
        row.spacing = 0;
        row.stripeWidth = 0;
        row.color.bkgd = ofColor(250,152,154);
        row.color.label = ofColor(249,150,0);
        row.color.mouseOver = ofColor::fromHex(0xaaecda);
        row.color.mouseDown = ofColor::fromHex(0x9bd9fc);
        row.color.inputArea = ofColor::fromHex(0x303030);

        font.file   = "BEBAS.ttf";
        font.size   = 20;
        font.highlightPadding = 14;
        
        init();
    }
};
