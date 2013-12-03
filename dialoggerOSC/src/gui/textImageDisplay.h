/*
 *  textImageDisplay.h
 */

#pragma once

#include "ofMain.h"
#include "guiText.h"

class textImageDisplay{
	
public:
	
	void setPosition(float x, float y);
	void setDimensions();
    void setImage(ofImage newImage);
    
	void draw(float x, float y, string word, string letter);
	
	ofRectangle boundingBox;
    
    float offsetX, offsetY;
	float fontSize, imageScaleAmount;
	bool readOnly;
	bool bShowText;
    
    //guiText-----_
	guiText displayWord;
    guiText displayLetter;
	ofTrueTypeFont wordFont;
    ofTrueTypeFont letterFont;
	//---guiText--_
    
    int oldSize_w, oldSize_h;
    bool isImageBig;
    ofImage myImage;
    ofImage myImageBig;
};