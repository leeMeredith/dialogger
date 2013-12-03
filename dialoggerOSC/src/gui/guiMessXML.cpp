/*
 *  guiMessXML.cpp
 */

#include "guiMessXML.h"

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

//-------------------------------------------
bool guiMessXML::checkHit(float x, float y){
	if(isInsideRect(x, y, boundingBox)){
		isIn = true;
	}else {
        isIn = false;
    }
}

//--------------------------------------------------------------
void guiMessXML::setup(float newRectX, float newRectY, string newSetDocDir){
	
    boundingBox.set(rectX-15, rectY-128, rectW+13, rectH*7-3);
    
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
    
    recIndex_Y = maxNumInList = 10;
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
    
    getMessRecordXMLTags[0] = getMessRecordXMLTag = getXML.getValue("REALTAGRECORD:message_0" , "XML?");
	getMessRecordXMLTags[1] = getXML.getValue("REALTAGRECORD:message_1" , "XML?");
	getMessRecordXMLTags[2] = getXML.getValue("REALTAGRECORD:message_2" , "XML?");
	getMessRecordXMLTags[3] = getXML.getValue("REALTAGRECORD:message_3" , "XML?");
	getMessRecordXMLTags[4] = getXML.getValue("REALTAGRECORD:message_4" , "XML?");
	getMessRecordXMLTags[5] = getXML.getValue("REALTAGRECORD:message_5" , "XML?");
   	getMessRecordXMLTags[6] = getXML.getValue("REALTAGRECORD:message_6" , "XML?");
    getMessRecordXMLTags[7] = getXML.getValue("REALTAGRECORD:message_7" , "XML?");
    getMessRecordXMLTags[8] = getXML.getValue("REALTAGRECORD:message_8" , "XML?");
    getMessRecordXMLTags[9] = getXML.getValue("REALTAGRECORD:message_9" , "XML?");
    
	rectX = newRectX;
	rectY = newRectY;
	messFont.loadFont("mono.ttf", 15, false);
	guiText_0.setup();
	guiText_0.setFont(messFont);
	guiText_0.setText(getMessRecordXML[8]);
	rectW = guiText_0.getTextWidth();
	rectH = guiText_0.getTextHeight();
    
    //cursor-----------------------_
    cursor_X = rectX-10;
    cursor_Y = rectY-110;
    cursor_W = 1;
	cursor_H = guiText_0.getTextHeight();
    isSetCursorAtSizeOne_X = isSetCursorAtSizeZero_X = isSetCursorAtSize_X = false;
    cursor.set(cursor_X, cursor_Y, cursor_W, cursor_H);
    
    cursorCounter = 0;
    newCursor_X = 0;
    cursor_Y = rectY-110;
    stringSize = 0;
    
    cursorCounter = ofGetSeconds();
    testCursorCounter = true;
    //-----------cursor------------_
	
	isIndex = true;
    isSel = false;
    isSetAllEnter = false;
    isFileEnter = isDateTimeEnter = isArtistEnter = isSetEnter = isAudioEnter = isFormatEnter = isSideEnter = isRecStringEnter = isRecDialogEnter = isImageEnter = false;
    
    playRecordRectColor.set(100, 255, 100, 40);
    recRecordRectColor.set(255, 100, 100, 255);
    playRecordColor.set(100, 255, 100);
    recRecordColor.set(255, 0, 255, 255);
    inRecordRectColor.set(255, 255, 255);
    selRecordRectColor.set(255, 255, 255);
    enterColor.set(255, 0, 0, 255);
    
    isDelete = false;
    
}

//--------------------------------------------------------------
void guiMessXML::update(float newRectX, float newRectY, string newSetDocDir){
	rectX = newRectX;
	rectY = newRectY;
    boundingBox.set(rectX-15, rectY-128, rectW+13, rectH*7-3);
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
    
    //cursor-----------------------_
    if (recIndex_Y != maxNumInList) {
        if (cursorCounter != ofGetSeconds()) {
            testCursorCounter = !testCursorCounter;
            cursorCounter = ofGetSeconds();
        }
    }
    //-----------cursor------------_
    
    int rectXW = rectX+rectW+5;
    
    if (recIndex_Y == maxNumInList) {
        isSetAllEnter = true;
        newCursor_X = rectXW;
        cursor_Y = rectY-110;
        stringSize = file.size();
    }
    
    if (recIndex_Y == 0) {
        newCursor_X = rectXW;
        cursor_Y = rectY-110;
        stringSize = file.size();
    }
    
    if (recIndex_Y == 1) {
        newCursor_X = rectXW;
        cursor_Y = rectY-92;
        stringSize = dateTime.size();
    }
    
    if (recIndex_Y == 2) {
        newCursor_X = rectXW;
        cursor_Y = rectY-74;
        stringSize = artist.size();
    }
    
    if (recIndex_Y == 3) {
        newCursor_X = rectXW;
        cursor_Y = rectY-56;
        stringSize = set.size();
    }
    
    if (recIndex_Y == 4) {
        newCursor_X = rectXW;
        cursor_Y = rectY-38;
        stringSize = audio.size();
    }
    
    if (recIndex_Y == 5) {
        newCursor_X = rectXW;
        cursor_Y = rectY-20;
        stringSize = format.size();
    }
    
    if (recIndex_Y == 6) {
        newCursor_X = rectXW;
        cursor_Y = rectY-2;
        stringSize = side.size();
    }
    
    if (recIndex_Y == 7) {
        newCursor_X = rectXW;
        cursor_Y = rectY+16;
        stringSize = recString.size();
    }
    
    if (recIndex_Y == 8) {
        newCursor_X = rectXW;
        cursor_Y = rectY+34;
        stringSize = recDialog.size();
    }
    
    if (recIndex_Y == 9) {
        newCursor_X = rectXW;
        cursor_Y = rectY+52;
        stringSize = image.size();
    }
    
    if (isUpList == true) {
        recIndex_Y++;
        testCursorCounter = true;
        int rectXW = rectX+rectW+5;
        if (recIndex_Y == 0) {
            newCursor_X = rectXW;
            cursor_Y = rectY-110;
            stringSize = file.size();
        }
        
        if (recIndex_Y == 1) {
            newCursor_X = rectXW;
            cursor_Y = rectY-92;
            stringSize = dateTime.size();
        }
        
        if (recIndex_Y == 2) {
            newCursor_X = rectXW;
            cursor_Y = rectY-74;
            stringSize = artist.size();
        }
        
        if (recIndex_Y == 3) {
            newCursor_X = rectXW;
            cursor_Y = rectY-56;
            stringSize = set.size();
        }
        
        if (recIndex_Y == 4) {
            newCursor_X = rectXW;
            cursor_Y = rectY-38;
            stringSize = audio.size();
        }
        
        if (recIndex_Y == 5) {
            newCursor_X = rectXW;
            cursor_Y = rectY-20;
            stringSize = format.size();
        }
        
        if (recIndex_Y == 6) {
            newCursor_X = rectXW;
            cursor_Y = rectY-2;
            stringSize = side.size();
        }
        
        if (recIndex_Y == 7) {
            newCursor_X = rectXW;
            cursor_Y = rectY+16;
            stringSize = recString.size();
        }
        
        if (recIndex_Y == 8) {
            newCursor_X = rectXW;
            cursor_Y = rectY+34;
            stringSize = recDialog.size();
        }
        
        if (recIndex_Y == 9) {
            newCursor_X = rectXW;
            cursor_Y = rectY+52;
            stringSize = image.size();
        }

        if (recIndex_Y > maxNumInList) {
            recIndex_Y = 0;
        }
        if (recIndex_Y == maxNumInList){
            getMessRecordXMLTag = "";
        }else {
            getMessRecordXMLTag = getMessRecordXMLTags[recIndex_Y];
        }
        cursor_X = newCursor_X + ((float)guiText_0.fontSize-1) * stringSize;
        cursorRightLeft = 0;
        stringIndexRightLeft = stringSize-1; 
        isUpList = false;
        //cout << getMessRecordXMLTag << "       " << recIndex_Y << " isUpList " <<  endl;
    }
    if (isDownList == true) {
        recIndex_Y--;
        testCursorCounter = true;
        int rectXW = rectX+rectW+5;
        if (recIndex_Y == 0) {
            newCursor_X = rectXW;
            cursor_Y = rectY-110;
            stringSize = file.size();
        }
        
        if (recIndex_Y == 1) {
            newCursor_X = rectXW;
            cursor_Y = rectY-92;
            stringSize = dateTime.size();
        }
        
        if (recIndex_Y == 2) {
            newCursor_X = rectXW;
            cursor_Y = rectY-74;
            stringSize = artist.size();
        }
        
        if (recIndex_Y == 3) {
            newCursor_X = rectXW;
            cursor_Y = rectY-56;
            stringSize = set.size();
        }
        
        if (recIndex_Y == 4) {
            newCursor_X = rectXW;
            cursor_Y = rectY-38;
            stringSize = audio.size();
        }
        
        if (recIndex_Y == 5) {
            newCursor_X = rectXW;
            cursor_Y = rectY-20;
            stringSize = format.size();
        }
        
        if (recIndex_Y == 6) {
            newCursor_X = rectXW;
            cursor_Y = rectY-2;
            stringSize = side.size();
        }
        
        if (recIndex_Y == 7) {
            newCursor_X = rectXW;
            cursor_Y = rectY+16;
            stringSize = recString.size();
        }
        
        if (recIndex_Y == 8) {
            newCursor_X = rectXW;
            cursor_Y = rectY+34;
            stringSize = recDialog.size();
        }
        
        if (recIndex_Y == 9) {
            newCursor_X = rectXW;
            cursor_Y = rectY+52;
            stringSize = image.size();
        }

        if (recIndex_Y < 0) {
            recIndex_Y = maxNumInList;
        }
        if (recIndex_Y == maxNumInList){
            getMessRecordXMLTag = "";
        }else {
            getMessRecordXMLTag = getMessRecordXMLTags[recIndex_Y];
        }
        cursor_X = newCursor_X + ((float)guiText_0.fontSize-1) * stringSize;
        cursorRightLeft = 0;
        stringIndexRightLeft = stringSize-1; 
        isDownList = false;
        //cout << getMessRecordXMLTag << "       " << recIndex_Y << " isDownList " << endl;
    }
    
    /*
    
    if (isAddToStringIndex == true) {
        if (stringSize > 0) {
            addToStringIndex++;
            newStringIndexRightLeft = stringIndexRightLeft+addToStringIndex;
            isStringSizeAtZero = false;
        }
        if (stringSize == 0) {
            addToStringIndex = 1;
            isStringSizeAtZero = true;
        }
        
        //stringSize = stringSize + addToStringIndex;
        isAddToStringIndex = false;
    }
    if (isReSetAddToStringIndex == true) {
        addToStringIndex = 0;
        isReSetAddToStringIndex = false;
    }
    
    if (stringSize > 0) {
        if (stringIndexRightLeft >= stringSize) {
            //setRecordArtistName.erase(setRecordArtistName.end()-1,setRecordArtistName.end());
            stringIndexRightLeft--;
        }else {
            //setRecordArtistName.erase(setRecordArtistName.begin()+stringIndexRightLeft);
            stringIndexRightLeft--;
        }
        //setRecordArtistName.erase(setRecordArtistName.end()-1,setRecordArtistName.end());
    }
     //*/
    
    if (isLeft == true) {
        if (recIndex_Y != 0 && recIndex_Y != 1 && recIndex_Y != 4 && recIndex_Y != 9){
            cursorRightLeft++;
            stringIndexRightLeft--;
        }
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
        if (recIndex_Y != 0 && recIndex_Y != 1 && recIndex_Y != 4 && recIndex_Y != 9){
            cursorRightLeft--;
            stringIndexRightLeft++;
        }
        testCursorCounter = true;
        ///*
        if (cursorRightLeft < 0) {
            cursorRightLeft = stringSize-1;
            //stringIndexRightLeft = 0;
        }
        if (stringIndexRightLeft >= stringSize) {
            stringIndexRightLeft = 0;
        }
         //*/
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
        isFileEnter = isDateTimeEnter = isArtistEnter = isSetEnter = isAudioEnter = isFormatEnter = isSideEnter = isRecStringEnter = isRecDialogEnter = isImageEnter = false;
        isSetAllEnter = false;
    }

}

//--------------------------------------------------------------
void guiMessXML::draw(){
	ofFill();
    ofEnableAlphaBlending();
    ofSetColor(playRecordRectColor);
    boundingBox.set(rectX-15, rectY-128, rectW+13, rectH*10-3);
	ofRect(rectX-15, rectY-128, rectW+13, rectH*10-3);
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
    ofRect(rectX-15, rectY-128, rectW+13, rectH*10-3);
    int rectXW = rectX+rectW+5;
    
    ofFill();
    if (recIndex_Y == 0) {
        if (isFileEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(enterColor);
        }
    }else {
        if (isFileEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(file, rectXW, rectY-110);
    guiText_0.renderString(getMessRecordXML[0], rectX-10, rectY-110);
    
    if (recIndex_Y == 1) {
        if (isDateTimeEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isDateTimeEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(dateTime, rectXW, rectY-92);
    guiText_0.renderString(getMessRecordXML[1], rectX-10, rectY-92);
    
    if (recIndex_Y == 2) {
        if (isArtistEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isArtistEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(artist, rectXW, rectY-74);
	guiText_0.renderString(getMessRecordXML[2], rectX-10, rectY-74);
    
    if (recIndex_Y == 3) {
        if (isSetEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isSetEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(set, rectXW, rectY-56);
	guiText_0.renderString(getMessRecordXML[3], rectX-10, rectY-56);
    
    if (recIndex_Y == 4) {
        if (isAudioEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(enterColor);
        }
    }else {
        if (isAudioEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(audio, rectXW, rectY-38);
	guiText_0.renderString(getMessRecordXML[4], rectX-10, rectY-38);
    
    if (recIndex_Y == 5) {
        if (isFormatEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isFormatEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(format, rectXW, rectY-20);
	guiText_0.renderString(getMessRecordXML[5], rectX-10, rectY-20);
    
    if (recIndex_Y == 6) {
        if (isSideEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isSideEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(side, rectXW, rectY-2);
	guiText_0.renderString(getMessRecordXML[6], rectX-10, rectY-2);
    
    if (recIndex_Y == 7) {
        if (isRecStringEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isRecStringEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(recString, rectXW, rectY+16);
	guiText_0.renderString(getMessRecordXML[7], rectX-10, rectY+16);
    
    if (recIndex_Y == 8) {
        if (isRecDialogEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(recRecordColor);
        }
    }else {
        if (isRecDialogEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(playRecordColor);
        }
    }
    guiText_0.renderString(recDialog, rectXW, rectY+34);
    guiText_0.renderString(getMessRecordXML[8], rectX-10, rectY+34);
    
    if (recIndex_Y == 9) {
        if (isImageEnter == true) {
            ofSetColor(enterColor);
        }else {
            ofSetColor(enterColor);
        }
    }else {
        ofSetColor(playRecordColor);
    }
    guiText_0.renderString(image, rectXW, rectY+52);
    guiText_0.renderString(getMessRecordXML[9], rectX-10, rectY+52);
    
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
            isSetCursorAtSize_X = true;
            isSetCursorAtSizeZero_X = true;
        }
        ofRect(cursor_X, cursor_Y-cursor_H, cursor_W, cursor_H);
    }
    ofDisableAlphaBlending();
}
