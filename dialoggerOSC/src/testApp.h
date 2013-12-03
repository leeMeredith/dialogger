#pragma once

#include "dialogger.h"

#include "guiText.h"
#include "recordInt.h"

class testApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    void keyReleased(int key);
    
    int rWR, rWG, rWB;
    int rLR, rLG, rLB;
    int rFIR, rFIG, rFIB;
    guiText word;
    guiText letter;
    guiText nameOfFileImage;
	ofTrueTypeFont wordFont;
    ofTrueTypeFont letterFont;
    ofTrueTypeFont fileImageFont;
    
    //recordInt-----------------------_
    recordInt currentDialogImageValDisplay;
    int currentDialogImageVal;
    //------------recordInt-----------_
    
    //dialogger----------------------_
    dialogger dialogger_0;
    //-----------dialogger-----------_
    
    bool isDialoggerGuiDraw, isFullscreen;
};

