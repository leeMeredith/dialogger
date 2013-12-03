/*
 * guiText.cpp
 */

#include "guiText.h"

//-------------------------------------------
void guiText::setup(){
	textString = "";
	bRealFont  = false;
	fontSize   = 13;
	numNewLines = 0;
}

//--------------------------------------------
void guiText::setFont(ofTrueTypeFont fontPtr){
	
	ourFont = fontPtr;
	bRealFont = true;
	
}

//--------------------------------------------
float guiText::getTextWidth(){
	float textWidth = 0;
	
	if(bRealFont)textWidth = ourFont.stringWidth(textString);
	else textWidth = 0.615 * (float)fontSize * textString.size();
	
	return  textWidth;
}

//--------------------------------------------
float guiText::getTextHeight(){
	float textHeight = 0;
	
	if(bRealFont)textHeight = ourFont.stringHeight(textString);
	else  textHeight = fontSize + fontSize * numNewLines;
	
	return textHeight;
}

//--------------------------------------------
float guiText::getTextSingleLineHeight(){
	float textHeight = 0;
	
	if(bRealFont)textHeight = ourFont.stringHeight("A");
	else  textHeight = fontSize;
	
	return textHeight;
}

//--------------------------------------------
float guiText::getTextSingleLineWidth(){
	float textWidth = 0;
	
	if(bRealFont)textWidth = ourFont.stringWidth("A");
	else  textWidth = fontSize;
	
	return textWidth;
}

//-------------------------------------------
void guiText::setText(string textStr){
	textString = textStr;
	
	numNewLines = 0;
	for(int i = 0; i < textString.size(); i++){
		if( textString[i] == '\n' )numNewLines++;
	}
	
}

//--------------------------------------------
void guiText::renderText(float x, float y){
	
	if(bRealFont){
		ourFont.drawString(textString, x, y);
	}
}

//--------------------------------------------
void guiText::renderString(string textToRender, float x, float y){
	
	if(bRealFont){
		ourFont.drawString(textToRender, x, y);
	}
}

//--------------------------------------------
float guiText::stringHeight(string textToRender){
	float textHeight = 0;
	
	if(bRealFont)textHeight = ourFont.stringHeight(textToRender);
	else{
		int numLines = 0;
		for(int i = 0; i < textToRender.size(); i++){
			if( textToRender[i] == '\n' )numLines++;
		}
		textHeight = fontSize + fontSize * numLines;
	}
	return textHeight;
}

//--------------------------------------------
float guiText::stringWidth(string textToRender){
	
	float textWidth = 0;
	
	if(bRealFont)textWidth = ourFont.stringWidth(textToRender);
	else textWidth = 0.615 * (float)fontSize * textToRender.size() ;
	
	return  textWidth;
}

