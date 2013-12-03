/*
 * recordFloat.h
 */

#pragma once

#include "ofMain.h"
#include "recordTextFloat.h"

class recordFloat{
	
public:
	void setup(float newRectX, float newRectY, float newScore);
	void update(float newRectX, float newRectY, float newScore);
	void draw();
        
	float rectX, rectY;
	float rectW, rectH;
    float score;
    bool isIndex;
	string message, setDocDir;
	string getMessXML;
	string newScoreString;
	string getMenuMessXML;
	int getIndexXML;
    float scale;
    
    ofColor textColor, rectTextColor;
    recordTextFloat recordTextFloat_0;
	
};