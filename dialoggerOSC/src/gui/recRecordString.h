/*
 * ofxXmlSettings.h
 */

#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"

class recRecordString{

	public:

		void setup(int setX, int setY, string xmlFile);
        void update(string xmlFile);
		void updateAddress(float setRecordAddress);
        void updateString(string setRecordString);
        void updateDialogString(string setRecordDialogString, string setRecordDialogImages);
        void updateInfo(string setArtistName, string setSetName, string setSetAudio, string setFormat, string setSide);
        void updateClearTagContents(string newWhoClearTagCon, string newWhichTagCon);
        void setRGBA(int setR, int setG, int setB, int setA);
		void draw(int setX, int setY, int setW, int setH);
		void keyPressed(int key);
        
        bool dBug, isAtRun;
        string xmlName, xmlFileTest, settingsDirectory, currentXmlFile;
        string whoClearTagCon, whichTagCon;
        bool isRemoveTag;
        bool isRemoveLastPhrase;
        int lastTagNumberRemove;
        float recordAddress, lastPhrase;
        int setRecordAddress, setRecordAddressTestNew, setPhrasesAddress, setRecordAddressTest, setRecordAddressIndexText;
        bool isGetPhrases, isSetRecord, isSetRecordAddressNew;
        int phrasesSize, wordsSize, lettersSize, dialogsSize;
        string getDate, getArtistName, getSetName, getAudio, getFormat, getSide, getString, getDialogString, getDialogImages;
        string date;
        string recordString, newRecString, recordDialogString, newRecDialogString;
        string recordArtistName, recordSetName, recordAudio, recordFormat, recordSide, recordDialogImages;
        string newRecArtistName, newRecSetName, newRecAudio, newRecFormat, newRecSide, newRecDialogImages;
        vector <float> phrases;
        vector <float> words;
        vector <float> letters;
        vector <float> dialogs;
        
        bool isRecord, isSaveAll, isSavePhrase, isStartPhrase, isPhraseTest, isDialog;
        bool isClearDoc, clearTagCon;
        
        vector <float> getPhrases;
        vector <float> getWords;
        vector <float> getLetters;
        vector <float> getDialogs;
        
        bool isGetAll;
        string guiDateTime, guiArtist, guiSet, guiAudio, guiFormat, guiSide, guiRecString, guiRecDialog, guiRecDialogImages;
        float guiRecordVal, guiPhraseVal, phrasesVal, guiWordVal, guiLetterVal, guiDialogVal, guiEndRecVal;
        vector <float> allPhrases;
        vector <float> allWords;
        vector <float> allLetters;
        vector <float> allDialogs;
        int setGetRecordAddress, setGetRecordAddressAll, setGetPhrasesAddress, setGetWordsAddress, setGetLettersAddress, setGetDialogAddress;
        int lastTagNumberEndRec;
        bool isPhrasesAddressEnd, isWordsAddressEnd, isLettersAddressEnd, isDialogAddressEnd;
        
        int x, y, w, h;
		int r, g, b, a;
        
        int loadNextIndex;
        float recStartPhrases;
        vector <float> allRecStartPhrases;
        vector <float> allRecEndRecords;
    
        ofxXmlSettings settingsRecordStringFile;
		ofTrueTypeFont TTF;

		string xmlStructure;
		string message;

		int lastRecTagNumber;
    
        //play-------------------------_
        bool isPlayBack, isIndexPlayBack, isIndexPlayBackNew, isPlayWord, isPlayLetter, isPlayDialog; 
        bool isConsecutivePlayBack, isConsecutivePBAudio;
        bool isConsecPlayBackLast, isGetLetterAddress, isGetStringPlayBack;
        bool isGetDialogPlayBack;
        
        bool isIndexRec;
        bool isGetAllIndexInRec;
        int recTagNumber;
        int phrasesAddres;
        
        int wordAddres;
        float lastDialog, lastLetter, setLastLetterVect;
        float wordVal_0, dialogVal_0;
        int newGetNumLetter;
        int getNumLetter;
        float letterDivision, dialogDivision;
        float addLetterDivision, addAllWords, addDialogDivision, addAllDialogs;
        float nextLetter, nextDialog;
        int wordAddresTestNew, letterAddresTestNew, dialogAddresTestNew;
        
        int letterAddres;
        int dialogAddres;
        string getStringPlayBack, newTempPlayBack, wordPlaying, letterPlaying;
        string getDialogPlayBack, getDialogStringPlayBack, newTempDialogPlayBack, dialogPlaying, dialogDivisionPlaying, getDialog;
        vector <string> allWordsFromString;
        vector <float> allLetterDivision;
        vector <string> allLetterDivisionString;
        
        int getDialogIndex, getDialogDivisionIndex;
        bool isDialogClear;
        string dialogIndex[6];
        vector<int> allDialogIndex;
        vector <string> allDialogFromString;
    
        vector<int> allDialogDivisionIndex;
        vector <float> allDialogDivision;
        vector <string> allDialogDivisionString;
        //play-------------------------_
};

