/*
 * recordFloat.cpp
 */

#include "recordFloat.h"

//--------------------------------------------------------------
void recordFloat::setup(float newRectX, float newRectY, float newScore){
	rectX = newRectX;
	rectY = newRectY;
    score = newScore;
    
    recordTextFloat_0.setup(rectX, rectY);
    rectTextColor.set(255, 0, 0);
    textColor.set(250, 100, 100);
}

//--------------------------------------------------------------
void recordFloat::update(float newRectX, float newRectY, float newScore){
    
    rectX = newRectX;
	rectY = newRectY;
    score = newScore;
    recordTextFloat_0.score = newScore;
    recordTextFloat_0.textColor(textColor);
    recordTextFloat_0.rectColor(rectTextColor);
    recordTextFloat_0.setScale(scale, scale, 0);
    recordTextFloat_0.update(rectX, rectY);
}

//--------------------------------------------------------------
void recordFloat::draw(){
	ofFill();
	recordTextFloat_0.draw();
}