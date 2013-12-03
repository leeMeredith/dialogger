/*
 *  guiOscMessXML.cpp
 */

#include "guiOscMessXML.h"

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

//-------------------------------------------
bool guiOscMessXML::checkHit(float x, float y){
	if(isInsideRect(x, y, boundingBox)){
		isIn = true;
	}else {
        isIn = false;
    }
}

//--------------------------------------------------------------
void guiOscMessXML::setup(float newRectX, float newRectY, string newSetDocDir){
	
    boundingBox.set(rectX-15, rectY-128, rectW+13, rectH*6-3);
    
	setDocDir = newSetDocDir;//message_presets.xml;
	message = "message_presets.xml";
	if( getXML.loadFile(setDocDir) ){
		cout << "message_presets.xml loaded from documents folder!" << endl;
	}else if( getXML.loadFile("record/message/message_presets.xml") ){
		cout << "message_presets.xml loaded from data folder!" << endl;
	}else{
		cout << "unable to load message_presets.xml check data/ folder" << endl;
	}	
	/*
	getXML.pushTag("FLAME");			
	for(int n = 0; n < getXML.getNumTags("message"); n++){		
		getXML.getValue("message", "undefined", n);
	}
	getXML.popTag();
	
	//getIndexXML[0] = 1;
	for (int i = 0; i < 6; i++) {
		char tempGetIndexXMLString[255];
		sprintf(tempGetIndexXMLString,"%i", (int)getIndexXML[i]);
		newGetIndexXMLString[i] = tempGetIndexXMLString;
	}
     dateTime = "this";
     artist = "this"; 
     set = "this"; 
     format = "this"; 
     side = "this"; 
     recString = "this"; 
     recDialog = "this";
    //*/
    
    recIndex_Y = maxNumInList = 3;
    getMessRecordXML[0] = getXML.getValue("OSC:title" , "XML?");
    getMessRecordXML[1] = getXML.getValue("OSC:message_0" , "XML?");
	getMessRecordXML[2] = getXML.getValue("OSC:message_1" , "XML?");
	getMessRecordXML[3] = getXML.getValue("OSC:message_2" , "XML?");
	    
    //getMessRecordXMLTags[0] = getMessRecordXMLTag = getXML.getValue("REALTAGRECORD:message_0" , "XML?");
	//getMessRecordXMLTags[1] = getXML.getValue("REALTAGRECORD:message_1" , "XML?");
	//getMessRecordXMLTags[2] = getXML.getValue("REALTAGRECORD:message_2" , "XML?");
    
	rectX = newRectX;
	rectY = newRectY;
	oscFont.loadFont("mono.ttf", 15, false);
	guiText_0.setup();
	guiText_0.setFont(oscFont);
	guiText_0.setText(getMessRecordXML[3]);
	rectW = guiText_0.getTextWidth();
	rectH = guiText_0.getTextHeight();
    
    cursor_X = rectX-10;
    cursor_Y = rectY-110;
    cursor_W = 1;
	cursor_H = guiText_0.getTextHeight();
    
    cursor.set(cursor_X, cursor_Y, cursor_W, cursor_H);
    
	
	isIndex = true;
    isSel = false;
    isSetAllEnter = isPortEnter = isHostEnter = isAddrasEnter = false;
    playRecordRectColor.set(175, 0, 153, 150);
    recRecordRectColor.set(100, 100, 100, 255);
    playRecordColor.set(170, 185, 0, 255);
    recRecordColor.set(255, 255, 255);
    inRecordRectColor.set(255, 255, 255);
    selRecordRectColor.set(255, 255, 255);
    enterColor.set(255, 0, 0, 255);
    
    cursorCounter = 0;
    newCursor_X = 0;
    cursor_Y = rectY-110;
    stringSize = 0;
    
    cursorCounter = ofGetSeconds();
    testCursorCounter = true;
    
    isDelete = false;
}

//--------------------------------------------------------------
void guiOscMessXML::update(float newRectX, float newRectY, string newSetDocDir){
	rectX = newRectX;
	rectY = newRectY;
    
    boundingBox.set(rectX-15, rectY-128, rectW+13, rectH*6-3);
    
	/*
	//getIndexXML[0] = 1;
	if (isIndex == true) {
		for (int i = 0; i < 6; i++) {
			char tempGetIndexXMLString[255];
			sprintf(tempGetIndexXMLString,"%i", (int)getIndexXML[i]);
			newGetIndexXMLString[i] = tempGetIndexXMLString;
		}
		//isIndex = false;
	}
    
    
    getMessRecordXML[0] = getXML.getValue("RECORD:message_0" , "XML?");
	getMessRecordXML[1] = getXML.getValue("RECORD:message_1" , "XML?");
	getMessRecordXML[2] = getXML.getValue("RECORD:message_2" , "XML?");
	getMessRecordXML[3] = getXML.getValue("RECORD:message_3" , "XML?");
	getMessRecordXML[4] = getXML.getValue("RECORD:message_4" , "XML?");
	getMessRecordXML[5] = getXML.getValue("RECORD:message_5" , "XML?");
   	getMessRecordXML[6] = getXML.getValue("RECORD:message_6" , "XML?");
    getMessRecordXML[7] = getXML.getValue("RECORD:message_7" , "XML?");
    getMessRecordXML[8] = getXML.getValue("RECORD:message_8" , "XML?");
    getMessRecordXML[9] = getXML.getValue("RECORD:message_9" , "XML?");
    */
    
    
    if (recIndex_Y != maxNumInList) {
        if (cursorCounter != ofGetSeconds()) {
            testCursorCounter = !testCursorCounter;
            cursorCounter = ofGetSeconds();
        }
    }
    
    int rectXW = rectX+rectW+5;
    
    if (recIndex_Y == maxNumInList) {
        isSetAllEnter = true;
        newCursor_X = rectXW;
        cursor_Y = rectY-92;
        stringSize = port.size();
    }
    
    if (recIndex_Y == 0) {
        newCursor_X = rectXW;
        cursor_Y = rectY-92;
        stringSize = port.size();
    }
    
    if (recIndex_Y == 1) {
        newCursor_X = rectXW;
        cursor_Y = rectY-74;
        stringSize = host.size();
    }
    
    if (recIndex_Y == 2) {
        newCursor_X = rectXW;
        cursor_Y = rectY-56;
        stringSize = addras.size();
    }

    
    if (isUpList == true) {
        recIndex_Y++;
        testCursorCounter = true;
        int rectXW = rectX+rectW+5;
        if (recIndex_Y == 0) {
            newCursor_X = rectXW;
            cursor_Y = rectY-92;
            stringSize = port.size();
        }
        
        if (recIndex_Y == 1) {
            newCursor_X = rectXW;
            cursor_Y = rectY-74;
            stringSize = host.size();
        }
        
        if (recIndex_Y == 2) {
            newCursor_X = rectXW;
            cursor_Y = rectY-56;
            stringSize = addras.size();
        }
        
        if (recIndex_Y > maxNumInList) {
            recIndex_Y = 0;
        }
        /*
        if (recIndex_Y == maxNumInList){
            getMessRecordXMLTag = "";
        }else {
            getMessRecordXMLTag = getMessRecordXMLTags[recIndex_Y];
        }
         */
        cursor_X = newCursor_X + ((float)guiText_0.fontSize-1) * stringSize;
        cursorRightLeft = 0;
        stringIndexRightLeft = stringSize-1;
        isUpList = false;
    }
    if (isDownList == true) {
        recIndex_Y--;
        testCursorCounter = true;
        int rectXW = rectX+rectW+5;
        if (recIndex_Y == 0) {
            newCursor_X = rectXW;
            cursor_Y = rectY-92;
            stringSize = port.size();
        }
        
        if (recIndex_Y == 1) {
            newCursor_X = rectXW;
            cursor_Y = rectY-74;
            stringSize = host.size();
        }
        
        if (recIndex_Y == 2) {
            newCursor_X = rectXW;
            cursor_Y = rectY-56;
            stringSize = addras.size();
        }
        
        if (recIndex_Y < 0) {
            recIndex_Y = maxNumInList;
        }
        /*
        if (recIndex_Y == maxNumInList){
            getMessRecordXMLTag = "";
        }else {
            getMessRecordXMLTag = getMessRecordXMLTags[recIndex_Y];
        }
         */ 
        cursor_X = newCursor_X + ((float)guiText_0.fontSize-1) * stringSize;
        cursorRightLeft = 0;
        stringIndexRightLeft = stringSize-1;
        isDownList = false;
    }
    
    if (isLeft == true) {
        cursorRightLeft++;
        stringIndexRightLeft--;
        
        testCursorCounter = true;
        
        if (cursorRightLeft >= stringSize) {
            cursorRightLeft = stringSize-1;
            //stringIndexRightLeft = stringSize-1;
        }
        if (stringIndexRightLeft <= 0) {
            stringIndexRightLeft = 0;
        }
        
        isLeft = false;
        cout << "cursor " << cursorRightLeft << " stringIndex " << stringIndexRightLeft << endl;
    }
    if (isRight == true) {
        cursorRightLeft--;
        stringIndexRightLeft++;
        
        testCursorCounter = true;
        
        if (cursorRightLeft < 0) {
            cursorRightLeft = stringSize-1;
            //stringIndexRightLeft = 0;
        }
        if (stringIndexRightLeft >= stringSize) {
            stringIndexRightLeft = 0;
        }
        
        isRight = false;
        cout << "cursor " << cursorRightLeft << " stringIndex " << stringIndexRightLeft << endl;
    }
    
    if (cursorRightLeft >= stringSize) {
        cursorRightLeft = stringSize-1;
        //stringIndexRightLeft = stringSize-1;
    }
    if (stringIndexRightLeft <= 0) {
        stringIndexRightLeft = 0;
    }
    
    if (cursorRightLeft < 0) {
        cursorRightLeft = stringSize-1;
        //stringIndexRightLeft = 0;
    }
    if (stringIndexRightLeft >= stringSize) {
        stringIndexRightLeft = 0;
    }
    
    if (isSetAllEnter == true) {
        isPortEnter = isHostEnter = isAddrasEnter = false;
        isSetAllEnter = false;
    }
}

//--------------------------------------------------------------
void guiOscMessXML::draw(){
	ofFill();
    ofEnableAlphaBlending();
    
    ofSetColor(playRecordRectColor);
    boundingBox.set(rectX-15, rectY-128, rectW+13, rectH*6-3);
	ofRect(rectX-15, rectY-128, rectW+13, rectH*6-3);
    
    if (recIndex_Y >= maxNumInList) {
        ofSetColor(playRecordRectColor);
    }else {
        ofSetColor(recRecordRectColor);
    }
    
    if (isIn == true) {
        ofSetColor(inRecordRectColor);
    }
    if (isSel == true) {
        ofSetColor(selRecordRectColor);
    }
    ofNoFill();
    ofRect(rectX-15, rectY-128, rectW+13, rectH*6-3);
    int rectXW = rectX+rectW+5;
    
    ofFill();
    ofSetColor(playRecordColor);
    guiText_0.renderString(getMessRecordXML[0], rectX-10, rectY-110);
    
    if (recIndex_Y == 0) {
        if (isPortEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isPortEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(port, rectXW, rectY-92);
    guiText_0.renderString(getMessRecordXML[1], rectX-10, rectY-92);
    
    if (recIndex_Y == 1) {
        if (isHostEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isHostEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(host, rectXW, rectY-74);
    guiText_0.renderString(getMessRecordXML[2], rectX-10, rectY-74);
    
    if (recIndex_Y == 2) {
        if (isAddrasEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isAddrasEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(addras, rectXW, rectY-56);
	guiText_0.renderString(getMessRecordXML[3], rectX-10, rectY-56);
    
    if (recIndex_Y != maxNumInList) {
        if (testCursorCounter) {
            ofSetColor(255,255,255,255);
        }else {
            ofSetColor(255,255,255,100);
        }
        if (cursorRightLeft >= 0){
            if (stringSize >= 0) {
                if (cursorRightLeft <= stringSize-1) {
                    cursor_X = (newCursor_X + ((float)guiText_0.fontSize-1) * stringSize-(((float)guiText_0.fontSize-1)*cursorRightLeft));
                }
            }
        }
        ofRect(cursor_X, cursor_Y-cursor_H, cursor_W, cursor_H);
    }
    
    ofDisableAlphaBlending();
}
