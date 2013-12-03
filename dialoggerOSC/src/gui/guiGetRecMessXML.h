/*
 *  guiGetRecMessXML.h
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "guiText.h"
#include "recordFloat.h"
#include "recordInt.h"

class guiGetRecMessXML{
	
public:
    bool checkHit(float x, float y);
	void setup(float newRectX, float newRectY, string newSetDocDir);
	void update(float newRectX, float newRectY, string newSetDocDir);
	void draw();
	
    bool isIn;
    ofRectangle boundingBox;
    
	//guiText-----_
	guiText guiText_0;
	ofTrueTypeFont recFont;
	//---guiText--_
	
	float rectX, rectY;
	float rectW, rectH;
	
	int messIndex;
	
	//xml--------------_
	ofxXmlSettings getXML;
	bool isIndex;
	string message, setDocDir;
	//-------xml-------_
    
    //recordInt-----------------------_
    recordInt recordSize;
    recordInt phraseSize;
    recordInt wordSize;
    recordInt endRecSize;
    int recordValSize, phraseValSize, wordValSize, endRecValSize;
    //------------recordInt-----------_
    
    //recordFloat-----------------------_
    ofColor inComingFloatColor;
    ofColor playRecordFloatColor, recRecordFloatColor;
    ofColor playRecordFloatRectColor, recRecordFloatRectColor;
    ofColor playRecordColor, recRecordColor;
    ofColor playRecordRectColor, recRecordRectColor;
    string getMessGetRecordXML[6];
    float recordVal, phraseVal, wordVal, endRecVal;
    recordFloat record;
    recordFloat phrase;
    recordFloat word;
    recordFloat endRec;
    ofColor phraseFloatColor;
    ofColor wordFloatColor;
    ofColor endRecFloatColor;
    //---------recordFloat--------------_
    
};