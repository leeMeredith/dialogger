/*
 * recRecordString.cpp
 */

#include "recRecordString.h"

//--------------------------------------------------------------
void recRecordString::setup(int setX, int setY, string xmlFile){
    
    recordAddress = 0.1;
    dBug = false;
    isAtRun = true;
    
    x = setX;
    y = setY;
    
    xmlFileTest = xmlFile;
    currentXmlFile = "record/address/";
    currentXmlFile += xmlFile;
    settingsDirectory = currentXmlFile;
    
    int posLastSlash = settingsDirectory.rfind("/");
    if(posLastSlash > 0)settingsDirectory.erase(settingsDirectory.begin()+ posLastSlash+1, settingsDirectory.end()  );
    else settingsDirectory = "";
    //currentXmlFile = settingsDirectory + currentXmlFile;
    int posLastDot = currentXmlFile.rfind(".xml");
    if (posLastDot < 1) {
        currentXmlFile += ".xml";
    }
    //currentXmlFile += "/";

	message = "loading ";
    message += currentXmlFile;
	
	if( settingsRecordStringFile.loadFile(currentXmlFile) ){
        message = currentXmlFile;
		message += " loaded!";
	}else{
		message = "unable to load ";
        message += currentXmlFile;
	}
    isGetAllIndexInRec = true;
    
    isRemoveTag = false;
    isRemoveLastPhrase = false;
    lastTagNumberRemove = 0;
    
    date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
    isPhraseTest = true;
    isClearDoc = clearTagCon = false;
    whoClearTagCon = "artistName";
    whichTagCon = "tesuji";
    recordAddress = 0.1;
    recordString = "Hello My Friend";
    recordDialogString = "BCDEF ACD BECDCB";
    recordArtistName = "tesuji";
    recordSetName = "myset_0";
    recordAudio = "HMF.wav";
    recordFormat = "wav";
    recordSide = "NA";
    recordDialogImages = "record/dialog/images/bob_A_F/";
    
    newRecArtistName = recordArtistName;
    newRecSetName = recordSetName;
    newRecAudio = recordAudio;
    newRecFormat = recordFormat;
    newRecSide = recordSide;
    newRecString = recordString;
    newRecDialogString = recordDialogString;
    newRecDialogImages = "record/dialog/images/bob_A_F/";//recordDialogImages;
    
	lastRecTagNumber = 0;    
	
    //-------
    int numAboutTags = settingsRecordStringFile.getNumTags("about");
	if(numAboutTags == 0){
        //client about
        settingsRecordStringFile.addTag("about");
        settingsRecordStringFile.pushTag("about");
        settingsRecordStringFile.addValue("file", currentXmlFile);
        date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
        settingsRecordStringFile.addValue("DATE", date);
        settingsRecordStringFile.addValue("client","--dialogger-- Version: BETA.0");
        settingsRecordStringFile.addValue("authors", "Lee Meredith");
        settingsRecordStringFile.addValue("url","http://www.diamondsandcode.com");
        settingsRecordStringFile.addValue("github", "http://www.diamondsandcode.com");
        settingsRecordStringFile.popTag();
        //client end about
        
        //version
        settingsRecordStringFile.addTag("version");
        settingsRecordStringFile.pushTag("version");
        
        settingsRecordStringFile.addValue("major", 0);
        settingsRecordStringFile.addValue("minor", 6);
        settingsRecordStringFile.popTag();
        //end version 
        
        //recordString header
        settingsRecordStringFile.addTag("RECORD");
        settingsRecordStringFile.pushTag("RECORD", numAboutTags-1);
        settingsRecordStringFile.addValue("file", currentXmlFile);
        date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
        settingsRecordStringFile.addValue("DATE", date);
        settingsRecordStringFile.addValue("artistName", recordArtistName);
        settingsRecordStringFile.addValue("setName", recordSetName);
        settingsRecordStringFile.addValue("audio", recordAudio);
        settingsRecordStringFile.addValue("format", recordFormat);
        settingsRecordStringFile.addValue("side", recordSide);
        settingsRecordStringFile.addValue("string", recordString);
        settingsRecordStringFile.addValue("dialogString", recordDialogString);
        settingsRecordStringFile.addValue("dialogImage", recordDialogImages);
        
        settingsRecordStringFile.addValue("PHRASE", -1);
        settingsRecordStringFile.addValue("WORD", -1);
        settingsRecordStringFile.addValue("LETTER", -1);
        settingsRecordStringFile.addValue("DIALOG", -1);
        settingsRecordStringFile.addValue("ENDRECORD", -1);
        
        settingsRecordStringFile.popTag();
        //record about
        
        settingsRecordStringFile.popTag(); //pop position
    }
    
    setRecordAddressTest = setRecordAddress = 0;
    setPhrasesAddress = 0;
    
    //play---------------------------------_
    isPlayBack = isPlayWord = isPlayLetter = isPlayDialog = false;
    isGetLetterAddress = isGetStringPlayBack = true;
    isGetDialogPlayBack = true;
    phrasesAddres = wordAddres = 0;
    lastDialog = wordVal_0 = letterDivision = addLetterDivision = addAllWords = nextLetter = 0;
    lastDialog = dialogVal_0 = dialogDivision = addDialogDivision = addAllDialogs = nextDialog = 0;
    newGetNumLetter = getNumLetter = letterAddres = dialogAddres = wordAddresTestNew = 0;
    letterAddresTestNew = dialogAddresTestNew = -1;
    getStringPlayBack = getDialogStringPlayBack = wordPlaying = getDialogPlayBack = "";
    
    isDialogClear = false;
    dialogIndex[0] =  "A";
    dialogIndex[1] =  "B";
    dialogIndex[2] =  "C";
    dialogIndex[3] =  "D";
    dialogIndex[4] =  "E";
    dialogIndex[5] =  "F";
    //---------------play------------------_
    
    //get----------------------------------_
    isGetPhrases = false;
    if (isGetPhrases == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            getPhrases.clear();
            getWords.clear();
            getLetters.clear();
            getDialogs.clear();
            int numberOfSavedPhrase = settingsRecordStringFile.getNumTags("PHRASE");
            int numberOfSavedWord = settingsRecordStringFile.getNumTags("WORD");
            int numberOfSavedLetter = settingsRecordStringFile.getNumTags("LETTER");
            int numberOfSavedDialog = settingsRecordStringFile.getNumTags("DIALOG");
            float myPhrases_0;
            float myPhrases_1;
            float myEndRec;
            lastPhrase = settingsRecordStringFile.getValue("PHRASE", 0.0, numberOfSavedPhrase-1);
            myPhrases_0 = settingsRecordStringFile.getValue("PHRASE", 0.0, setPhrasesAddress);
            if (myPhrases_0 == lastPhrase) {
                myPhrases_1 = settingsRecordStringFile.getValue("ENDRECORD", 0.0, 0);
            }else {
                myPhrases_1 = settingsRecordStringFile.getValue("PHRASE", 0.0, setPhrasesAddress+1);
            }
            myEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, 0);
            for(int i = 0; i < numberOfSavedWord; i++){
                float myWord;
                myWord = settingsRecordStringFile.getValue("WORD", 0.0, i);
                if (myWord >= myPhrases_0 && myWord <= myPhrases_1) {
                    getWords.push_back(myWord);
                    if (dBug == true)cout << "myWord " << myWord << endl;
                }
            }
            
            for(int i = 0; i < numberOfSavedLetter; i++){
                float myLetter;
                myLetter = settingsRecordStringFile.getValue("LETTER", 0.0, i);
                if (myLetter >= myPhrases_0 && myLetter <= myPhrases_1) {
                    getLetters.push_back(myLetter);
                    if (dBug == true)cout << "myLetter " << myLetter << endl;
                }
            }
            
            for(int i = 0; i < numberOfSavedDialog; i++){
                float myDialog;
                myDialog = settingsRecordStringFile.getValue("DIALOG", 0.0, i);
                if (myDialog >= myPhrases_0 && myDialog <= myPhrases_1) {
                    getDialogs.push_back(myDialog);
                    if (dBug == true)cout << "myDialog " << myDialog << endl;
                }
            }
            getPhrases.push_back(myPhrases_0);
            settingsRecordStringFile.popTag();
        }
        if (dBug == true){
            cout << "getPhrases.size(); " << getPhrases.size() << endl;
            cout << "getWords.size(); " << getWords.size() << endl;
            cout << "getLetters.size(); " << getLetters.size() << endl;
            cout << "getDialogs.size(); " << getDialogs.size() << endl;
        }
        isGetPhrases = false;
    }
    
    isGetAll = true;
    if (isGetAll == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            getDate = settingsRecordStringFile.getValue("DATE","");
            getArtistName = settingsRecordStringFile.getValue("artistName", "");
            getSetName = settingsRecordStringFile.getValue("setName", "");
            getAudio = settingsRecordStringFile.getValue("audio", "");
            getFormat = settingsRecordStringFile.getValue("format", "");
            getSide = settingsRecordStringFile.getValue("side", "");
            getString = settingsRecordStringFile.getValue("string", "");
            getDialogString = settingsRecordStringFile.getValue("dialogString", "");
            getDialogImages = settingsRecordStringFile.getValue("dialogImage", "");

            
            int numberOfSavedPhrase = settingsRecordStringFile.getNumTags("PHRASE");
            for(int i = 0; i < numberOfSavedPhrase; i++){
                float myPhrases;
                myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, i);
                allPhrases.push_back(myPhrases);
            }
            std::sort (allPhrases.begin(), allPhrases.end());
            
            int numberOfSavedWord = settingsRecordStringFile.getNumTags("WORD");
            for(int i = 0; i < numberOfSavedWord; i++){
                float myWord;
                myWord = settingsRecordStringFile.getValue("WORD", 0.0, i);
                allWords.push_back(myWord);
            }
            std::sort (allWords.begin(), allWords.end());
            
            int numberOfSavedLetter = settingsRecordStringFile.getNumTags("LETTER");
            for(int i = 0; i < numberOfSavedLetter; i++){
                float myLetter;
                myLetter = settingsRecordStringFile.getValue("LETTER", 0.0, i);
                allLetters.push_back(myLetter);
            }
            std::sort (allLetters.begin(), allLetters.end());
            
            int numberOfSavedDialog = settingsRecordStringFile.getNumTags("DIALOG");
            for(int i = 0; i < numberOfSavedDialog; i++){           
                float myDialog;
                myDialog = settingsRecordStringFile.getValue("DIALOG", 0.0, i);
                allDialogs.push_back(myDialog);
            }
            std::sort (allDialogs.begin(), allDialogs.end());
            
            int numberOfSavedEndRec = settingsRecordStringFile.getNumTags("ENDRECORD");
            if (numberOfSavedEndRec > 0) {
                lastTagNumberEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, numberOfSavedEndRec-1);
            }
            settingsRecordStringFile.popTag(); //pop position
        }
        isGetAll = false;
    }
    
    setGetRecordAddress = setGetWordsAddress = setGetLettersAddress = setGetDialogAddress = setGetPhrasesAddress = 0;
    isPhrasesAddressEnd = isWordsAddressEnd = isLettersAddressEnd = isDialogAddressEnd = false;
    if (allPhrases.size() > 0) {
        guiDateTime = getDate;
        guiArtist = getArtistName;
        guiSet = getSetName;
        guiAudio = getAudio;
        guiFormat = getFormat;
        guiSide = getSide;
        guiRecString = getString;
        guiRecDialog = getDialogString;
        guiRecDialogImages = getDialogImages;
        
        setGetRecordAddress = 0;
        //setGetRecordAddressAll = recRecordString_0.setPhrasesAddress;
        if (setGetRecordAddressAll >= allPhrases.size()) {
            setGetPhrasesAddress = allPhrases.size()-1;
        }
        if (setGetRecordAddressAll >= allWords.size()) {
            setGetWordsAddress = allWords.size()-1;
        }
        if (setGetRecordAddressAll >= allLetters.size()) {
            setGetLettersAddress = allLetters.size()-1;
        }
        if (setGetRecordAddressAll >= allDialogs.size()) {
            setGetDialogAddress = allDialogs.size()-1;
        }
        
        guiRecordVal = recordAddress;
        if (allPhrases.size() > 0)guiPhraseVal = allPhrases[setGetPhrasesAddress];
        if (allPhrases.size() == 0){
            guiPhraseVal = -1;
        }
        if (allWords.size() > 0)guiWordVal = allWords[setGetWordsAddress];
        if (allWords.size() == 0){
            guiWordVal = -1;
        }
        if (allLetters.size() > 0)guiLetterVal = allLetters[setGetLettersAddress];
        if (allLetters.size() == 0){
            guiLetterVal = -1;
        }
        if (allDialogs.size() > 0)guiDialogVal = allDialogs[setGetDialogAddress];
        if (allDialogs.size() == 0){
            guiDialogVal = -1;
        }
        guiEndRecVal = lastTagNumberEndRec;
    }
    
    isIndexPlayBack = isIndexPlayBackNew = isConsecutivePlayBack = false;
    loadNextIndex = 0;
    //---------------get-------------------_
    
    //edit----------------------------_
    isSaveAll = isSavePhrase = isStartPhrase = isSetRecord = false;
    //------------edit----------------_
}

//--------------------------------------------------------------
void recRecordString::update(string xmlFile){
    
    if (xmlFile != xmlFileTest) {
        currentXmlFile = "record/address/";
        currentXmlFile += xmlFile;
        settingsDirectory = currentXmlFile;
        
        int posLastSlash = settingsDirectory.rfind("/");
        if( posLastSlash > 0) settingsDirectory.erase(settingsDirectory.begin()+ posLastSlash+1, settingsDirectory.end()  );
        else settingsDirectory = "";
        
        int posLastDot = currentXmlFile.rfind(".xml");
        if (posLastDot < 1) {
            currentXmlFile += ".xml";
        }
        //currentXmlFile += "/";
        
        message = "loading ";
        message += currentXmlFile;
        
        if( settingsRecordStringFile.loadFile(currentXmlFile) ){
            message = currentXmlFile;
            message += " loaded!";
        }else{
            message = "unable to load ";
            message += currentXmlFile;
        }
        
        int numAboutTags = settingsRecordStringFile.getNumTags("about");
        if(numAboutTags >= 1){
            settingsRecordStringFile.pushTag("about");
            if (settingsRecordStringFile.getValue("file", "") != currentXmlFile) {
                settingsRecordStringFile.removeTag("file", 0);
                settingsRecordStringFile.addValue("file", currentXmlFile);
            }
            settingsRecordStringFile.popTag();
        }
        xmlFileTest = xmlFile;
    }
    
    //play---------------------------------_
    //getStringPlayBack-----------_
    
    if (isGetStringPlayBack == true) {
        int lastSpass = 0;
        int nextSpass = 0;
        int addToString = 0;
        for (int i=0; i < getString.length(); i++){
            if(getString.at(i) == ' '){
                ++addToString;
            }
        }
        
        if (addToString < allWords.size()) {
            for (int i=addToString; i < allWords.size()-1; i++){
                getString += " word";
            }
        }
        if (getStringPlayBack != getString && getString != "") {
            
            string newGetString = getString;
            newGetString += " ";
            if (allWordsFromString.size() > 0) {
                allWordsFromString.clear();
                allLetterDivision.clear();
                allLetterDivisionString.clear();
                
                allLetterDivision.push_back(0);
            }
            for (int i=0; i < newGetString.length(); i++){
                if(newGetString.at(i) == ' '){
                    nextSpass = i;
                    
                    for (int j = lastSpass; j <= nextSpass; j++) {
                        if(newGetString.at(j) != ' '){
                            newTempPlayBack += newGetString.at(j);
                            string l;
                            l = newGetString.at(j);
                            allLetterDivisionString.push_back(l);
                        }
                    }
                    allWordsFromString.push_back(newTempPlayBack);
                    newTempPlayBack = "";
                }
                lastSpass = nextSpass;
            }
            allLetterDivisionString.push_back("");
            if (allWords.size() > 0) {
                //if (recordAddress  <= allWords[allWords.size()-1] ) {
                    int numberOfSavedEndRec = settingsRecordStringFile.getNumTags("ENDRECORD");
                    if (numberOfSavedEndRec > 0) {
                        lastTagNumberEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, numberOfSavedEndRec-1);
                    }
                    for(int i = 0; i < allWords.size(); i++){
                        
                        if (allWords[i] < allWords[allWords.size()-1]) {
                            lastLetter = allWords[i+1];
                        }
                        if (allWords[i] >= allWords[allWords.size()-1]) {
                            lastLetter = lastTagNumberEndRec;
                        }
                        
                        if (letterAddresTestNew != i) {
                            addAllWords = allWords[i];
                            addLetterDivision = nextLetter = 0;
                            letterAddresTestNew = i;
                        }
                        wordVal_0 = lastLetter - allWords[i];
                        
                        int getNumLetterMax;
                        getNumLetterMax = allWordsFromString[i].size();
                        
                        letterDivision = wordVal_0 / getNumLetterMax;
                        
                        bool isAllLetterAddres;
                        isAllLetterAddres = true;
                        for(int j = 0; j < allWordsFromString[i].size(); j++){                        
                            addLetterDivision = addLetterDivision + letterDivision;
                            nextLetter = addAllWords + addLetterDivision;//was letterDivision;
                            allLetterDivision.push_back(nextLetter);
                        }
                    }
                    //cout << allLetterDivision.size() << endl;
                //}                
            }
            getStringPlayBack = getString;
        }
    }
    //------getStringPlayBack-----_
    
    //getDialogPlayBack-----------_
    if (isGetDialogPlayBack == true) {
        int lastSpass = 0;
        int nextSpass = 0;
        int addToDialogString = 0;
        
        for (int i=0; i < getDialogString.length(); i++){
            if(getDialogString.at(i) == ' '){
                ++addToDialogString;
            }
        }
        
        if (addToDialogString < allDialogs.size()) {
            for (int i=addToDialogString; i < allDialogs.size()-1; i++){
                getDialogString += " A";
            }
        }
        if (addToDialogString <= 0){
            for (int i=addToDialogString; i < allDialogs.size()-1; i++){
                getDialogString += " A";
            }
        }

        if (getDialogPlayBack != getDialogString && getDialogString != "") {
                        
            string newGetDialog = getDialogString;
            newGetDialog += " ";
            if (allDialogFromString.size() > 0) {
                allDialogFromString.clear();
                allDialogDivision.clear();
                allDialogDivisionString.clear();
                
                allDialogDivision.push_back(0);
                isDialogClear = true;
            }
            
            for (int i=0; i < newGetDialog.length(); i++){
                if(newGetDialog.at(i) == ' '){
                    nextSpass = i;
                    for (int j = lastSpass; j <= nextSpass; j++) {
                        if(newGetDialog.at(j) != ' '){
                            newTempDialogPlayBack += newGetDialog.at(j);
                            string d;
                            d = newGetDialog.at(j);
                            allDialogDivisionString.push_back(d);
                        }
                    }
                    allDialogFromString.push_back(newTempDialogPlayBack);
                    newTempDialogPlayBack = "";
                }
                lastSpass = nextSpass;
            }
            allDialogDivisionString.push_back("");
            if (allDialogs.size() > 0) {
                //if (recordAddress <= allDialogs[allDialogs.size()-1] ) {
                    int numberOfSavedEndRec = settingsRecordStringFile.getNumTags("ENDRECORD");
                    if (numberOfSavedEndRec > 0) {
                        lastTagNumberEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, numberOfSavedEndRec-1);
                    }
                    for(int i = 0; i < allDialogs.size(); i++){
                        
                        if (allDialogs[i] < allDialogs[allDialogs.size()-1]) {
                            lastDialog = allDialogs[i+1];
                        }
                        if (allDialogs[i] >= allDialogs[allDialogs.size()-1]) {
                            lastDialog = lastTagNumberEndRec;
                        }

                        if (dialogAddresTestNew != i) {
                            addAllDialogs = allDialogs[i];
                            addDialogDivision = nextDialog = 0;
                            dialogAddresTestNew = i;
                        }
                        dialogVal_0 = lastDialog - allDialogs[i];
                        
                        int getNumDialogMax;
                        getNumDialogMax = allDialogFromString[i].size();
                        
                        dialogDivision = dialogVal_0 / getNumDialogMax;
                        
                        bool isAllDialogAddres;
                        isAllDialogAddres = true;
                        for(int j = 0; j < allDialogFromString[i].size(); j++){                        
                            addDialogDivision = addDialogDivision + dialogDivision;
                            nextDialog = addAllDialogs + addDialogDivision;
                            allDialogDivision.push_back(nextDialog);
                        }
                    }
                //}
            }
            getDialogPlayBack = getDialogString;
        }
    }
    //------getDialogPlayBack-----_
    
    if (isGetLetterAddress == true) {
        isGetLetterAddress = false;
    }
    
    if (isPlayBack == true) {
        //phrasesPlayBack-----------_
        if (allPhrases.size() >= 2) {
            if (recordAddress <= allPhrases[allPhrases.size()-1] ) {
                for(int i = 0; i < allPhrases.size(); i++){
                    if (recordAddress >= allPhrases[i] &&  recordAddress < allPhrases[i+1]) {
                        int phrasesAddres;
                        phrasesAddres = i;
                        phrasesVal = allPhrases[phrasesAddres+1] - allPhrases[phrasesAddres];
                    }
                }
            }
        
            if (recordAddress > allPhrases[allPhrases.size()-1]){
                int phrasesAddres;
                phrasesAddres = allPhrases.size()-1;
                phrasesVal = lastTagNumberEndRec - allPhrases[phrasesAddres];
            }
        }
        if (allPhrases.size() == 1) {
            if (recordAddress > allPhrases[0]){
                int phrasesAddres;
                phrasesAddres = allPhrases[0];
                phrasesVal = allPhrases[phrasesAddres] - lastTagNumberEndRec;
            }
        }

        if (isIndexPlayBack == true) {
            if (allRecStartPhrases.size() > 0){
                for(int i = 0; i < allRecStartPhrases.size(); i++){
                     if (recordAddress >= allRecStartPhrases[i] && recordAddress <= allRecEndRecords[i]){
                         if (i != setRecordAddressIndexText) {
                             isIndexPlayBackNew = true;
                             setRecordAddressIndexText = setRecordAddressTest = setRecordAddress = loadNextIndex = i;
                             //isGetStringPlayBack = true;
                             //getStringPlayBack = "well!?";
                             isGetAll = true;
                         }
                     }
                }
                if (recordAddress <= 0) {
                    loadNextIndex = 0;
                }
                if (recordAddress >= allRecEndRecords[allRecEndRecords.size()-1]) {
                    recordAddress = allRecEndRecords[allRecEndRecords.size()-1];
                } 
            }
        }
        if (isConsecutivePlayBack == true) {
            if (allRecEndRecords.size() > 0){
                if (recordAddress >= allRecEndRecords[setRecordAddress]){
                    isIndexPlayBackNew = true;
                    ++setRecordAddress;
                    //if (setRecordAddress != allRecEndRecords.size()-1)isConsecutivePBAudio = true;
                    isConsecutivePBAudio = true;
                    isGetAll = true; 
                }
                if (setRecordAddress >= settingsRecordStringFile.getNumTags("RECORD")) {
                    if (recordAddress >= allRecEndRecords[allRecEndRecords.size()-1]){
                        isIndexPlayBackNew = true;
                        setRecordAddress = 0;
                        isConsecPlayBackLast = true;
                        isConsecutivePlayBack = false;
                    }
                }
            }
        }
        //-----phrasesPlayBack------_
        
        //stringPlayBack-----------_
        if (isPlayWord == true) {
            if (recordAddress <= allWords[allWords.size()-1]) {
                for(int i = 0; i < allWords.size(); i++){
                    
                    lastLetter = allWords[i+1];
                    
                    if (recordAddress >= allWords[i] && recordAddress < lastLetter) {
                        int wordAddres;
                        wordAddres = i;
                        
                        if (wordAddres <= allWordsFromString.size()) {
                            wordPlaying = allWordsFromString[wordAddres];
                        }
                    }
                }
            }
            if (recordAddress > allWords[allWords.size()-1]){
                int wordAddres;
                wordAddres = allWords.size()-1;
                wordPlaying = allWordsFromString[wordAddres];
            }
        }
         
        if (isPlayLetter == true) {
            if (allLetterDivision.size() > 0) {
                
                for(int i = 0; i <= allLetterDivision.size()-1; i++){
                    if (recordAddress >= allLetterDivision[i] && recordAddress < allLetterDivision[i+1]) {
                        int letterDivisionAddres;
                        letterDivisionAddres = i;
                        if (i <= allLetterDivision.size()-1) {
                            letterPlaying = allLetterDivisionString.at(letterDivisionAddres);
                            //cout << allLetterDivision.size() << endl;
                        }
                    }
                }
                
                if (recordAddress > allLetterDivision[allLetterDivision.size()-1]) {
                    int letterDivisionAddres;
                    letterDivisionAddres = allLetterDivision.size()-1;
                    letterPlaying = allLetterDivisionString.at(letterDivisionAddres);
                }
            }
        }
        //-----stringPlayBack------_
        
        //for(int i = 0; i < allLetters.size(); i++){
        //    if (recordAddress >= allLetters[i] && recordAddress < allLetters[i+1]) {
        //        int letterAddres;
        //        letterAddres = i;
        //    }
        //}
        
        //dialogPlayBack-----------_
        if (isPlayDialog == true) {
            if (recordAddress <= allDialogs[allDialogs.size()-1] ) {
                for(int i = 0; i < allDialogs.size(); i++){
                    lastLetter = allDialogs[i+1];
                    if (recordAddress >= allDialogs[i] && recordAddress < lastLetter) {
                        dialogAddres = i;
                        if (dialogAddres <= allDialogFromString.size()) {
                            dialogPlaying = allDialogFromString[dialogAddres];
                            for (int k = 0; k <= 5; k++) {
                                if (dialogIndex[k] == dialogPlaying) {
                                    getDialogIndex = k;
                                }
                            }
                        }
                    }
                }
            }
            if (recordAddress > allDialogs[allDialogs.size()-1]){
                dialogAddres = allDialogs.size()-1;
                dialogPlaying = allDialogFromString[dialogAddres];
                for (int k = 0; k <= 5; k++) {
                    if (dialogIndex[k] == dialogPlaying) {
                        getDialogIndex = k;
                    }
                }
            }
            
            if (allDialogDivision.size() > 0) {
                
                for(int i = 0; i <= allDialogDivision.size()-1; i++){
                    if (recordAddress >= allDialogDivision[i] && recordAddress < allDialogDivision[i+1]) {
                        int dialogDivisionAddres;
                        dialogDivisionAddres = i;
                        if (i <= allDialogDivision.size()-1) {
                            dialogDivisionPlaying = allDialogDivisionString.at(dialogDivisionAddres);
                            for (int k = 0; k <= 5; k++) {
                                if (dialogIndex[k] == dialogDivisionPlaying) {
                                    getDialogDivisionIndex = k;
                                }
                            }
                        }
                    }
                }
                
                if (recordAddress > allDialogDivision[allDialogDivision.size()-1]) {
                    int dialogDivisionAddres;
                    dialogDivisionAddres = allDialogDivision.size()-1;
                    dialogDivisionPlaying = allDialogDivisionString.at(dialogDivisionAddres);
                    for (int k = 0; k <= 5; k++) {
                        if (dialogIndex[k] == dialogDivisionPlaying) {
                            getDialogDivisionIndex = k;
                        }
                    }
                }
            }
        }
        //------dialogPlayBack-----_
        
        //int numberOfSavedEndRec = settingsRecordStringFile.getNumTags("ENDRECORD");
        //if (numberOfSavedEndRec > 0) {
          //  lastTagNumberEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, numberOfSavedEndRec-1);
        //}
    }
    
    //----------------play-----------------_
    
    //get----------------------------------_
    if (isGetPhrases == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            /*
            getDate = settingsRecordStringFile.getValue("DATE","");
            getArtistName = settingsRecordStringFile.getValue("artistName", "");
            getSetName = settingsRecordStringFile.getValue("setName", "");
            getAudio = settingsRecordStringFile.getValue("audio", "");
            getFormat = settingsRecordStringFile.getValue("format", "");
            getSide = settingsRecordStringFile.getValue("side", "");
            getString = settingsRecordStringFile.getValue("string", "");
            getDialogString = settingsRecordStringFile.getValue("dialogString", "");
            getDialogImages = settingsRecordStringFile.getValue("dialogImage", "");
             */
            getPhrases.clear();
            getWords.clear();
            getLetters.clear();
            getDialogs.clear();
            
            int numberOfSavedPhrase = settingsRecordStringFile.getNumTags("PHRASE");
            int numberOfSavedWord = settingsRecordStringFile.getNumTags("WORD");
            int numberOfSavedLetter = settingsRecordStringFile.getNumTags("LETTER");
            int numberOfSavedDialog = settingsRecordStringFile.getNumTags("DIALOG");
            
            float myPhrases_0;
            float myPhrases_1;
            float myEndRec;
            lastPhrase = settingsRecordStringFile.getValue("PHRASE", 0.0, numberOfSavedPhrase-1);
            myPhrases_0 = settingsRecordStringFile.getValue("PHRASE", 0.0, setPhrasesAddress);// or ("X",0)
            if (myPhrases_0 == lastPhrase) {
                myPhrases_1 = settingsRecordStringFile.getValue("ENDRECORD", 0.0, 0);
            }else {
                myPhrases_1 = settingsRecordStringFile.getValue("PHRASE", 0.0, setPhrasesAddress+1);// or ("X", 0)
            }
            myEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, 0);
            for(int i = 0; i < numberOfSavedWord; i++){
                float myWord;
                myWord = settingsRecordStringFile.getValue("WORD", 0.0, i);
                if (myWord >= myPhrases_0 && myWord <= myPhrases_1) {
                    getWords.push_back(myWord);
                    if (dBug == true)cout << "myWord " << myWord << endl;
                }
            }
            
            for(int i = 0; i < numberOfSavedLetter; i++){
                float myLetter;
                myLetter = settingsRecordStringFile.getValue("LETTER", 0.0, i);
                if (myLetter >= myPhrases_0 && myLetter <= myPhrases_1) {
                    getLetters.push_back(myLetter);
                    if (dBug == true)cout << "myLetter " << myLetter << endl;
                }
            }
            
            for(int i = 0; i < numberOfSavedDialog; i++){
                float myDialog;
                myDialog = settingsRecordStringFile.getValue("DIALOG", 0.0, i);
                if (myDialog >= myPhrases_0 && myDialog <= myPhrases_1) {
                    getDialogs.push_back(myDialog);
                    if (dBug == true)cout << "myDialog " << myDialog << endl;
                }
            }
            
            getPhrases.push_back(myPhrases_0);
            settingsRecordStringFile.popTag();
        }
        if (dBug == true){
            cout << "getPhrases.size(); " << getPhrases.size() << endl;
            cout << "getWords.size(); " << getWords.size() << endl;
            cout << "getLetters.size(); " << getLetters.size() << endl;
            cout << "getDialogs.size(); " << getDialogs.size() << endl;
        }
        isGetPhrases = false;
    }
    
    if (isGetAll == true) {
        setGetRecordAddressAll = 0;
        allPhrases.clear();
        allWords.clear();
        allLetters.clear();
        allDialogs.clear();
        if (setRecordAddress != setRecordAddressTest) {            
            isSetRecordAddressNew = true;
            setRecordAddressTest = setRecordAddress;
        }
        if (setRecordAddress == setRecordAddressTest){
            isSetRecordAddressNew = false;
        }
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            getDate = settingsRecordStringFile.getValue("DATE","");
            getArtistName = settingsRecordStringFile.getValue("artistName", "");
            getSetName = settingsRecordStringFile.getValue("setName", "");
            getAudio = settingsRecordStringFile.getValue("audio", "");
            getFormat = settingsRecordStringFile.getValue("format", "");
            getSide = settingsRecordStringFile.getValue("side", "");
            getString = settingsRecordStringFile.getValue("string", "");
            getDialogString = settingsRecordStringFile.getValue("dialogString", "");
            getDialogImages = settingsRecordStringFile.getValue("dialogImage", "");
            
            int numberOfSavedPhrase = settingsRecordStringFile.getNumTags("PHRASE");
            for(int i = 0; i < numberOfSavedPhrase; i++){
                float myPhrases;
                myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, i);// or ("X", 0)
                allPhrases.push_back(myPhrases);
            }
            std::sort (allPhrases.begin(), allPhrases.end());
            
            int numberOfSavedWord = settingsRecordStringFile.getNumTags("WORD");
            for(int i = 0; i < numberOfSavedWord; i++){
                float myWord;
                myWord = settingsRecordStringFile.getValue("WORD", 0.0, i);
                allWords.push_back(myWord);
            }
            std::sort (allWords.begin(), allWords.end());
            
            int numberOfSavedLetter = settingsRecordStringFile.getNumTags("LETTER");
            for(int i = 0; i < numberOfSavedLetter; i++){                
                float myLetter;
                myLetter = settingsRecordStringFile.getValue("LETTER", 0.0, i);
                allLetters.push_back(myLetter);
            }
            std::sort (allLetters.begin(), allLetters.end());
            
            int numberOfSavedDialog = settingsRecordStringFile.getNumTags("DIALOG");
            for(int i = 0; i < numberOfSavedDialog; i++){
                float myDialog;
                myDialog = settingsRecordStringFile.getValue("DIALOG", 0.0, i);
                allDialogs.push_back(myDialog);
            }
            std::sort (allDialogs.begin(), allDialogs.end());
            
            int numberOfSavedEndRec = settingsRecordStringFile.getNumTags("ENDRECORD");
            if (numberOfSavedEndRec > 0) {
                lastTagNumberEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, numberOfSavedEndRec-1);
            }
            settingsRecordStringFile.popTag(); //pop position
        }
        isGetAllIndexInRec = true;
        isGetAll = false;
    }
    
    if (allWords.size() > 0) {
        guiDateTime = getDate;
        guiArtist = getArtistName;
        guiSet = getSetName;
        guiAudio = getAudio;
        guiFormat = getFormat;
        guiSide = getSide;
        guiRecString = getString;
        guiRecDialog = getDialogString;
        guiRecDialogImages = getDialogImages;
        
        setGetRecordAddress = 0;
        
        if (setGetRecordAddressAll >= allPhrases.size()-1) {
            setGetPhrasesAddress = allPhrases.size()-1;
            isPhrasesAddressEnd = true;
        }else {
            setGetPhrasesAddress = setGetRecordAddressAll;
            isPhrasesAddressEnd = false;
        }
        if (setGetRecordAddressAll >= allWords.size()-1) {
            setGetWordsAddress = allWords.size()-1;
            isWordsAddressEnd = true;
        }else {
            setGetWordsAddress = setGetRecordAddressAll;
            isWordsAddressEnd = false;
        }
        if (setGetRecordAddressAll >= allLetters.size()-1) {//-1 is to give the stop Color
            setGetLettersAddress = allLetters.size()-1;
            isLettersAddressEnd = true;
        }else {
            setGetLettersAddress = setGetRecordAddressAll;
            isLettersAddressEnd = false;
        }
        if (setGetRecordAddressAll >= allDialogs.size()-1) {//-1 is to give the stop Color
            setGetDialogAddress = allDialogs.size()-1;
            isDialogAddressEnd = true;
        }else {
            setGetDialogAddress = setGetRecordAddressAll;
            isDialogAddressEnd = false;
        }
        
        guiRecordVal = recordAddress;
        if (allPhrases.size() > 0)guiPhraseVal = allPhrases[setGetPhrasesAddress];
        if (allPhrases.size() == 0){
            guiPhraseVal = -1;
        }
        if (allWords.size() > 0)guiWordVal = allWords[setGetWordsAddress];
        if (allWords.size() == 0){
            guiWordVal = -1;
        }
        if (allLetters.size() > 0)guiLetterVal = allLetters[setGetLettersAddress];
        if (allLetters.size() == 0){
            guiLetterVal = -1;
        }
        if (allDialogs.size() > 0)guiDialogVal = allDialogs[setGetDialogAddress];
        if (allDialogs.size() == 0){
            guiDialogVal = -1;
        }

        guiEndRecVal = lastTagNumberEndRec;
    }
    
    if (isGetAllIndexInRec == true) {
        if (allRecStartPhrases.size() > 0){
            allRecStartPhrases.clear();
            allRecEndRecords.clear();
        }
        recTagNumber = settingsRecordStringFile.getNumTags("RECORD");
        if (recTagNumber > 0) {
            for(int i = 0; i < recTagNumber; i++){
                if( settingsRecordStringFile.pushTag("RECORD", i) ){
                    float myPhrases;
                    myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, 0);
                    allRecStartPhrases.push_back(myPhrases);
                    float myEndRec;
                    myEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, 0);
                    allRecEndRecords.push_back(myEndRec);
                }
                settingsRecordStringFile.popTag();
            }
        }
        isGetAllIndexInRec = false;
    }
    //---------------get-------------------_
    
    //edit----------------------------_
    if (isSaveAll == true) {
        settingsRecordStringFile.saveFile(currentXmlFile);
        message = currentXmlFile;
        message += " saved to xml!";
        isSaveAll = false;
    }
    if (isSetRecord == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
            settingsRecordStringFile.setValue("DATE", date);
            settingsRecordStringFile.setValue("artistName", recordArtistName);
            settingsRecordStringFile.setValue("setName", recordSetName);
            settingsRecordStringFile.setValue("audio", recordAudio);
            settingsRecordStringFile.setValue("format", recordFormat);
            settingsRecordStringFile.setValue("side", recordSide);
            settingsRecordStringFile.setValue("string", recordString);
            settingsRecordStringFile.setValue("dialogString", recordDialogString);
            settingsRecordStringFile.setValue("dialogImage", recordDialogImages);
            settingsRecordStringFile.popTag();
        }
        isSetRecord = false;
    }
    
    if (isStartPhrase == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            if (allWords.size() > 0) {
                if (recordAddress <= allWords[allWords.size()-1]) {
                    float myPhrases;
                    myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, 0);
                    if (myPhrases < 0) {
                        settingsRecordStringFile.removeTag("PHRASE", 0);
                        settingsRecordStringFile.addValue("PHRASE", phrases[0]);
                    }else {
                        settingsRecordStringFile.addValue("PHRASE", phrases[0]);
                    }
                }
                if (recordAddress > allWords[allWords.size()-1]) {
                    float myPhrases;
                    myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, 0);
                    if (myPhrases < 0) {
                        settingsRecordStringFile.removeTag("PHRASE", 0);
                        settingsRecordStringFile.addValue("PHRASE", phrases[0]);
                    }else {
                        settingsRecordStringFile.addValue("PHRASE", phrases[0]);
                    }
                    float myWords;
                    myWords = settingsRecordStringFile.getValue("WORD", 0.0, 0);
                    if (myWords < 0) {
                        settingsRecordStringFile.removeTag("WORD", 0);
                        settingsRecordStringFile.addValue("WORD", words[0]);
                    }else {
                        settingsRecordStringFile.addValue("WORD", words[0]);
                    }
                    float myLetters;
                    myLetters = settingsRecordStringFile.getValue("LETTER", 0.0, 0);
                    if (myLetters < 0) {
                        settingsRecordStringFile.removeTag("LETTER", 0);
                        settingsRecordStringFile.addValue("LETTER", letters[0]);
                    }else {
                        settingsRecordStringFile.addValue("LETTER", letters[0]);
                    }
                    float myDialogs;
                    myDialogs = settingsRecordStringFile.getValue("DIALOG", 0.0, 0);
                    if (myDialogs < 0) {
                        settingsRecordStringFile.removeTag("DIALOG", 0);
                        settingsRecordStringFile.addValue("DIALOG", words[0]);
                    }else {
                        settingsRecordStringFile.addValue("DIALOG", words[0]);
                    }
                }
            }else {
                float myPhrases;
                myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, 0);
                if (myPhrases < 0) {
                    settingsRecordStringFile.removeTag("PHRASE", 0);
                    settingsRecordStringFile.addValue("PHRASE", phrases[0]);
                }else {
                    settingsRecordStringFile.addValue("PHRASE", phrases[0]);
                }
                float myWords;
                myWords = settingsRecordStringFile.getValue("WORD", 0.0, 0);
                if (myWords < 0) {
                    settingsRecordStringFile.removeTag("WORD", 0);
                    settingsRecordStringFile.addValue("WORD", words[0]);
                }else {
                    settingsRecordStringFile.addValue("WORD", words[0]);
                }
                float myLetters;
                myLetters = settingsRecordStringFile.getValue("LETTER", 0.0, 0);
                if (myLetters < 0) {
                    settingsRecordStringFile.removeTag("LETTER", 0);
                    settingsRecordStringFile.addValue("LETTER", letters[0]);
                }else {
                    settingsRecordStringFile.addValue("LETTER", letters[0]);
                }
                float myDialogs;
                myDialogs = settingsRecordStringFile.getValue("DIALOG", 0.0, 0);
                if (myDialogs < 0) {
                    settingsRecordStringFile.removeTag("DIALOG", 0);
                    settingsRecordStringFile.addValue("DIALOG", words[0]);
                }else {
                    settingsRecordStringFile.addValue("DIALOG", words[0]);
                }
            }
            settingsRecordStringFile.popTag(); //pop position
        }
        
        settingsRecordStringFile.saveFile(currentXmlFile);
        message = currentXmlFile;
        message += " saved to xml!";
        
        phrases.clear();
        words.clear();
        letters.clear();
        dialogs.clear();
        isStartPhrase = false;
    }
    
    if (isSavePhrase == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            if (words.size() > 0) {
                float myPhrases;
                myPhrases = settingsRecordStringFile.getValue("PHRASE", 0.0, 0);
                if (myPhrases < 0) {
                    settingsRecordStringFile.removeTag("PHRASE", 0);
                    settingsRecordStringFile.addValue("PHRASE", words[0]);//if Value "PHRASE" is < 0 make new words[0]
                }
            }
            float myWords;
            myWords = settingsRecordStringFile.getValue("WORD", 0.0, 0);
            if (myWords < 0) {
                settingsRecordStringFile.removeTag("WORD", 0);
                for(int i = 0; i < words.size(); i++){
                    settingsRecordStringFile.addValue("WORD", words[i]);
                }
                if (words.size() == 0) {
                    settingsRecordStringFile.addValue("WORD", -1);
                }
            }else {
                for(int i = 0; i < words.size(); i++){
                    settingsRecordStringFile.addValue("WORD", words[i]);
                }
            }
            float myLetters;
            myLetters = settingsRecordStringFile.getValue("LETTER", 0.0, 0);
            if (myLetters < 0) {
                settingsRecordStringFile.removeTag("LETTER", 0);
                for(int i = 0; i < letters.size(); i++){
                    settingsRecordStringFile.addValue("LETTER", letters[i]);
                }
                if (letters.size() == 0) {
                    settingsRecordStringFile.addValue("LETTER", -1);
                }

            }else {
                for(int i = 0; i < letters.size(); i++){
                    settingsRecordStringFile.addValue("LETTER", letters[i]);
                }
            }
            float myDialogs;
            myDialogs = settingsRecordStringFile.getValue("DIALOG", 0.0, 0);
            if (myDialogs < 0) {
                settingsRecordStringFile.removeTag("DIALOG", 0);
                for(int i = 0; i < dialogs.size(); i++){
                    settingsRecordStringFile.addValue("DIALOG", dialogs[i]);
                }
                if (dialogs.size() == 0) {
                    settingsRecordStringFile.addValue("DIALOG", -1);
                }
            }else {
                for(int i = 0; i < dialogs.size(); i++){
                    settingsRecordStringFile.addValue("DIALOG", dialogs[i]);
                }
            }
            settingsRecordStringFile.popTag(); //pop position
        }
        settingsRecordStringFile.saveFile(currentXmlFile);
        message = currentXmlFile;
        message += " saved to xml!";
        
        phrases.clear();
        words.clear();
        letters.clear();
        dialogs.clear();
        
        if (allLetters.size() > 0){
            setGetRecordAddressAll = allLetters.size()-1;//allWords.size()-1            
        }
        isGetAll = true;//this need a test
        isSavePhrase = false;
    
    }
    
    if (isClearDoc == true) {
        settingsRecordStringFile.clear();
        
        int numAboutTags = settingsRecordStringFile.getNumTags("about");
        
        if(numAboutTags == 0){
            //client about
            settingsRecordStringFile.addTag("about");
            settingsRecordStringFile.pushTag("about");
            settingsRecordStringFile.addValue("file", currentXmlFile);
            date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
            settingsRecordStringFile.addValue("DATE", date);
            settingsRecordStringFile.addValue("client","--dialogger-- Version: BETA.0");
            settingsRecordStringFile.addValue("authors", "Lee Meredith");
            settingsRecordStringFile.addValue("url","http://www.diamondsandcode.com");
            settingsRecordStringFile.addValue("github", "http://www.diamondsandcode.com");
            settingsRecordStringFile.popTag();
            //client end about
            
            //version
            settingsRecordStringFile.addTag("version");
            settingsRecordStringFile.pushTag("version");
            
            settingsRecordStringFile.addValue("major", 0);
            settingsRecordStringFile.addValue("minor", 6);
            settingsRecordStringFile.popTag();
            //end version 
            
            //recordString header
            settingsRecordStringFile.addTag("RECORD");
            settingsRecordStringFile.pushTag("RECORD", numAboutTags-1);
            date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
            settingsRecordStringFile.addValue("DATE", date);
            settingsRecordStringFile.addValue("artistName", recordArtistName);
            settingsRecordStringFile.addValue("setName", recordSetName);
            settingsRecordStringFile.addValue("audio", recordAudio);
            settingsRecordStringFile.addValue("format", recordFormat);
            settingsRecordStringFile.addValue("side", recordSide);
            settingsRecordStringFile.addValue("string", recordString);
            settingsRecordStringFile.addValue("dialogString", recordDialogString);
            settingsRecordStringFile.addValue("dialogImage", "record/dialog/images/bob_A_F/");
            
            settingsRecordStringFile.addValue("PHRASE", -1);
            settingsRecordStringFile.addValue("WORD", -1);
            settingsRecordStringFile.addValue("LETTER", -1);
            settingsRecordStringFile.addValue("DIALOG", -1);
            settingsRecordStringFile.addValue("ENDRECORD", -1);
            
            settingsRecordStringFile.popTag();
            settingsRecordStringFile.pushTag("RECORD", numAboutTags-1);
            
            settingsRecordStringFile.popTag();
        }
        isGetAll = true;
        isClearDoc = false;
    }
    
    if (clearTagCon == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            settingsRecordStringFile.clearTagContents(whoClearTagCon, 0);
            settingsRecordStringFile.addValue(whoClearTagCon, whichTagCon);
            settingsRecordStringFile.popTag();
            
            settingsRecordStringFile.saveFile(currentXmlFile);
            message = currentXmlFile;
            message += " saved to xml!";
        }
        clearTagCon = false;
    }
    
    if (isRemoveTag == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            settingsRecordStringFile.removeTag(whoClearTagCon, 0);
            settingsRecordStringFile.addValue(whoClearTagCon, whichTagCon);
            settingsRecordStringFile.popTag();
            settingsRecordStringFile.saveFile(currentXmlFile);
            message = currentXmlFile;
            message += " saved to xml!";
        }
        isRemoveTag = false;
    }
    
    if(isRemoveLastPhrase == true) {
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){ 
            int numberOfSavedPhrase = settingsRecordStringFile.getNumTags("PHRASE");
            int numberOfSavedWord = settingsRecordStringFile.getNumTags("WORD");
            int numberOfSavedLetter = settingsRecordStringFile.getNumTags("LETTER");
            int numberOfSavedDialog = settingsRecordStringFile.getNumTags("DIALOG");
            float myPhrases_0 = settingsRecordStringFile.getValue("PHRASE", 0.0, numberOfSavedPhrase-1);

            float myEndRec = settingsRecordStringFile.getValue("ENDRECORD", 0.0, 0);
            
            for(int i = numberOfSavedWord-1; i >= 0 ; i--){
                float myWord;
                myWord = settingsRecordStringFile.getValue("WORD", 0.0, i);
                if (myWord >= myPhrases_0) {
                    settingsRecordStringFile.removeTag("WORD", i);
                }
            }
            numberOfSavedWord = settingsRecordStringFile.getNumTags("WORD");
            if (numberOfSavedWord == 0) {
                settingsRecordStringFile.addValue("WORD", -1);
            }
            
            for(int i = numberOfSavedLetter-1; i >= 0; i--){
                float myLetter;
                myLetter = settingsRecordStringFile.getValue("LETTER", 0.0, i);
                if (myLetter >= myPhrases_0 ) {
                    settingsRecordStringFile.removeTag("LETTER", i);
                }
            }
            numberOfSavedLetter = settingsRecordStringFile.getNumTags("LETTER");
            if (numberOfSavedLetter == 0) {
                settingsRecordStringFile.addValue("LETTER", -1);
            }
            
            for(int i = numberOfSavedDialog-1; i >= 0; i--){
                float myDialog;
                myDialog = settingsRecordStringFile.getValue("DIALOG", 0.0, i);
                if (myDialog >= myPhrases_0 ) {
                    settingsRecordStringFile.removeTag("DIALOG", i);
                }
            }
            numberOfSavedDialog = settingsRecordStringFile.getNumTags("DIALOG");
            if (numberOfSavedDialog == 0) {
                settingsRecordStringFile.addValue("DIALOG", -1);
            }
            
            settingsRecordStringFile.removeTag("PHRASE", numberOfSavedPhrase-1);
            numberOfSavedPhrase = settingsRecordStringFile.getNumTags("PHRASE");
            if (numberOfSavedPhrase == 0) {
                settingsRecordStringFile.addValue("PHRASE", -1);
            }
            
            if (myEndRec >= 0) {
                settingsRecordStringFile.removeTag("ENDRECORD", 0);
                settingsRecordStringFile.addValue("ENDRECORD", -1);
            }
            
            settingsRecordStringFile.popTag();
        }
        settingsRecordStringFile.saveFile(currentXmlFile);
        //isGetPhrases = true; 
        isGetAll = true;
        isRemoveLastPhrase = false;
    }
    //-------------edit---------------_
    
    //At_Run----------------------_
    if (isAtRun == true) {
        //isGetPhrases = true;
        isGetAll = true;
        isAtRun = false;
    }
    //-----------At_Run-----------_
    
    if (allRecStartPhrases.size() > 0){
        recStartPhrases = allRecStartPhrases[setRecordAddress];
    }
}

//--------------------------------------------------------------
void recRecordString::updateAddress(float setRecordAddress){
	recordAddress = setRecordAddress;
}

//--------------------------------------------------------------
void recRecordString::updateString(string setRecordString){
    recordString = setRecordString;
}

//--------------------------------------------------------------
void recRecordString::updateDialogString(string setRecordDialogString, string setRecordDialogImages){
    recordDialogString = setRecordDialogString;
    recordDialogImages = setRecordDialogImages;
}

//--------------------------------------------------------------
void recRecordString::updateClearTagContents(string newWhoClearTagCon, string newWhichTagCon){
    whoClearTagCon = newWhoClearTagCon;
    whichTagCon = newWhichTagCon;
}

//--------------------------------------------------------------
void recRecordString::setRGBA(int setR, int setG, int setB, int setA){
    r = setR;
    g = setG;
    b = setB;
    a = setA;
}

//--------------------------------------------------------------
void recRecordString::updateInfo(string setArtistName, string setSetName, string setAudio, string setFormat, string setSide){
    recordArtistName = setArtistName;
    recordSetName = setSetName;
    recordAudio = setAudio;
    recordFormat = setFormat;
    recordSide = setSide;
}
//--------------------------------------------------------------
void recRecordString::draw(int setX, int setY, int setW, int setH){
    
    x = setX;
    y = setY;
    
	//---------
    ofFill();
	ofEnableAlphaBlending();
	ofSetColor(0, 0, 0, 200);
}

//--------------------------------------------------------------
void recRecordString::keyPressed  (int key){
    
    //get-----------------_
    if(key == '/'){
        xmlFileTest = "";
        setRecordAddressTest = -1;
        isGetDialogPlayBack = true;
        getDialogPlayBack = "well?!";
        isGetAll = true;
    }
    if(key == '?')isGetPhrases = true;
    if(key == OF_KEY_UP || key == 357){
        --setRecordAddress;
        if (setRecordAddress <= 0) {
            setRecordAddress = 0;
        }
        isGetAll = true;
        if (dBug == true)cout << "setRecordAddress " << setRecordAddress << endl;
    }
    if(key == OF_KEY_DOWN || key == 359){
        ++setRecordAddress;
        if (setRecordAddress >= settingsRecordStringFile.getNumTags("RECORD")) {
            setRecordAddress = settingsRecordStringFile.getNumTags("RECORD")-1;
        } 
        isGetAll = true;
        if (dBug == true)cout << "setRecordAddress " << setRecordAddress << endl;
    }
    if(key == ','){
        --setPhrasesAddress;
        if (setPhrasesAddress <= 0) {
            setPhrasesAddress = 0;
        }
        isGetPhrases = true; 
        if (dBug == true)cout << "setPhrasesAddress " << setPhrasesAddress << endl;
    }
    if(key == '.'){
        ++setPhrasesAddress;
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            if (setPhrasesAddress >= settingsRecordStringFile.getNumTags("PHRASE")) {
                setPhrasesAddress = settingsRecordStringFile.getNumTags("PHRASE")-1;
            }
            settingsRecordStringFile.popTag();
        }
        isGetPhrases = true; 
        if (dBug == true)cout << "setPhrasesAddress " << setPhrasesAddress << endl;
    }
    
    if(key == OF_KEY_RIGHT || key == 258){
		++setGetRecordAddressAll;
        if (setGetRecordAddressAll >= allLetters.size()) {  //allWords.size()
            setGetRecordAddressAll = allLetters.size()-1;   //allWords.size()-1
        }
        if (dBug == true)cout << " setGetRecordAddressAll                        " << setGetRecordAddressAll << endl;
	}
    if(key == OF_KEY_LEFT || key == 256){
		--setGetRecordAddressAll;
        if (setGetRecordAddressAll <= 0) {
            setGetRecordAddressAll = 0;
        }
        if (dBug == true)cout << " setGetRecordAddressAll " << setGetRecordAddressAll << endl;
	}
    //---------get--------_
    
    
    //edit----------------------------_
    //recordAddress = ofRandom(1,100);
    //no data gets saved unless you hit the s key
    if(key == '0')isClearDoc = true;
    //if(key == 'C')clearTagCon = true;
    //if(key == 'X')isRemoveTag = true;
    if(key == 'r'){
        isRemoveLastPhrase = true;
    }
    if(key == 'S'){
        isSaveAll = true;
        settingsRecordStringFile.saveFile(currentXmlFile);
        message = currentXmlFile;
        message += " saved to xml!";
        xmlFileTest = "";
        isGetAll = true;
        
        isGetAllIndexInRec = true;
        isGetStringPlayBack = true;
        getStringPlayBack = "getStringPlayBack!?";
        isGetDialogPlayBack = true;
        getDialogPlayBack = "getDialogPlayBack?!";
        setRecordAddressTest = -1;

    }
    if(key == 's'){
        xmlFileTest = "";
        isSavePhrase = true;
        isGetAll = true;
        isGetStringPlayBack = true;
        isGetDialogPlayBack = true;
    }
    
    if(key == 'P'){
        if (allWords.size() > 0) {
            if (recordAddress <= allWords[allWords.size()-1]) {
                float myPhrases;
                myPhrases = recordAddress;
                phrases.push_back(myPhrases);
            }
            if (recordAddress > allWords[allWords.size()-1]) {
                float myLetter;
                myLetter = recordAddress;
                letters.push_back(myLetter);
                float myWord;
                myWord = recordAddress;
                words.push_back(myWord);
                float myPhrases;
                myPhrases = recordAddress;
                phrases.push_back(myPhrases);
            }
        }else {
            float myLetter;
            myLetter = recordAddress;
            letters.push_back(myLetter);
            float myWord;
            myWord = recordAddress;
            words.push_back(myWord);
            float myPhrases;
            myPhrases = recordAddress;
            phrases.push_back(myPhrases);
        }
        isStartPhrase = true;
        isPhraseTest = false;
    }
    
    if(key == 'w'){
        float myWord;
        myWord = recordAddress;
        words.push_back(myWord);
        letters.push_back(myWord);
        dialogs.push_back(myWord);
    }
    
    if(key == 'L'){
        isPlayWord = !isPlayWord;
    }
    
    if(key == 'l'){
        isPlayLetter = !isPlayLetter;
    }
    
    if(key == 'd'){
        isPlayDialog = !isPlayDialog;
    }
    
    if(key == 'E'){
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            settingsRecordStringFile.removeTag("ENDRECORD", 0);
            settingsRecordStringFile.addValue("ENDRECORD", recordAddress);
            settingsRecordStringFile.popTag();
        }
        isGetAll = true;
        isGetStringPlayBack = true;
        isGetDialogPlayBack = true;
        xmlFileTest = "";
        settingsRecordStringFile.saveFile(currentXmlFile);
        message = currentXmlFile;
        message += " saved to xml!";
    }
    if(key == 'R' ){
        //lastRecTagNumber = settingsRecordStringFile.getNumTags("RECORD");
        //if( settingsRecordStringFile.pushTag("RECORD", lastRecTagNumber-1) ){
            //settingsRecordStringFile.removeTag("ENDRECORD", 0);
            //settingsRecordStringFile.addValue("ENDRECORD", recordAddress);
            //settingsRecordStringFile.popTag();
        //}
        
        lastRecTagNumber	= settingsRecordStringFile.addTag("RECORD");
        xmlStructure = "<RECORD>\n";
        if( settingsRecordStringFile.pushTag("RECORD", setRecordAddress) ){
            newRecArtistName = settingsRecordStringFile.getValue("artistName", "New");
            newRecSetName = settingsRecordStringFile.getValue("setName", "New");
            newRecAudio = settingsRecordStringFile.getValue("audio", "New");
            newRecFormat = settingsRecordStringFile.getValue("format", "New");
            newRecSide = settingsRecordStringFile.getValue("side", "New");
            newRecString = settingsRecordStringFile.getValue("string", "New");
            newRecDialogString = settingsRecordStringFile.getValue("dialogString", "New");
            newRecDialogImages = settingsRecordStringFile.getValue("dialogImage", "New");
            settingsRecordStringFile.popTag(); //pop position
        }
        //-------------
        
        if( settingsRecordStringFile.pushTag("RECORD", lastRecTagNumber) ){
            date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
            settingsRecordStringFile.addValue("DATE", date);
            settingsRecordStringFile.addValue("artistName", newRecArtistName);
            settingsRecordStringFile.addValue("setName", newRecSetName);
            settingsRecordStringFile.addValue("audio", newRecAudio);
            settingsRecordStringFile.addValue("format", newRecFormat);
            settingsRecordStringFile.addValue("side", newRecSide);
            settingsRecordStringFile.addValue("string", newRecString);
            settingsRecordStringFile.addValue("dialogString", newRecDialogString);
            settingsRecordStringFile.addValue("dialogImage", newRecDialogImages);//recordDialogImages
            
            //int tagNum = settingsRecordStringFile.addTag("PHRASE");
            //settingsRecordStringFile.setValue("PHRASE:WORD", recordAddress, tagNum);
            settingsRecordStringFile.popTag();
            //int tagNum = settingsRecordStringFile.addTag("REC");
            //settingsRecordStringFile.setValue("REC:ADDRESS", recordAddress, tagNum);
            settingsRecordStringFile.popTag();
        }
        float myLetter;
        myLetter = recordAddress;
        letters.push_back(myLetter);
        float myWord;
        myWord = recordAddress;
        words.push_back(myWord);
        float myPhrases;
        myPhrases = recordAddress;
        phrases.push_back(myPhrases);
        isStartPhrase = true;
        isPhraseTest = false;
        lastRecTagNumber = settingsRecordStringFile.getNumTags("RECORD");
        if( settingsRecordStringFile.pushTag("RECORD", lastRecTagNumber-1) ){
            settingsRecordStringFile.addValue("PHRASE", -1);
            settingsRecordStringFile.addValue("WORD", -1);
            settingsRecordStringFile.addValue("LETTER", -1);
            settingsRecordStringFile.addValue("DIALOG", -1);
            settingsRecordStringFile.addValue("ENDRECORD", -1);
            settingsRecordStringFile.popTag();
        }
    }
    //------------edit----------------_
}