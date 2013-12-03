/*
 * recordTextInt.h
 */

#pragma once

#include "ofMain.h"
#include "guiText.h"

class recordTextInt{
	
public:
	void setup(float newRectX, float newRectY);
	void update(float newRectX, float newRectY);
	void draw();
    void setScale(float x, float y, float z);
    void textColor(ofColor newScoreColor);
    void rectColor(ofColor newRectColor);
    
    //guiText-----_
	guiText guiText_0;
	ofTrueTypeFont intFont;
	//---guiText--_
	
    ofColor scoreColor;
    ofColor rectColorBG;
	float rectX, rectY;
	float rectW, rectH;
    float scaleX, scaleY, scaleZ;
    int score;
    bool isIndex;
	string message, setDocDir;
	string getMessXML;
	string newScoreString;
	string getMenuMessXML;
	int getIndexXML;
	
};