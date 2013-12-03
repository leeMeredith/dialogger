#pragma once

#include "ofxXmlSettings.h"
#include "recRecordString.h"
#include "guiMessXML.h"
#include "guiGetRecMessXML.h"
#include "dialogPlayer.h"
#include "allHitAreaImage.h"
#include "textImageDisplay.h"
#include "guiOscMessXML.h"
#include "ofxOsc.h"

//osc--------------
//#define HOST "192.168.1.6"
// listen on port 12345
//#define PORT 12345
#define NUM_MSG_STRINGS 20
//--------osc------

class dialogger{
    
public:
    
    void setup();
    void update(float newMouseX, float newMouseY);
    void draw(bool newIsGuiDraw);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    void keyReleased(int key);
    
    float mouseX, mouseY;
    bool isGuiDraw;
    
    float recordAddress;
    int setRecordAddress, setPhrasesAddress;
    bool isGetPhrases;
    bool isSetAllDefault;
    bool isSetRecordFileDefault, isRecordFileKeyLR;
    bool isSetAudioDefault, isSetDialogImagesDefault, isSetDialogImagesFolderDefault;
    string date;
    string setRecordFileDefault, setRecordFile, recordFile, setCurrentDirByFile, setCurrentDirByFileTest;
    string setRecordAudioDefault, setRecordAudio, recordAudio;
    string setRecordImageDefault, setRecordImage, recordImage;
    string setRecordImageFolderDefault, setRecordImageFolder, recordImageFolder, setRecordImageFolderTest;
    string recordArtistName, recordSetName, recordFormat, recordSide;
    string setRecordArtistName, setRecordSetName, setRecordFormat, setRecordSide;
    string setRecordArtistNameDefault, setRecordSetNameDefault, setRecordFormatDefault, setRecordSideDefault;
    string recordString, setRecordString, setRecordStringDefault;
    string recordDialogString, setRecordDialogString, setRecordDialogStringDefault;
    
    bool isFullscreen;
    bool isKeyFile, isKeyArtistName, isKeySetName, isKeyAudio, isKeyRecFormat, isKeyRecSide, isKeyString, isKeyDiaString, isKeyDiaImage;
    bool isKeyFill;
    bool isRecord, isSaveAll, isSavePhrase, isStartPhrase, isPhraseTest, isNothing, isDialog;
    bool clearDoc, clearTagCon, clearTagAttrib;
    
    bool isGetAll;
    
    float graphRecString_X, graphRecString_Y, graphRecString_W, graphRecString_H;
    int graphRecString_R, graphRecString_G, graphRecString_B, graphRecString_A;
    int setGetRecordAddress, setGetRecordAddressAll, setGetPhrasesAddress, setGetWordsAddress, setGetLettersAddress, setGetDialogAddress, setGetNothingsAddress;
    
    string recRecordWhoClearTagCon, recRecordWhichTagCon;
    bool isAllPlayBack, isCanAllPlayBack, isPlayBackIn, isIndexPlayBack, isConsecutivePlayBack;
    bool isAllPlayBackTest, isIndexPlayBackTest, isConsecutivePlayBackTest;
    string wordPlaying, wordPlayingTest, letterPlaying, letterPlayingTest;
    bool isNewWord, isNewLetter;
    recRecordString recRecordString_0;
    
    //guiMessXML------------------------_
    bool isDelAtIndexZero;
    int addKeyIndexZero;
    int stringSizeWas;
    string toAddZero;
    guiMessXML guiMessXML_0;
    guiGetRecMessXML guiGetRecMessXML_0;
    //-----------guiMessXML-------------_
    
    //letterForm----------------------_
    string letterForm;
    //-----------letterForm-----------_
    
    //ofDirectory------------------------_
    ofDirectory recordAddressDir;
    bool isJustAtRunFile;
    int recAddressCurrentDir, setCurrentDirByAddresTest, setCurrentDirByAddres;
    bool isRecAddressCurrentDir, isRecordAddressR, isRecordAddressL;
    bool isKeyFileRL;
    
    ofDirectory recordAudioDir;
    int recAudioCurrentDir;
    bool isRecAudioCurrentDir, isRecordAudioR, isRecordAudioL;
    string nameOfDirPathAudio;
    bool isKeyAudioRL;
    
    ofDirectory dirDialogFolder;
    bool isJustAtRunDialogFolder;
    int recImageFolderCurrentDir;
    bool isRecImageFolderCurrentDir, isRecordImageFolderL, isRecordImageFolderR;
    bool isKeyImageFolderRL;
    string dirDialogImageFolderStringDefault, dirDialogImageFolderString, setDirirDialogImageFolderString;
    bool isNewNameOfFileImage;
    string getNameOfFileImage, getNameOfFileImageTest;
    
    vector<string> imagesFolder;
    int currentDialogImageFolder;
    
    ofDirectory dirDialogImage;
    int recImageCurrentDir, recImageCurrentDirTest;
    string dirDialogImageStringDefault, dirDialogImageString, setDirirDialogImageString;
    
    vector<ofImage> images;
    ofImage imagePlaying;
    int currentDialogImage;
    bool isImageR, isImageL;
    
    int hitAreaImageIndex;
    bool isAddHitDialog;
    string hitDialogIndex;
    bool myImageNew;
    ofImage myImage[6];
    allHitAreaImage allHitAreaImage_0;
    //-------------ofDirectory-----------_
    
    //textImageDisplay----------_
    textImageDisplay display;
    //-----textImageDisplay-----_
    
    //dialogPlayer--------------_
    bool isPlay;
    bool isPlayWord, isPlayLetter, isPlayDialog;
    dialogPlayer dialogPlayer_0;
    //-------dialogPlayer-------_
    
    //ofxOscReceiver------------_
    bool isFormOsc;
    bool isKeyPort, isKeyHost, isKeyOscAddres;
    
    guiOscMessXML guiOscMessXML_0;
    string stringToIntPort;
    string stringPort, setStringPort, host, setHost, oscAddres, setOscAddres;
    int port, setPort;
    ofxOscSender sender;
    ofxOscReceiver receiver;
    int				current_msg_string;
    string		msg_strings[NUM_MSG_STRINGS];
    float			timers[NUM_MSG_STRINGS];
    //------ofxOscReceiver------_
};

