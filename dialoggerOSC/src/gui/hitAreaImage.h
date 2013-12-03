/*
 *  hitAreaImage.h
 */

#pragma once

#include "ofMain.h"
#include "guiText.h"

class hitAreaImage{
	
public:
	
	bool checkHit(float x, float y);
	void setPosition(float x, float y);
	void setDimensions();
    void setImage(ofImage newImage);
    
	void draw(float x, float y);
	
	ofRectangle boundingBox;
	ofRectangle myHitAreaImage;
	 
	guiText displayText;
	float offsetX, offsetY;
	float titleSpacing;
	float fontSize;
	bool readOnly;
	bool bShowText;
	int  state;
    bool isIn;
    float myImageWidth, myImageHeight;
    float imageScaleAmount;
    ofImage myImage;
};