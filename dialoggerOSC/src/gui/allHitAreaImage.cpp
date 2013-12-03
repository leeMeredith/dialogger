/*
 *  allHitAreaImage.cpp
 */

#include "allHitAreaImage.h"

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

//-------------------------------------------
bool allHitAreaImage::checkHit(float new_x, float new_y){
    float x = new_x;
    float y = new_y;
    
	for (int i = 0; i < MAX_NUM_IMAGE; i++) {
        hitAreaImage_0[i].checkHit(x, y);
        isIn[i] = hitAreaImage_0[i].isIn;
        if (hitAreaImage_0[i].isIn == true) {
            isHitOk = true;
            hitAreaImageIndex = i+1;
            hitDialogIndex = dialogIndex[i];
        }
    }
    if (hitAreaImage_0[0].isIn == false &&
        hitAreaImage_0[1].isIn == false &&
        hitAreaImage_0[2].isIn == false &&
        hitAreaImage_0[3].isIn == false &&
        hitAreaImage_0[4].isIn == false &&
        hitAreaImage_0[5].isIn == false){
        isHitOk = false;
    }
}

//-----------------------------------------------
void allHitAreaImage::setPosition(float new_x, float new_y){
    float x = new_x;
    float y = new_y;
    isImageWidthNew = true;
    testAddPosX = 0;
    dialogIndex[0] =  "A";
    dialogIndex[1] =  "B";
    dialogIndex[2] =  "C";
    dialogIndex[3] =  "D";
    dialogIndex[4] =  "E";
    dialogIndex[5] =  "F";
    imageWTest = imageW = 0;
    for (int i = 0; i < MAX_NUM_IMAGE; i++) {
        hitAreaImage_0[i].setPosition(x, y);
    }
}

//------------------------------------------------
void allHitAreaImage::setDimensions(){
    for (int i = 0; i < MAX_NUM_IMAGE; i++) {
        hitAreaImage_0[i].setDimensions();
    }
}

//--------------------------------------------------------------
void allHitAreaImage::setImage(ofImage newImage[6]){
    for (int i = 0; i < MAX_NUM_IMAGE; i++) {
        imageW = newImage[i].width;
        if (imageW > imageWTest) {
            imageWTest = imageW;
            if (imageWTest*MAX_NUM_IMAGE > 650) {
                float hitArMapMax = imageWTest*MAX_NUM_IMAGE;
                float hitArMapV = hitArMapMax - 650;
                float one = 1.0;
                valueAreaIMap = ofMap(hitArMapV, 0, hitArMapMax, 0, one);
                imageScaleAmount = one - valueAreaIMap;
            }
            if (imageWTest*MAX_NUM_IMAGE <= 650) {
                valueAreaIMap = imageScaleAmount = 1.0;
            }
        }
        hitAreaImage_0[i].setImage(newImage[i]);
    }
}

//--------------------------------------------------------------
void allHitAreaImage::draw(float new_x, float new_y){
    float x = new_x;
    float y = new_y;
    
    if (isImageWidthNew == true){
        testAddPosX = 0;
        for (int i = 0; i < MAX_NUM_IMAGE; i++) {
            hitAreaImage_0[i].imageScaleAmount = imageScaleAmount;
            if (hitAreaImage_0[i].boundingBox.getWidth() > testAddPosX){
                testAddPosX = hitAreaImage_0[i].boundingBox.getWidth();
                addPosX = hitAreaImage_0[i].boundingBox.getWidth()+5;
            }
        }
        //isImageWidthNew = false;
    }

    //addPosX = hitAreaImage_0[0].boundingBox.getWidth()+5;
    for (int i = 0; i < MAX_NUM_IMAGE; i++) {
        x += addPosX;
        hitAreaImage_0[i].draw(x, y);
    }
}