/*
 *  allHitAreaImage.h
 */

#pragma once

#include "ofMain.h"
#include "hitAreaImage.h"

#define MAX_NUM_IMAGE 6

class allHitAreaImage{
	
public:
	
	bool checkHit(float new_x, float new_y);
	void setPosition(float new_x, float new_y);
	void setDimensions();
    void setImage(ofImage newImage[MAX_NUM_IMAGE]);
    
	void draw(float new_x, float new_y);
	
    float imageW, imageWTest;
    float addPosX, testAddPosX;
    float test_x, test_y;
    float valueAreaIMap;
    float imageScaleAmount;
    int hitAreaImageIndex;
    
    int getDialogIndex;
    int allHitAdd;
    bool isHitOk, isImageWidthNew;
    bool isIn[MAX_NUM_IMAGE];
    string hitDialogIndex;
    string dialogIndex[MAX_NUM_IMAGE];
    hitAreaImage hitAreaImage_0[MAX_NUM_IMAGE];
    
};