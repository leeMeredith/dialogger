/*
 *  guiMessXML.h
 */

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "guiText.h"
#include "recordFloat.h"
#include "recordInt.h"

class guiMessXML{
	
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
    //-----------cursor------------_
    
	//guiText-----_
	guiText guiText_0;
	ofTrueTypeFont messFont;
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
    bool isFileEnter, isDateTimeEnter, isArtistEnter, isSetEnter, isAudioEnter, isFormatEnter, isSideEnter, isRecStringEnter, isRecDialogEnter, isImageEnter;
    ofColor inRecordRectColor, selRecordRectColor;
    ofColor playRecordColor, recRecordColor;
    ofColor playRecordRectColor, recRecordRectColor;
    ofColor enterColor;
    
    string getMessRecordXMLTag;
    string getMessRecordXML[10];
    string getMessRecordXMLTags[10];
    string file, dateTime, artist, set, audio, format, side, recString, recDialog, image;
    
    //recordFloat-----------------------_
    //recordFloat recordFloat_0;
    //---------recordFloat--------------_
    
};