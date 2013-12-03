/*
 *  dialogPlayer.h
 */

#pragma once

#include "ofMain.h"
#include "ofxSimpleSlider.h"
#include "ofxXmlSettings.h"
#include "guiText.h"
#include "recordFloat.h"
#include "recordInt.h"

class dialogPlayer{

	public:
    
        bool checkHit(float x, float y);
		void setup(int newRectX, int newRectY, string newDialogAudioDir);
		void update(int newRectX, int newRectY, string newDialogAudioDir);
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
        bool isIn;
        ofRectangle boundingBox;
    
        //xml--------------_
        ofxXmlSettings getXML;
        bool isIndex;
        string setMessageDir;
        string getMessAudioXML[6];
        string audio, play, paused, volume, speed, position;
        //-------xml-------_
        
        //guiText-----_
        guiText guiText_0;
        ofTrueTypeFont dialogPlayerFont;
        int rectX, rectY;
        int rectW, rectH;
        bool isSel;
        ofColor inRecordRectColor, selRecordRectColor;
        ofColor playColor, pausedColor, controlColor, playRecordRectColor;
        //---guiText--_
    
        
        string dialogAudioDir, dialogAudioDirTest;
        bool isPlay, isPaused, isPlayTest, isEdit;
        float dialogAudioPosition, setPos, dialogAudioSpeed, dialogAudioVolume;
        float getDialogPositionMS, newGetDialogPositionMS, getDialogPosition, getDialogSpeed, getDialogVolume;
        ofSoundPlayer  dialog;
        
        //ofxSimpleSlider-----------------_
        float slider_X, slider_Y;
        bool isSliderDraw, isSliderDrawTest;
        ofxSimpleSlider sliderPosition;
        ofxSimpleSlider sliderSpeed;
        ofxSimpleSlider sliderVolume;
        //----------ofxSimpleSlider-------_
};

