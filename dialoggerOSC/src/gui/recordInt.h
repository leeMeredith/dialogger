/*
 * recordInt.h
 */

#pragma once

#include "ofMain.h"
#include "recordTextInt.h"

class recordInt{
	
public:
	void setup(float newRectX, float newRectY, int newScore);
	void update(float newRectX, float newRectY, int newScore);
	void draw();
        
	float rectX, rectY;
	float rectW, rectH;
    int score;
    bool isIndex;
	string message, setDocDir;
	string getMessXML;
	string newScoreString;
	string getMenuMessXML;
	int getIndexXML;
    float scale;
    
    ofColor textColor, rectTextColor;
    recordTextInt recordTextInt_0;
	
};