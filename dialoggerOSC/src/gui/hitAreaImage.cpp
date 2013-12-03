/*
 *  hitAreaImage.cpp
 */

#include "hitAreaImage.h"

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

//-------------------------------------------
bool hitAreaImage::checkHit(float x, float y){
	if(isInsideRect(x, y, boundingBox)){
		isIn = true;
	}else {
        isIn = false;
    }
}

//-----------------------------------------------
void hitAreaImage::setPosition(float x, float y){
	boundingBox.x = x;
	boundingBox.y = y;
	myHitAreaImage.x = x;
	myHitAreaImage.y = y;
}

//------------------------------------------------
void hitAreaImage::setDimensions(){
    myImageWidth = myImage.width*imageScaleAmount;
    myImageHeight = myImage.height*imageScaleAmount;
	myHitAreaImage.width       = myImageWidth;
	myHitAreaImage.height      = myImageHeight;
	boundingBox.width   = myImageWidth;
	boundingBox.height  = myImageHeight;
}

//--------------------------------------------------------------
void hitAreaImage::setImage(ofImage newImage){
	myImage = newImage;
}

//--------------------------------------------------------------
void hitAreaImage::draw(float x, float y){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CORNER); // center around the position
    if (isIn == true) {
        ofSetColor(255, 0, 0);
    }else {
        ofSetColor(255, 255, 255);
    }
    boundingBox.set(x, y, myImageWidth, myImageHeight);
    ofPushMatrix();
    ofTranslate(x, y, 0);
    ofScale(imageScaleAmount, imageScaleAmount, 1);
    myImage.draw(0, 0);
    ofPopMatrix();
}