/*
 *  guiOscMessXML.h
 */

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "guiText.h"
#include "recordFloat.h"
#include "recordInt.h"

class guiOscMessXML{
	
public:
    
    bool checkHit(float x, float y);
	void setup(float newRectX, float newRectY, string newSetDocDir);
	void update(float newRectX, float newRectY, string newSetDocDir);
	void draw();
	
    bool isIn, isDelete;
    ofRectangle boundingBox;
    
    //cursor-----------------------_
    float cursorRightLeft, stringIndexRightLeft, cursorCounter;    
    bool isRight, isLeft, testCursorCounter;
    float newCursor_X, newCursor_Y;
    float cursor_X, cursor_Y;
    bool isSetCursor_X, isSetCursorAtSizeOne_X, isSetCursorAtSizeZero_X, isSetCursorAtSize_X;
    float cursor_W, cursor_H;
    bool isAddToStringIndex, isReSetAddToStringIndex, isStringSizeAtZero;
    int addToStringIndex, newStringIndexRightLeft;
    int stringLength, stringSize;
    ofRectangle cursor;
    //----------cursor-------------_
    
	//guiText-----_
	guiText guiText_0;
	ofTrueTypeFont oscFont;
	//---guiText--_
    
	float rectX, rectY;
	float rectW, rectH;
	
	int messIndex;
	int maxNumInList;
    
	//xml--------------_
	ofxXmlSettings getXML;
	bool isIndex;
	string message, setDocDir;
	//-------xml-------_
    
    int recIndex_Y, recIndexTest;
    bool isUpList, isDownList;
    
    bool isSel, isSetAllEnter;
    bool isPortEnter, isHostEnter, isAddrasEnter;
    ofColor inRecordRectColor, selRecordRectColor;
    ofColor playRecordColor, recRecordColor;
    ofColor playRecordRectColor, recRecordRectColor;
    ofColor enterColor;
    
    string getMessRecordXMLTag;
    string getMessRecordXML[4];
    string getMessRecordXMLTags[4];
    string port, host, addras, inVal;
    
    //recordFloat-----------------------_
    //recordFloat recordFloat_0;
    //---------recordFloat--------------_
    
    
};