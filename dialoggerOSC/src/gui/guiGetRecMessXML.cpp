/*
 *  guiGetRecMessXML.cpp
 */

#include "guiGetRecMessXML.h"

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

//-------------------------------------------
bool guiGetRecMessXML::checkHit(float x, float y){
	if(isInsideRect(x, y, boundingBox)){
		isIn = true;
	}else {
        isIn = false;
    }
}

//--------------------------------------------------------------
void guiGetRecMessXML::setup(float newRectX, float newRectY, string newSetDocDir){
	
	setDocDir = newSetDocDir;//message_presets.xml;
	message = "record/message/message_presets.xml";
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
    //*/
	
    getMessGetRecordXML[0] = getXML.getValue("GETRECORD:message_0", "XML?");
    getMessGetRecordXML[1] = getXML.getValue("GETRECORD:message_1", "XML?");
    getMessGetRecordXML[2] = getXML.getValue("GETRECORD:message_2", "XML?");
    getMessGetRecordXML[3] = getXML.getValue("GETRECORD:message_3", "XML?");
    //getMessGetRecordXML[6] = getXML.getValue("GETRECORD:message_6", "XML?");
    	
	rectX = newRectX;
	rectY = newRectY;
	recFont.loadFont("mono.ttf", 15, false);
	guiText_0.setup();
	guiText_0.setFont(recFont);
	guiText_0.setText(getMessGetRecordXML[3]);
	rectW = guiText_0.getTextWidth();
	rectH = guiText_0.getTextHeight();
    
	isIndex = true;
    
    //recordFloat-----------------------_
    inComingFloatColor.set(240, 240, 240, 200);
    playRecordFloatRectColor.set(100, 255, 100, 40);
    recRecordFloatRectColor.set(255, 100, 100, 40);
    playRecordFloatColor.set(100, 255, 100);
    recRecordFloatColor.set(255, 100, 100);
    
    playRecordRectColor.set(100, 255, 100, 40);
    recRecordRectColor.set(255, 100, 100, 40);
    playRecordColor.set(100, 255, 100);
    recRecordColor.set(255, 100, 100);
    
    int rectXW = rectX+rectW+15;
    record.setup(rectXW, rectY-80, recordVal);
    phrase.setup(rectXW, rectY-60, phraseVal);
    word.setup(rectXW, rectY-40, wordVal);
    endRec.setup(rectXW, rectY-20, endRecVal);
    //------------recordFloat-----------_
    
    //recordInt-----------------------_
    int rectIntXW = rectX+rectW+15;
    recordSize.setup(rectIntXW, rectY-80, recordValSize);
    phraseSize.setup(rectIntXW, rectY-60, phraseValSize);
    wordSize.setup(rectIntXW, rectY-40, wordValSize);
    endRecSize.setup(rectIntXW, rectY-20, endRecValSize);
    //------------recordInt-----------_
}

//--------------------------------------------------------------
void guiGetRecMessXML::update(float newRectX, float newRectY, string newSetDocDir){
	rectX = newRectX;
	rectY = newRectY;
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
    */
    
    getMessGetRecordXML[0] = getXML.getValue("GETRECORD:message_0", "XML?");
    getMessGetRecordXML[1] = getXML.getValue("GETRECORD:message_1", "XML?");
    getMessGetRecordXML[2] = getXML.getValue("GETRECORD:message_2", "XML?");
    getMessGetRecordXML[3] = getXML.getValue("GETRECORD:message_3", "XML?");
    
    //recordInt-----------------------_
    int rectIntXW = rectX+rectW+10;
    recordSize.update(rectIntXW, rectY-80, recordValSize);
    phraseSize.update(rectIntXW, rectY-60, phraseValSize);
    wordSize.update(rectIntXW, rectY-40, wordValSize);
    endRecSize.update(rectIntXW, rectY-20, endRecValSize);
    
    recordSize.rectTextColor = inComingFloatColor;
    phraseSize.rectTextColor = playRecordFloatRectColor;
    wordSize.rectTextColor = playRecordFloatRectColor;
    endRecSize.rectTextColor = playRecordFloatRectColor;
    
    recordSize.textColor = inComingFloatColor;
    phraseSize.textColor = phraseFloatColor;
    wordSize.textColor = wordFloatColor;
    endRecSize.textColor = endRecFloatColor;
    //------------recordInt-----------_    
    
    //recordFloat-----------------------_
    int rectXW = rectX+rectW+40;
    record.update(rectXW, rectY-80, recordVal);
    phrase.update(rectXW, rectY-60, phraseVal);
    word.update(rectXW, rectY-40, wordVal);
    endRec.update(rectXW, rectY-20, endRecVal);
    
    record.rectTextColor = inComingFloatColor;
    phrase.rectTextColor = playRecordFloatRectColor;
    word.rectTextColor = playRecordFloatRectColor;
    endRec.rectTextColor = playRecordFloatRectColor;
    
    record.textColor = inComingFloatColor;
    phrase.textColor = phraseFloatColor;
    word.textColor = wordFloatColor;
    endRec.textColor = endRecFloatColor;
    //------------recordFloat-----------_

}

//--------------------------------------------------------------
void guiGetRecMessXML::draw(){
	ofFill();
    ofEnableAlphaBlending();
	ofSetColor(playRecordRectColor);
    boundingBox.set(rectX-15, rectY-98, rectW+41, rectH*5+3);
	ofRect(rectX-15, rectY-98, rectW+41, rectH*5+3);
    
    ofNoFill();
	ofSetColor(playRecordColor);
	ofRect(rectX-15, rectY-98, rectW+41, rectH*5+3);
	
    ofFill();
    ofSetColor(playRecordColor);//ofSetColor(playRecordRectColor);
	guiText_0.renderString(getMessGetRecordXML[0], rectX-10, rectY-80);
	guiText_0.renderString(getMessGetRecordXML[1], rectX-10, rectY-60);
	guiText_0.renderString(getMessGetRecordXML[2], rectX-10, rectY-40);
	guiText_0.renderString(getMessGetRecordXML[3], rectX-10, rectY-20);
    
    //recordInt-----------------------_
    recordSize.draw();
    phraseSize.draw();
    wordSize.draw();
    endRecSize.draw();
    //------------recordInt-----------_
    
    //recordFloat-----------------------_
    record.draw();
    phrase.draw();
    word.draw();
    endRec.draw();
    //------------recordFloat-----------_
    ofDisableAlphaBlending();

}
