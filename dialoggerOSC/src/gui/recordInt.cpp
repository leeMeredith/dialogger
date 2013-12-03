/*
 * recordInt.cpp
 */

#include "recordInt.h"

//--------------------------------------------------------------
void recordInt::setup(float newRectX, float newRectY, int newScore){
	rectX = newRectX;
	rectY = newRectY;
    score = newScore;
    
    recordTextInt_0.setup(rectX, rectY);
    rectTextColor.set(255, 0, 0);
    textColor.set(250, 100, 100);
}

//--------------------------------------------------------------
void recordInt::update(float newRectX, float newRectY, int newScore){
    
    rectX = newRectX;
	rectY = newRectY;
    score = newScore;
    recordTextInt_0.score = newScore;
    recordTextInt_0.textColor(textColor);
    recordTextInt_0.rectColor(rectTextColor);
    recordTextInt_0.setScale(scale, scale, 0);
    recordTextInt_0.update(rectX, rectY);
}

//--------------------------------------------------------------
void recordInt::draw(){
	ofFill();
	recordTextInt_0.draw();
}