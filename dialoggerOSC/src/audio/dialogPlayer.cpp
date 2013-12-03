/*
 *  dialogPlayer.cpp
 */

#include "dialogPlayer.h"

static bool isInsideRect(float x, float y, ofRectangle rect){
    return ( x >= rect.x && x <= rect.x + rect.width && y >= rect.y && y <= rect.y + rect.height );
}

//-------------------------------------------
bool dialogPlayer::checkHit(float x, float y){
	if(isInsideRect(x, y, boundingBox)){
		isIn = true;
	}else {
        isIn = false;
    }
}

//--------------------------------------------------------------
void dialogPlayer::setup(int newRectX, int newRectY, string newDialogAudioDir){
    rectX = newRectX;
	rectY = newRectY;
    dialogAudioDirTest = dialogAudioDir = newDialogAudioDir;
    
    int newRectH = rectH*7+9;
    boundingBox.set(rectX-12, rectY-100, rectW+43, newRectH);
    
    //xml----------------------------_
    setMessageDir = "record/message/message_presets.xml";
    if( getXML.loadFile(setMessageDir) ){
        cout << "message_presets.xml loaded from documents folder!" << endl;
    }else if( getXML.loadFile("record/message/message_presets.xml") ){
        cout << "message_presets.xml loaded from data folder!" << endl;
    }else{
        cout << "unable to load message_presets.xml check data/ folder" << endl;
    }
    audio = play = paused = volume = speed = position = "";
    getMessAudioXML[0] = getXML.getValue("AUDIO:message_0" , "XML?");
    getMessAudioXML[1] = getXML.getValue("AUDIO:message_1" , "XML?");
    getMessAudioXML[2] = getXML.getValue("AUDIO:message_2" , "XML?");
    getMessAudioXML[3] = getXML.getValue("AUDIO:message_3" , "XML?");
    getMessAudioXML[4] = getXML.getValue("AUDIO:message_4" , "XML?");
    getMessAudioXML[5] = getXML.getValue("AUDIO:message_5" , "XML?");
    //-------------xml---------------_
    
	dialogPlayerFont.loadFont("mono.ttf", 15, false);
	guiText_0.setup();
	guiText_0.setFont(dialogPlayerFont);
	guiText_0.setText(getMessAudioXML[5]);
	rectW = guiText_0.getTextWidth();
	rectH = guiText_0.getTextHeight();
    
    
	dialog.loadSound(dialogAudioDir);
	dialog.setVolume(0.75f);
	dialog.setMultiPlay(false);
    
    isPlay = isPaused = false;
    isEdit = true;
    getDialogPositionMS = dialog.getPositionMS();
    getDialogPosition = dialog.getPosition();// just to have a 0-1 Position
    getDialogSpeed = dialog.getSpeed();
    getDialogVolume = dialog.getVolume();
    
    playRecordRectColor.set(0, 0, 255, 40);
    
    isSel = false;
    setPos = 0;
    playColor.set(255, 255, 255, 255);
    pausedColor.set(0, 0, 255, 255);
    controlColor.set(255, 0, 255, 255);
    selRecordRectColor.set(255, 255, 255);
    
    //ofxSimpleSlider-----------------_
    slider_X = 150;
    slider_Y = 370;
    isSliderDrawTest = isSliderDraw = true;
    sliderVolume.isDraw = true;
    sliderSpeed.isDraw = true;
    sliderPosition.isDraw = true;
    sliderVolume.setup(slider_X, slider_Y+25, 100, 20, 0, 1, 0.75f, false, 0);
    sliderSpeed.setup(slider_X, slider_Y+45, 100, 20, 0, 1, 1, false, 0);
    sliderPosition.setup(slider_X, slider_Y+65, 570, 20, 0, 1, 0, false, 0);
    //----------ofxSimpleSlider-------_

}

//--------------------------------------------------------------
void dialogPlayer::update(int newRectX, int newRectY, string newDialogAudioDir){
    dialogAudioDir = newDialogAudioDir;
    
    int newRectH = rectH*7+9;
    boundingBox.set(rectX-12, rectY-100, rectW+43, newRectH);
    
    if (dialogAudioDir != dialogAudioDirTest) {
        dialog.unloadSound();
        dialog.loadSound(dialogAudioDir);
        dialogAudioDirTest = dialogAudioDir;
    }
    
    if (isEdit == true) {
        //ofxSimpleSlider-----------------_
        float pctPos = sliderPosition.getValue();
        float pctSpeed = sliderSpeed.getValue();
        float pctVolume = sliderVolume.getValue();
        dialogAudioPosition = pctPos;
        dialogAudioSpeed = pctSpeed;
        dialogAudioVolume = pctVolume;
        //----------ofxSimpleSlider-------_
        controlColor.set(255, 0, 255, 255);
    }else {
        dialogAudioPosition = setPos;
        float pctSpeed = sliderSpeed.getValue();
        float pctVolume = sliderVolume.getValue();
        dialogAudioSpeed = pctSpeed;
        dialogAudioVolume = pctVolume;
        controlColor.set(100, 100, 255, 255);
    }
    
	if (isPlay == true) {
        dialog.play();
        if (isEdit == true){
            dialog.setPosition(dialogAudioPosition);
        }else {
            dialog.setPositionMS(dialogAudioPosition);
        }
		dialog.setSpeed(dialogAudioSpeed);
        dialog.setVolume(dialogAudioVolume);
        
        isPlay = false;
    }
    
    getDialogPositionMS = dialog.getPositionMS();
    getDialogPosition = dialog.getPosition();// just to have a 0-1 Position
    getDialogSpeed = dialog.getSpeed();
    getDialogVolume = dialog.getVolume();
    
    if (dialog.getIsPlaying()) {
        playColor.set(255, 0, 255, 255);
    }else {
        playColor.set(100, 100, 255, 255);
    }
    if (isPaused == true) {
        dialog.setPaused(true);
        pausedColor.set(255, 0, 255, 255);
        isPlay = false;
    }else {
        pausedColor.set(100, 100, 255, 255);
        dialog.setPaused(false);
    }
    if (dialog.getIsPlaying() == false) {
        isPlayTest = false;
    }
   	// update the sound playing system:
    ofSoundUpdate();

}

//--------------------------------------------------------------
void dialogPlayer::draw(){
    ofFill();
    ofEnableAlphaBlending();
	ofSetColor(playRecordRectColor);
    int newRectH = rectH*7+9;
    boundingBox.set(rectX-12, rectY-100, rectW+43, newRectH);
	ofRect(rectX-12, rectY-100, rectW+43, newRectH);
    
    ofNoFill();
    if (isIn == true) {
        ofSetColor(inRecordRectColor);
    }
    if (isSel == true) {
        ofSetColor(selRecordRectColor);
    }
	ofRect(rectX-12, rectY-100, rectW+43, newRectH);

    ofFill();
    ofSetColor(100, 100, 255, 255);
	guiText_0.renderString(getMessAudioXML[0], rectX-10, rectY-80);
    ofSetColor(playColor);
	guiText_0.renderString(getMessAudioXML[1], rectX-10, rectY-60);
    ofSetColor(pausedColor);
	guiText_0.renderString(getMessAudioXML[2], rectX+50, rectY-60);
    ofSetColor(controlColor);
	guiText_0.renderString(getMessAudioXML[3], rectX-10, rectY-40);
	guiText_0.renderString(getMessAudioXML[4], rectX-10, rectY-20);
    guiText_0.renderString(getMessAudioXML[5], rectX-10, rectY);
    
    if (isSliderDraw == true ) {
        sliderVolume.draw();
        sliderSpeed.draw();
        sliderPosition.draw();
        isSliderDrawTest = isSliderDraw;
    }
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void dialogPlayer::keyPressed  (int key){
    if(key == '1'){
        isPlay = true;
        //newGetDialogPositionMS = dialog.getPositionMS();
    }
    if(key == '2'){
        isPaused = !isPaused;
        isPlay = true;
        newGetDialogPositionMS = dialog.getPositionMS();
    }
}

//--------------------------------------------------------------
void dialogPlayer::keyReleased(int key){

}

//--------------------------------------------------------------
void dialogPlayer::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void dialogPlayer::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void dialogPlayer::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void dialogPlayer::mouseReleased(int x, int y, int button){

}