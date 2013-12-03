//NOTE: The AF system of dialog animation was developed by companies 
//like Hanna Barbera on the TV shows of the 1960s.
//http://www.angryanimator.com/word/2010/11/26/tutorial-3-dialog/
//http://www.idleworm.com/how/anm/03t/talk1.shtml
//http://www.mpi-inf.mpg.de/resources/FAM/publ/pg2002.pdf
//http://www.youtube.com/watch?v=btBwP4yG92I
//
//"Hello My Friend"
//"BCDEF ACD BECDCB"

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetWindowTitle("dialoggerOSC");
    
    isDialoggerGuiDraw = true;
    
    wordFont.loadFont("mono.ttf", 92, false);
	word.setup();
	word.setFont(wordFont);
	word.setText("dialogger");
    
    letterFont.loadFont("mono.ttf", 140, false);
    letter.setup();
	letter.setFont(letterFont);
	letter.setText("d");
    
    fileImageFont.loadFont("mono.ttf", 24, false);
    nameOfFileImage.setup();
	nameOfFileImage.setFont(fileImageFont);
	nameOfFileImage.setText("nameOfFileImage");
    
    currentDialogImageVal = 0;
    currentDialogImageValDisplay.setup(50, 450, currentDialogImageVal);
    
    //dialogger----------------------_
    dialogger_0.setup();
    //-----------dialogger-----------_
}

//--------------------------------------------------------------
void testApp::update(){
    
    if(isFullscreen == false){
        ofSetWindowTitle("dialoggerOSC");
    }

    //dialogger----------------------_    
    dialogger_0.update(mouseX, mouseY);
    currentDialogImageVal = dialogger_0.currentDialogImage;
    currentDialogImageValDisplay.update(ofGetWidth()/2-180, ofGetHeight()/2-100, currentDialogImageVal);
    //-----------dialogger-----------_
}

//--------------------------------------------------------------
void testApp::draw(){
    
	//---------
    ofFill();

	ofSetColor(240, 240, 225);
    
    //dialogger----------------------_
    if (isDialoggerGuiDraw == true){
        dialogger_0.draw(isDialoggerGuiDraw);
    }
    if (isDialoggerGuiDraw == false){
        if (dialogger_0.isPlayWord == true) {
            if (dialogger_0.isNewWord == true) {
                rWR = ofRandom(255);
                rWG = ofRandom(255);
                rWB = ofRandom(255);
            }
            ofSetColor(rWR, rWG, rWB);
            if (dialogger_0.wordPlaying != "NA") {
                word.renderString(dialogger_0.wordPlaying, 50, 150);
            }
        }
        if (dialogger_0.isPlayLetter == true) {
            if (dialogger_0.isNewLetter == true) {
                rLR = ofRandom(255);
                rLG = ofRandom(255);
                rLB = ofRandom(255);
            }
            ofSetColor(rLR, rLG, rLB);
            if (dialogger_0.wordPlaying != "NA") {
                letter.renderString(dialogger_0.letterPlaying, 50, 350);
            }
        }
        if (dialogger_0.isPlayDialog == true) {
            if (dialogger_0.isNewNameOfFileImage == true) {
                rFIR = ofRandom(255);
                rFIG = ofRandom(255);
                rFIB = ofRandom(255);
            }
            ofSetColor(rFIR, rFIG, rFIB);
            nameOfFileImage.renderString(dialogger_0.getNameOfFileImage, ofGetWidth()/2-150, ofGetHeight()/2-150);
            
            currentDialogImageValDisplay.draw();
            
            //float imageWidth = dialogger_0.imagePlaying.width;
            //float imageHeigh = dialogger_0.imagePlaying.height;
            float imageScaleAmount = 3;
            ofEnableAlphaBlending();
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2-150, ofGetHeight()/2-100, 0);
            ofScale(imageScaleAmount, imageScaleAmount, 1);
            dialogger_0.draw(isDialoggerGuiDraw);
            ofPopMatrix();	
            ofDisableAlphaBlending();
        }
    }
    ofSetColor(255);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    //-----------dialogger-----------_
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if(key == '|') {
        isDialoggerGuiDraw = !isDialoggerGuiDraw;
        if (isDialoggerGuiDraw == true)ofShowCursor();
        if (isDialoggerGuiDraw == false)ofHideCursor();
	}
    if(key == 'f' && dialogger_0.isKeyFill == false){
        isFullscreen = !isFullscreen;
        if(!isFullscreen){
            ofSetWindowShape(1280,800);
            ofSetFullscreen(false);
            ofSetWindowTitle("dialoggerOSC");
            //ofSetWindowPosition(0, 0);
        } else if(isFullscreen == 1){
            ofSetFullscreen(true);
        }
    }
    
    //dialogger----------------------_
    if (key == '5'){    
        dialogger_0.setCurrentDirByAddres = 0;
    }
    if (key == '6'){
        dialogger_0.setCurrentDirByAddres = 1;
    }
    if (key == '7'){
        dialogger_0.setCurrentDirByFile = "TheDemo";
    }
    if (key == '8'){
        dialogger_0.setCurrentDirByFile = "testingTrue";
    }
    
    if (isDialoggerGuiDraw == false){
        if (key == '1'){
            dialogger_0.isPlay = true;
        }
        if (key == '3'){
            dialogger_0.isAllPlayBack = !dialogger_0.isAllPlayBack;
        }
        if (key == 'i'){
            dialogger_0.isIndexPlayBack = !dialogger_0.isIndexPlayBack;
        }
        if (key == 'c'){
            dialogger_0.isConsecutivePlayBack = !dialogger_0.isConsecutivePlayBack;
        }        
    }
    dialogger_0.keyPressed(key);
    //-----------dialogger-----------_
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //dialogger----------------------_
    dialogger_0.mousePressed(x, y, button);
    //-----------dialogger-----------_
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //dialogger----------------------_
    dialogger_0.mouseReleased(x, y, button);
    //-----------dialogger-----------_
}
