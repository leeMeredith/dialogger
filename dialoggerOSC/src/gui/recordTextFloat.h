/*
 * recordTextFloat.h
 */

#pragma once

#include "ofMain.h"
#include "guiText.h"

class recordTextFloat{
	
public:
	void setup(float newRectX, float newRectY);
	void update(float newRectX, float newRectY);
	void draw();
    void setScale(float x, float y, float z);
    void textColor(ofColor newScoreColor);
    void rectColor(ofColor newRectColor);
    
    //guiText-----_
	guiText guiText_0;
	ofTrueTypeFont floatFont;
	//---guiText--_
	
    ofColor scoreColor;
    ofColor rectColorBG;
	float rectX, rectY;
	float rectW, rectH;
    float scaleX, scaleY, scaleZ;
    float score;
    bool isIndex;
	string message, setDocDir;
	string getMessXML;
	string newScoreString;
	string getMenuMessXML;
	int getIndexXML;
	
};