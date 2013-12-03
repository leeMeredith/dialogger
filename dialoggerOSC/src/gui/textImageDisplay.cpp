/*
 *  textImageDisplay.cpp
 */

#include "textImageDisplay.h"

//-----------------------------------------------
void textImageDisplay::setPosition(float x, float y){
	boundingBox.x = x;
	boundingBox.y = y;
	isImageBig = false;
    wordFont.loadFont("mono.ttf", 46, false);
	displayWord.setup();
	displayWord.setFont(wordFont);
	displayWord.setText("cat");
    
    letterFont.loadFont("mono.ttf", 92, false);
    displayLetter.setup();
	displayLetter.setFont(letterFont);
	displayLetter.setText("c");
}

//------------------------------------------------
void textImageDisplay::setDimensions(){
	boundingBox.width   = myImage.width*imageScaleAmount;
	boundingBox.height  = myImage.height*imageScaleAmount;
}

//--------------------------------------------------------------
void textImageDisplay::setImage(ofImage newImage){
    
    if (isImageBig == false){
        if (newImage.width > 150) {
            float hitArMapMax = newImage.width;
            float hitArMapV = hitArMapMax - 150;
            float one = 1.0;
            float valueAreaIMap;
            valueAreaIMap = ofMap(hitArMapV, 0, hitArMapMax, 0, one);
            imageScaleAmount = one - valueAreaIMap;
        }else {
            imageScaleAmount = 1.0;
        }
    }else {
        int testSize = 325;
        if (newImage.width > testSize) {
            float hitArMapMax = newImage.width;
            float hitArMapV = hitArMapMax - testSize;
            float one = 1.0;
            float valueAreaIMap;
            valueAreaIMap = ofMap(hitArMapV, 0, hitArMapMax, 0, one);
            imageScaleAmount = one - valueAreaIMap;
        }
        if (newImage.width <= testSize){
            float hitArMapMax = newImage.width;
            float hitArMapV = hitArMapMax - testSize;
            float one = 1.0;
            float valueAreaIMap;
            valueAreaIMap = ofMap(hitArMapV, 0, hitArMapMax, 0, one);
            imageScaleAmount = one - valueAreaIMap;
        }
    }
    
	myImage = newImage;
    if (isImageBig == true)myImageBig = newImage;
//    oldSize_w = myImage.width;
//    oldSize_h = myImage.height;
//    oldSize_w = oldSize_w-25;
//    oldSize_h = oldSize_h-40;
}

//--------------------------------------------------------------
void textImageDisplay::draw(float x, float y, string word, string letter){
    ofFill();
    ofSetColor(255, 0, 100);
    //myImage.resize(oldSize_w*2, oldSize_h*2);
    
    displayWord.renderString(word, x, y);
    if (isImageBig == false)displayLetter.renderString(letter, x+myImage.width*imageScaleAmount+15, y+115);
    if (isImageBig == true)displayLetter.renderString(letter, x, y+115);

    ofSetColor(255, 255, 255);
	boundingBox.set(x, y, myImage.width*imageScaleAmount, myImage.height*imageScaleAmount);
    if (isImageBig == false){
        ofEnableAlphaBlending();
        //ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
        ofPushMatrix();
        ofTranslate(x, y+12, 0);
        ofScale(imageScaleAmount, imageScaleAmount, 1);
        myImage.draw(0, 0);
        ofPopMatrix();
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDisableAlphaBlending();
    }
    
    if (isImageBig == true){
        ofEnableAlphaBlending();
        //ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
        ofPushMatrix();
        ofTranslate(ofGetWidth()-470, ofGetHeight()-480, 0);
        ofScale(imageScaleAmount, imageScaleAmount, 1);
        myImageBig.draw(0, 0);
        ofPopMatrix();	
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDisableAlphaBlending();
    }
}