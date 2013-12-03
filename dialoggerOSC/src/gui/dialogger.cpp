//NOTE: The AF system of dialog animation was developed by companies 
//like Hanna Barbera on the TV shows of the 1960s.
//http://www.angryanimator.com/word/2010/11/26/tutorial-3-dialog/
//http://www.idleworm.com/how/anm/03t/talk1.shtml
//http://www.mpi-inf.mpg.de/resources/FAM/publ/pg2002.pdf
//http://www.youtube.com/watch?v=btBwP4yG92I
//
//"Hello My Friend"
//"BCDEF ACD BECDCB"

#include "dialogger.h"

//--------------------------------------------------------------
void dialogger::setup(){

    //osc-----------------------_
    isFormOsc = isFullscreen = false;
    //receiver------------_
    setOscAddres = "/msp/pos/r";
    // listen on the given port
    port = 12345;
    host = "192.168.1.6";
	cout << "listening for osc messages on port " << port << "\n";
	receiver.setup(port);
    //------receiver------_
    //---------osc--------------_
    
    //ofDirectory------------------------_
    //Directory-Address-------_    
    recordAddressDir.listDir("record/address/");
	recordAddressDir.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order
    
    if ((int)recordAddressDir.size() == 0) {
        setCurrentDirByFile = setCurrentDirByFileTest = setRecordFileDefault = setRecordFile = recordFile = "forYou";// if no file in record/address/????.xml
        recRecordString_0.isSaveAll = true;
        recRecordString_0.isGetAll = true;
    }
    
    isJustAtRunFile = true;
    recAddressCurrentDir = 0;
    setCurrentDirByAddresTest = setCurrentDirByAddres = 0;
    isRecordAddressR = false;
    isRecordAddressL = false;
    isKeyFileRL = false;
    //---Directory-Address----_
    
    //Directory-Audio-------_
    recordAudioDir.listDir("record/dialog/audio/");
	recordAudioDir.sort(); 
    isKeyAudioRL = false;
    //----Directory-Audio---_
    
    //Directory-ImageFolder-------_
    dirDialogImageFolderStringDefault = "record/dialog/images/";
    dirDialogImageFolderString = dirDialogImageFolderStringDefault;
    dirDialogFolder.listDir(dirDialogImageFolderString);
	dirDialogFolder.sort();
    
    isJustAtRunDialogFolder = true;
    recImageFolderCurrentDir = 0;
    isRecordImageFolderL = false;
    isRecordImageFolderR = false;
    isKeyImageFolderRL = false;
    //----Directory-ImageFolder---_
    
    //Directory-Image-------_
    dirDialogImageStringDefault = "record/dialog/images/";
    dirDialogImageString = dirDialogImageStringDefault;
    setDirirDialogImageString = "bob_A_F";
    dirDialogImageString += setDirirDialogImageString;
    dirDialogImageString += "/";
    dirDialogImage.listDir(dirDialogImageString);
	dirDialogImage.sort();
    
	if(dirDialogImage.size()){
		images.assign(dirDialogImage.size(), ofImage());
	}
    
	for(int i = 0; i < (int)dirDialogImage.size(); i++){
		images[i].loadImage(dirDialogImage.getPath(i));
        if (i < 6) {
            myImage[i] = images[i];
        }
	}
    
    //allHitAreaImage-------------_
    isAddHitDialog = true;
    myImageNew = false;
    allHitAreaImage_0.setPosition(11, 500);
    allHitAreaImage_0.setDimensions();
    allHitAreaImage_0.setImage(myImage);
    //-------allHitAreaImage------_
    
    currentDialogImage = 0;
    setRecordImageFolderTest = dirDialogImageString;
    //----Directory-Image---_
    //-------------ofDirectory-----------_
    
    //dialogPlayer--------------_
    nameOfDirPathAudio = "record/dialog/audio/HMF.wav";
    dialogPlayer_0.setup(20, 450, "record/dialog/audio/HMF.wav");
    //-------dialogPlayer-------_
    
	ofBackground(75,75,75);
    date = ofToString(ofGetYear()) +"-"+ ofToString(ofGetMonth()) +"-"+ ofToString(ofGetDay()) +"-"+ ofToString(ofGetHours()) +"-"+ ofToString(ofGetMinutes())+"-"+ ofToString(ofGetSeconds());
    isSaveAll = isSavePhrase = isStartPhrase = isNothing = false;
    isPhraseTest = true;
    clearDoc = clearTagCon = false;
    recordAddress = 0.1;
    isSetAllDefault = true;
    isSetRecordFileDefault = isSetAudioDefault = isSetDialogImagesDefault = isSetDialogImagesFolderDefault = false;
    isKeyFile = isKeyArtistName = isKeySetName = isKeyAudio = isKeyRecFormat = isKeyRecSide = isKeyString = isKeyDiaString, isKeyDiaImage = false;
    recAddressCurrentDir = 0;
    for(int i = 0; i < (int)recordAddressDir.size(); i++){
		if(i == recAddressCurrentDir) {
            setCurrentDirByFile = setCurrentDirByFileTest = setRecordFileDefault = setRecordFile = recordFile = recordAddressDir.getName(i);
		}
	}
    setRecordStringDefault = setRecordString = recordString = "Hello My Friend";
    setRecordDialogStringDefault = setRecordDialogString = recordDialogString = "BCDEF ACD BECDCB";
    setRecordArtistNameDefault = setRecordArtistName = recordArtistName = "tesuji";
    setRecordSetNameDefault = setRecordSetName = recordSetName = "myset_0";
    setRecordAudioDefault = setRecordAudio = recordAudio = "HMF.wav"; 
    setRecordFormatDefault = setRecordFormat = recordFormat = "wav";
    setRecordSideDefault = setRecordSide = recordSide = "NA";
    setRecordImageFolderDefault = setRecordImageFolder = recordImageFolder = "bob_A_F"; // did i need this?
    setRecordImageDefault = setRecordImage = recordImage = "bob_A_F";
    
    setGetRecordAddress = setGetPhrasesAddress = setGetWordsAddress = setGetLettersAddress = setGetDialogAddress = setGetNothingsAddress = 0;
    
    //recRecordString------------------_
    graphRecString_X = 10;
    graphRecString_Y = 10;
    graphRecString_W = 100;
    graphRecString_H = 100;
    
    graphRecString_R = 255;
    graphRecString_G = 255;
    graphRecString_B = 255;
    graphRecString_A = 255;
    
    recRecordWhoClearTagCon = "artistName";
    recRecordWhichTagCon = "cat";
    isCanAllPlayBack = true;
    isPlayBackIn = true;
    isAllPlayBack = isIndexPlayBack = isConsecutivePlayBack = false;
    isAllPlayBackTest = isIndexPlayBackTest = isConsecutivePlayBackTest = false;
    isPlayWord = isPlayLetter = isPlayDialog = true;
    isNewWord = isNewLetter = false;
    wordPlayingTest = letterPlayingTest = " ";
    
    recRecordString_0.setup(graphRecString_X, graphRecString_Y, recordFile);
    recRecordString_0.updateString(recordString);
    recRecordString_0.updateAddress(dialogPlayer_0.getDialogPositionMS);
    recRecordString_0.updateDialogString(recordDialogString, recordImage);
    recRecordString_0.setRGBA(graphRecString_R, graphRecString_G, graphRecString_B, graphRecString_A);
    recRecordString_0.updateInfo(recordArtistName, recordSetName, recordAudio, recordFormat, recordSide);
    recRecordWhoClearTagCon = guiMessXML_0.getMessRecordXMLTag;
    recRecordString_0.updateClearTagContents(recRecordWhoClearTagCon, recRecordWhichTagCon);
    //--------recRecordString----------_
    
    //guiMessXML------------------------_
    addKeyIndexZero = 0;
    toAddZero = "";
    isDelAtIndexZero = false;
    guiMessXML_0.setup(20, 150, "record/message/message_presets.xml");
    guiGetRecMessXML_0.setup(20, 325, "record/message/message_presets.xml");
    guiMessXML_0.recIndex_Y = guiMessXML_0.maxNumInList;
    //-----------guiMessXML-------------_
    
    //osc-------------------------_
    stringToIntPort = "";
    guiOscMessXML_0.setup(ofGetWidth()-490, 230, "record/message/message_presets.xml");
    guiOscMessXML_0.port = setStringPort = ofToString(port);
    guiOscMessXML_0.host = setHost = host;
    guiOscMessXML_0.addras = setOscAddres;
    //-------------osc------------_
    
    //textImageDisplay----------_
    display.setPosition(400, 550);
    display.setDimensions();
    display.setImage(images[0]);
    //-----textImageDisplay-----_
    
    //imagePlaying-------------------------------_
    imagePlaying = images[currentDialogImage];
    isNewNameOfFileImage = false;
    getNameOfFileImageTest = getNameOfFileImage = guiMessXML_0.image;
    //---------------imagePlaying----------------_
    
    isGuiDraw = true;
}

//--------------------------------------------------------------
void dialogger::update(float newMouseX, float newMouseY){
    mouseX = newMouseX;
    mouseY = newMouseY;
    
    if (isFullscreen == false) {
        //ofSetWindowTitle("dialoggerOSC");
    }
    //ofDirectory------------------------_
    //Directory-Address-------_
    if (recordAddressDir.size() > 0 && isRecordAddressR == true){
		recAddressCurrentDir++;
		recAddressCurrentDir %= recordAddressDir.size();
        isRecordAddressR = false;
	}
    if (recordAddressDir.size() > 0 && isRecordAddressL == true){
		recAddressCurrentDir--;
        if (recAddressCurrentDir < 0) {
            recAddressCurrentDir = recordAddressDir.size()-1;
        }
        isRecordAddressL = false;
	}
    
    if (recordAddressDir.size() > 0){
        if (setCurrentDirByAddres < 0) {
            setCurrentDirByAddres = 0;
        }
        if (setCurrentDirByAddres >= recordAddressDir.size()) {
            setCurrentDirByAddres = recordAddressDir.size()-1;
        }
        if (isKeyFill == false && guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList){
            if (setCurrentDirByAddres != setCurrentDirByAddresTest){
                recAddressCurrentDir = setCurrentDirByAddres;
                for(int i = 0; i < (int)recordAddressDir.size(); i++){
                    if(i == recAddressCurrentDir) {
                        if (isKeyFile == false && isRecAddressCurrentDir == false){
                            setCurrentDirByFile = setCurrentDirByFileTest = setRecordFile = recordAddressDir.getName(i);
                        }
                    }
                }
                setCurrentDirByFile = setCurrentDirByFileTest = recRecordWhichTagCon = recordFile = setRecordFile;
                
                recRecordString_0.setRecordAddress = 0;
                recRecordString_0.isGetAll = true;
                
                setCurrentDirByAddresTest = setCurrentDirByAddres;
            }
        }else {
            setCurrentDirByAddresTest = setCurrentDirByAddres;
        }
    }
    
    if (isKeyFill == false && guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList){
        if (setCurrentDirByFile != setCurrentDirByFileTest && setRecordFile != setCurrentDirByFile) {
            int posLastDot = setCurrentDirByFile.rfind(".xml");
            if (posLastDot == 1) {
                setCurrentDirByFile.erase(setCurrentDirByFile.end()-4, setCurrentDirByFile.end());//erase the ".xml" from string
            }
            for(int i = 0; i < (int)recordAddressDir.size(); i++){
                string newSetRecFile = recordAddressDir.getName(i);
                newSetRecFile.erase(newSetRecFile.end()-4, newSetRecFile.end());//erase the ".xml" from string
                if(newSetRecFile == setCurrentDirByFile) {
                    setCurrentDirByAddresTest = setCurrentDirByAddres = i;
                }
            }
            setRecordFile = setCurrentDirByFile;
            if (setRecordFile != "") {     
                
                guiMessXML_0.recIndex_Y = guiMessXML_0.maxNumInList;
                recRecordWhichTagCon = recordFile = setRecordFile;
                
                //ofDirectory--------_
                recordAddressDir.listDir("record/address/");
                recordAddressDir.sort();
                //---ofDirectory-----_
                
            }
            recRecordString_0.setRecordAddress = 0;
            recRecordString_0.isSaveAll = true;
            recRecordString_0.isGetAll = true;
            guiMessXML_0.isFileEnter = false;
            setCurrentDirByFile = setCurrentDirByFileTest = setRecordFile;
        }
    }

    for(int i = 0; i < (int)recordAddressDir.size(); i++){
        //make if new?
		if(i == recAddressCurrentDir) {
            if (isKeyFile == false && isRecAddressCurrentDir == false){
               setRecordFile = recordAddressDir.getName(i);
            }
		}
	}
    //---Directory-Address----_
    
    //Directory-Audio-------_
    if (recordAudioDir.size() > 0 && isRecordAudioR == true){
		recAudioCurrentDir++;
		recAudioCurrentDir %= recordAudioDir.size();
        isKeyAudioRL = true;
        isRecordAudioR = false;
	}
    if (recordAudioDir.size() > 0 && isRecordAudioL == true){
		recAudioCurrentDir--;
        if (recAudioCurrentDir < 0) {
            recAudioCurrentDir = recordAudioDir.size()-1;
        }
        isKeyAudioRL = true;
        isRecordAudioL = false;
	}
    for(int i = 0; i < (int)recordAudioDir.size(); i++){
		if(i == recAudioCurrentDir) {
            if (isKeyAudio == false && isRecAudioCurrentDir == false){
                setRecordAudio = recordAudioDir.getName(i);
            }
		}
	}
    //----Directory-Audio---_
    
    //Directory-ImageFolder-------_
    if (dirDialogFolder.size() > 0 && isRecordImageFolderR == true){
		recImageFolderCurrentDir++;
		recImageFolderCurrentDir %= dirDialogFolder.size();
        isKeyImageFolderRL = true;
        isRecordImageFolderR = false;
	}
    if (dirDialogFolder.size() > 0 && isRecordImageFolderL == true){
		recImageFolderCurrentDir--;
        if (recImageFolderCurrentDir < 0) {
            recImageFolderCurrentDir = dirDialogFolder.size()-1;
        }
        isKeyImageFolderRL = true;
        isRecordImageFolderL = false;
	}
    for(int i = 0; i < (int)dirDialogFolder.size(); i++){
		if(i == recImageFolderCurrentDir) {
            if (isKeyDiaImage == false && isRecImageFolderCurrentDir == false){
                setRecordImageFolder = dirDialogFolder.getName(i);
            }
		}
	}
    //----Directory-ImageFolder---_
    
    //Directory-Image-------_
    if (dirDialogImage.size() > 0 && isImageR == true){
		currentDialogImage++;
		currentDialogImage %= dirDialogImage.size();
        isImageR = false;
	}
    if (dirDialogImage.size() > 0 && isImageL == true){
		currentDialogImage--;
        if (currentDialogImage < 0) {
            currentDialogImage = dirDialogImage.size()-1;
        }
        isImageL = false;
	}
    for(int i = 0; i < (int)dirDialogImage.size(); i++){
		if(i == recImageCurrentDir) {
            if (isKeyDiaImage == false && recImageCurrentDirTest == false){
                setRecordImage = dirDialogImage.getName(i);
            }
		}
	}
    
    int posLastSlash = setRecordImageFolder.rfind("/");
    if(posLastSlash > 0){
        if (setRecordImageFolder != setRecordImageFolderTest && setRecordImageFolder != "") {
            dirDialogImage.listDir(dirDialogImageString);
            dirDialogImage.sort();
            if( dirDialogImage.size() ){
                images.assign(dirDialogImage.size(), ofImage());
            }
            for(int i = 0; i < (int)dirDialogImage.size(); i++){
                images[i].loadImage(dirDialogImage.getPath(i));
                if (i < 6) {
                    myImage[i] = images[i];
                }
            }
            currentDialogImage = 0;
            myImageNew = true;
            setRecordImageFolderTest = setRecordImageFolder;
        }
    }
    
    if (setRecordImageFolder != setRecordImageFolderTest && setRecordImageFolder != "" && posLastSlash == 0) {
        dirDialogImageStringDefault = "record/dialog/images/";
        dirDialogImageString = dirDialogImageStringDefault;
        setDirirDialogImageString = setRecordImageFolder;
        dirDialogImageString += setDirirDialogImageString;
        recRecordWhichTagCon = dirDialogImageString += "/";
        dirDialogImage.listDir(dirDialogImageString);
        dirDialogImage.sort();
        if( dirDialogImage.size() ){
            images.assign(dirDialogImage.size(), ofImage());
        }
        for(int i = 0; i < (int)dirDialogImage.size(); i++){
            images[i].loadImage(dirDialogImage.getPath(i));
            if (i < 6) {
                myImage[i] = images[i];
            }
        }
        currentDialogImage = 0;
        setRecordImageFolderTest = setRecordImageFolder;
    }
    //currentDialogImage = recRecordString_0.getDialogIndex;
    currentDialogImage = recRecordString_0.getDialogDivisionIndex;
    //----Directory-Image---_
    //-------------ofDirectory-----------_
    
    //osc-----------------------_
    if (isFormOsc == true){
        if (isKeyPort == false &&
            isKeyHost == false && 
            isKeyOscAddres == false) {
            isKeyFill = false;
        }else {
            isIndexPlayBack = isConsecutivePlayBack = false;
            isKeyFill = true;
        }
    }
    
    if (isPlayBackIn == false) {
        //oscSendMax
        /*
         eveTime = beatSet0.bpm_0.totalTime;
         if (eveTime >= 1 && eveTime != eveTimeTest) {
         ofxOscMessage sm;
         sm.setAddress( "/max/evet" );
         sm.addIntArg( eveTime );
         cout<< "max_evet: "<<eveTime<<endl;
         sender.sendMessage( sm );
         eveTimeTest = eveTime;
         }
         */
        
        //receiver------------_
        for ( int i=0; i<NUM_MSG_STRINGS; i++ )
        {
            if ( timers[i] < ofGetElapsedTimef() )
                msg_strings[i] = "";
        }
        while( receiver.hasWaitingMessages() )
        {
            ofxOscMessage m;
            receiver.getNextMessage( &m );
            
            if ( m.getAddress() == setOscAddres )
            {
                recordAddress = m.getArgAsFloat(0);
            }
            else {
                string msg_string;
                msg_string = m.getAddress();
                msg_string += ": ";
                for ( int i=0; i<m.getNumArgs(); i++ )
                {
                    msg_string += m.getArgTypeName( i );
                    msg_string += ":";
                    if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
                        msg_string += ofToString( m.getArgAsInt32( i ) );
                    else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
                        msg_string += ofToString( m.getArgAsFloat( i ) );
                    else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
                        msg_string += m.getArgAsString( i );
                    else
                        msg_string += "unknown";
                }
                msg_strings[current_msg_string] = msg_string;
                timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
                current_msg_string = ( current_msg_string + 1 ) % NUM_MSG_STRINGS;
                msg_strings[current_msg_string] = "";
            }
        }
    }
    //------receiver------_
    //osc-----------------------_ 
    
    //playBack--------------_
    if (isPlay == true) {
        dialogPlayer_0.isPlay = true;
        isPlay = false;
    }
    
    if (isAllPlayBack != isAllPlayBackTest && isCanAllPlayBack == true){
        recRecordString_0.isPlayWord = isPlayWord = true;
        recRecordString_0.isPlayLetter = isPlayLetter = true;
        recRecordString_0.isPlayDialog = isPlayDialog = true;
        isSetAllDefault = true;
        isAllPlayBackTest = isAllPlayBack;
    }
    
    recRecordString_0.isPlayWord = isPlayWord;
    recRecordString_0.isPlayLetter = isPlayLetter;
    recRecordString_0.isPlayDialog = isPlayDialog;
    
    if (isIndexPlayBack != isIndexPlayBackTest && isKeyFill == false){
        if (isIndexPlayBack == true) {
            isConsecutivePlayBackTest = isConsecutivePlayBack = false;
        }
        isSetAllDefault = true;
        isIndexPlayBackTest = isIndexPlayBack;
    }
    if (isConsecutivePlayBack != isConsecutivePlayBackTest && isKeyFill == false){
        if (isConsecutivePlayBack == true) {
            isIndexPlayBackTest = isIndexPlayBack = false;
            dialogPlayer_0.isEdit = false;
        }
        if (isConsecutivePlayBack == false) {
            dialogPlayer_0.isEdit = true;
            recRecordString_0.isConsecPlayBackLast = dialogPlayer_0.isPlay = recRecordString_0.isConsecutivePlayBack = isConsecutivePlayBack = false;
        }
        isSetAllDefault = true;
        isConsecutivePlayBackTest = isConsecutivePlayBack;
    }
    //-------playBack-------_
    
    
    //recRecordString------------------_
    if (isPlayBackIn == true) {
        recordAddress = dialogPlayer_0.getDialogPositionMS;
    }
    //playBack--------------_
    if (isAllPlayBack == true) {
        if (dialogPlayer_0.isPlayTest == true || isPlayBackIn == true) {
            recRecordString_0.isPlayBack = true;
        }
        if (isFormOsc == true && isPlayBackIn == false) {
            recRecordString_0.isPlayBack = true;
        }
    }else {
        recRecordString_0.isPlayBack = false;
    }
    if (isPlayBackIn == true) {
        dialogPlayer_0.isPlayTest = false;
    }
    if (isKeyFill == true || isCanAllPlayBack == false){
        if (guiMessXML_0.recIndex_Y != 8) {
            isCanAllPlayBack = false;
        }
        isAllPlayBack = false;
    }
    if (isKeyFill == false){
        isCanAllPlayBack = true;
    }
    //-------playBack-------_
    
    recRecordString_0.updateString(recordString);
    recRecordString_0.updateAddress(recordAddress);
    if(isIndexPlayBack == true && isAllPlayBack == true){
        recRecordString_0.isIndexPlayBack = true;        
    }
    if(isConsecutivePlayBack == true && isAllPlayBack == true){
        recRecordString_0.isConsecutivePlayBack = true;
        dialogPlayer_0.setPos = recRecordString_0.recStartPhrases;
        if (recRecordString_0.isConsecutivePBAudio == true) {
            dialogPlayer_0.isPlay = recRecordString_0.isConsecutivePBAudio;
            recRecordString_0.isConsecutivePBAudio = false;
        }
        if (recRecordString_0.isConsecPlayBackLast == true) {
            recRecordString_0.isConsecPlayBackLast = dialogPlayer_0.isPlay = recRecordString_0.isConsecutivePlayBack = isConsecutivePlayBack = false;
        }
    }
    if(isConsecutivePlayBack == false){
        
    }
    
    recRecordString_0.updateDialogString(recordDialogString, recordImage);
    recRecordString_0.setRGBA(graphRecString_R, graphRecString_G, graphRecString_B, graphRecString_A);
    recRecordString_0.updateInfo(recordArtistName, recordSetName, recordAudio, recordFormat, recordSide);
    recRecordWhoClearTagCon = guiMessXML_0.getMessRecordXMLTag;
    recRecordString_0.updateClearTagContents(recRecordWhoClearTagCon, recRecordWhichTagCon);
    recRecordString_0.update(recordFile);
    
    if (recRecordString_0.wordPlaying != wordPlayingTest) {
        isNewWord = true;
        wordPlaying = recRecordString_0.wordPlaying;
        wordPlayingTest = recRecordString_0.wordPlaying;
    }else {
        isNewWord = false;
    }
    if (recRecordString_0.letterPlaying != letterPlayingTest) {
        isNewLetter = true;
        letterPlaying = recRecordString_0.letterPlaying;
        letterPlayingTest = recRecordString_0.letterPlaying;
    }else {
        isNewLetter = false;
    }
    //--------recRecordString----------_
    
    //guiMessXML------------------------_
    if (isKeyFile == false &&
        isKeyArtistName == false && 
        isKeySetName == false && 
        isKeyAudio == false && 
        isKeyRecFormat == false && 
        isKeyRecSide == false && 
        isKeyString == false && 
        isKeyDiaString == false &&
        isKeyDiaImage == false) {
        isKeyFill = false;
    }else {
        isIndexPlayBack = isConsecutivePlayBack = false;
        isKeyFill = true;
    }
    if (guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList) {
        isKeyFile = isKeyArtistName = isKeySetName = isKeyAudio = isKeyRecFormat = isKeyRecSide = isKeyString = isKeyDiaString, isKeyDiaImage = false;
    }
    if (recRecordString_0.allWords.size() > 0) {
        
        //Directory-Audio-------_
        nameOfDirPathAudio = "record/dialog/audio/";
        nameOfDirPathAudio += recRecordString_0.guiAudio;
        //----Directory-Audio---_
        
        //Directory-ImageFolder-------_
        string settingsImageDirectory = recRecordString_0.guiRecDialogImages;
        int posLastSlashImageDirectory = settingsImageDirectory.rfind("/");
        if(posLastSlashImageDirectory > 0)settingsImageDirectory.erase(settingsImageDirectory.begin()+posLastSlashImageDirectory, settingsImageDirectory.end());
        else settingsImageDirectory = "";
        
        posLastSlashImageDirectory = settingsImageDirectory.rfind("/");
        char thisStringImage = settingsImageDirectory.find_last_of("/\\");
        string nameOfFileImage;
        string nameOfDirPathImage;
        if(posLastSlashImageDirectory > 0){
            
            nameOfFileImage = settingsImageDirectory.substr(thisStringImage+1);
            
            nameOfDirPathImage = settingsImageDirectory.substr(0, thisStringImage);
            nameOfDirPathImage += "/";
        }
        //----Directory-ImageFolder---_
        if (guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList) {
            guiMessXML_0.file = recRecordString_0.currentXmlFile;
            guiMessXML_0.dateTime = recRecordString_0.guiDateTime;
            guiMessXML_0.artist = recRecordString_0.guiArtist;
            guiMessXML_0.set = recRecordString_0.guiSet;
            guiMessXML_0.audio = recRecordString_0.guiAudio;
            guiMessXML_0.format = recRecordString_0.guiFormat;
            guiMessXML_0.side = recRecordString_0.guiSide;
            guiMessXML_0.recString = recRecordString_0.guiRecString;
            guiMessXML_0.recDialog = recRecordString_0.guiRecDialog;
            guiMessXML_0.image = nameOfFileImage;
            if (isSetAllDefault == true || recRecordString_0.isIndexPlayBackNew == true) {
                setRecordFile = setRecordFileDefault = recRecordString_0.currentXmlFile;
                setRecordArtistName = setRecordArtistNameDefault = recRecordString_0.guiArtist;
                setRecordSetName = setRecordSetNameDefault = recRecordString_0.guiSet;
                setRecordAudio = setRecordAudioDefault = nameOfDirPathAudio;
                setRecordFormat = setRecordFormatDefault = recRecordString_0.guiFormat;
                setRecordSide = setRecordSideDefault = recRecordString_0.guiSide;
                setRecordString = setRecordStringDefault = recRecordString_0.guiRecString;
                setRecordDialogString = setRecordDialogStringDefault = recRecordString_0.guiRecDialog;
                setRecordImageFolder = setRecordImageFolderDefault = recRecordString_0.guiRecDialogImages;
                setRecordImage = setRecordImageDefault = nameOfFileImage;
                recRecordString_0.isIndexPlayBackNew = false;//this is the only plase this is turn false;
                isSetAllDefault = false;
            }
        }
        
        if (guiMessXML_0.recIndex_Y != guiMessXML_0.maxNumInList) {
            
            if (isSetRecordFileDefault == true) {
                guiMessXML_0.file = setRecordFileDefault;
            }else {
                guiMessXML_0.file = setRecordFile;
            }
            guiMessXML_0.dateTime = recRecordString_0.guiDateTime;
            guiMessXML_0.artist = setRecordArtistName;
            guiMessXML_0.set = setRecordSetName;
            if (isSetAudioDefault == true) {
                guiMessXML_0.audio = setRecordAudioDefault;
            }else {
                guiMessXML_0.audio = setRecordAudio;
            }
            guiMessXML_0.format = setRecordFormat;
            guiMessXML_0.side = setRecordSide;
            guiMessXML_0.recString = setRecordString;
            guiMessXML_0.recDialog = setRecordDialogString;
            if (isSetDialogImagesDefault == true) {
                guiMessXML_0.image = setRecordImageFolderDefault;
            }else {
                guiMessXML_0.image = setRecordImageFolder;
            }
            isSetAllDefault = true;
        }
        
        guiGetRecMessXML_0.recordValSize = recRecordString_0.setRecordAddress+1;
        guiGetRecMessXML_0.phraseValSize = recRecordString_0.setGetPhrasesAddress+1;
        guiGetRecMessXML_0.wordValSize = recRecordString_0.setGetWordsAddress+1;
        guiGetRecMessXML_0.endRecValSize = 1;
        
        guiGetRecMessXML_0.recordVal = recRecordString_0.guiRecordVal;
        guiGetRecMessXML_0.phraseVal = recRecordString_0.guiPhraseVal;
        guiGetRecMessXML_0.wordVal = recRecordString_0.guiWordVal;
        guiGetRecMessXML_0.endRecVal = recRecordString_0.guiEndRecVal;
        
        ofColor isColorEnd_0;
        ofColor isColorEnd_1;
        isColorEnd_0.r = 0;
        isColorEnd_0.g = 255;
        isColorEnd_0.b = 0;
        isColorEnd_1.r = 0;
        isColorEnd_1.g = 200;
        isColorEnd_1.b = 0;
        guiGetRecMessXML_0.recRecordFloatColor = isColorEnd_1;
        if (recRecordString_0.isPhrasesAddressEnd == false) {
            guiGetRecMessXML_0.phraseFloatColor = isColorEnd_0;
        }else {
            guiGetRecMessXML_0.phraseFloatColor = isColorEnd_1;
        }
        if (recRecordString_0.isWordsAddressEnd == false) {
            guiGetRecMessXML_0.wordFloatColor = isColorEnd_0;
        }else {
            guiGetRecMessXML_0.wordFloatColor = isColorEnd_1;
        }
        if (recRecordString_0.isPhrasesAddressEnd == false) {
            guiGetRecMessXML_0.endRecFloatColor = isColorEnd_0;
        }else {
            guiGetRecMessXML_0.endRecFloatColor = isColorEnd_1;
        }
        guiGetRecMessXML_0.phraseFloatColor;
        guiGetRecMessXML_0.wordFloatColor;
        guiGetRecMessXML_0.endRecFloatColor;
    }
    if (isGuiDraw == true)guiMessXML_0.checkHit(mouseX, mouseY);
    guiMessXML_0.update(20, 150, "record/message/message_presets.xml");
    if (isGuiDraw == true)guiGetRecMessXML_0.checkHit(mouseX, mouseY);
    guiGetRecMessXML_0.update(20, 325, "record/message/message_presets.xml");
    guiOscMessXML_0.port = setStringPort;
    guiOscMessXML_0.host = setHost;
    guiOscMessXML_0.addras = setOscAddres;
    if (isGuiDraw == true)guiOscMessXML_0.checkHit(mouseX, mouseY);
    guiOscMessXML_0.update(ofGetWidth()-490, 150, "record/message/message_presets.xml");
    //-----------guiMessXML-------------_
    
    //dialogPlayer--------------_
    if (isGuiDraw == true)dialogPlayer_0.checkHit(mouseX, mouseY);
    if (isPlayBackIn == true) {
        dialogPlayer_0.update(20, 450, nameOfDirPathAudio);
        if (isIndexPlayBack == false && isConsecutivePlayBack == false) {
            dialogPlayer_0.isEdit = true;
        }
    }
    //-------dialogPlayer-------_
    
    //allHitAreaImage-------------_
    if (isGuiDraw == true)allHitAreaImage_0.checkHit(mouseX, mouseY);
    allHitAreaImage_0.setDimensions();
    if (myImageNew == true) {
        cout << myImageNew << endl;
        myImageNew = false;
    }
    allHitAreaImage_0.setImage(myImage);
    if (guiMessXML_0.recIndex_Y == 8){
        if (allHitAreaImage_0.isHitOk == true && isAddHitDialog == true) {
            if (isKeyDiaString == true){
                if (setRecordDialogString.size() > 0) {
                    addKeyIndexZero++;
                    if (isDelAtIndexZero == true) {
                        guiMessXML_0.stringIndexRightLeft++;
                        toAddZero += hitDialogIndex;
                        if (toAddZero.size() > 1) {
                            toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                        }
                        setRecordDialogString.insert(0, toAddZero);
                        setRecordDialogString.erase(setRecordDialogString.begin(), setRecordDialogString.end()-stringSizeWas);
                        setRecordDialogString.insert(0, toAddZero);
                        
                    }
                    if (isDelAtIndexZero == false) {
                        guiMessXML_0.stringIndexRightLeft++;
                        setRecordDialogString.insert(guiMessXML_0.stringIndexRightLeft, hitDialogIndex);
                    }
                }
                
                if (setRecordDialogString.size() <= 0) {
                    guiMessXML_0.stringIndexRightLeft = 0;
                    setRecordDialogString += hitDialogIndex;
                }
                guiMessXML_0.stringSize = setRecordDialogString.size();
            }
        }
        isAddHitDialog = false;
    }
    //-------allHitAreaImage------_
    
    //imagePlaying-------------------------------_
    imagePlaying = images[currentDialogImage];
    
    if (guiMessXML_0.image != getNameOfFileImageTest) {
        isNewNameOfFileImage = true;
        getNameOfFileImageTest = getNameOfFileImage = guiMessXML_0.image;
    }else {
        isNewNameOfFileImage = false;
    }
    //---------------imagePlaying----------------_
}

//--------------------------------------------------------------
void dialogger::draw(bool newIsGuiDraw){
    
    isGuiDraw = newIsGuiDraw;
    
	//---------
    
	
	//ofSetColor(240, 240, 225);
    if (isGuiDraw == true) {
        //recRecordString------------------_
        recRecordString_0.draw(graphRecString_X, graphRecString_Y, graphRecString_W, graphRecString_H);
        //--------recRecordString----------_
        
        //guiMessXML------------------------_
        guiMessXML_0.draw();
        guiGetRecMessXML_0.draw();
        if (isPlayBackIn == true) {
            dialogPlayer_0.playRecordRectColor.set(0, 0, 255, 40);
            guiOscMessXML_0.playRecordRectColor.set(100, 100, 100, 40);
        }else {
            dialogPlayer_0.playRecordRectColor.set(255, 255, 255, 10);
            guiOscMessXML_0.playRecordRectColor.set(175, 0, 153, 150);
        }
        guiOscMessXML_0.draw();
        //-----------guiMessXML-------------_
        
        //ofDirectory------------------------_
        ofSetColor(ofColor::gray);
        if (dirDialogImage.size() > 0){
            ofSetColor(ofColor::white);
            //images[currentDialogImage].draw(300,220);
            //textImageDisplay----------_
            display.setImage(images[currentDialogImage]);
            //-----textImageDisplay-----_
        }
        //-------------ofDirectory-----------_
        
        //textImageDisplay----------_
        display.draw(ofGetWidth()-680, ofGetHeight()-525, recRecordString_0.wordPlaying, recRecordString_0.letterPlaying);
        //-----textImageDisplay-----_
        
        //dialogPlayer--------------_
        dialogPlayer_0.draw();
        //-------dialogPlayer-------_
        
        //allHitAreaImage-------------_
        allHitAreaImage_0.draw(0, 500);
        //-------allHitAreaImage------_
        
        if (isAllPlayBack == false) {
            //display-------------------_
            display.isImageBig = false;
            //----------display---------_
            
            //ofBackground(0);
            //bFullscreen
            string s = string("") + 
            "\n" + 
            "KEYS / MOUSE: \n" + 
            "\n" +
            "Audio \n" +
            "\n" +
            " num '1' Play Audio \n" +
            " num '2' Paused Audio \n" +
            " num '3' Display Word, Letter and Dialog. \n" +
            " 'c' Consecutive \n" +
            " 'i' Index the Addres \n" +
            "\n" +
            "Data Logging \n" +
            "\n" +
            " num '0' Clear Doc!" +
            "\n" +
            " 'E' END REC \n" +
            " 'r' Remove Last Phrase. \n" +
            " 'R' Makes A New REC. \n" +
            " 's' Save Phrase / Will Undo Clear Doc, If Not All Saved. \n" +
            " 'S' All Saved \n" +
            " 'P' Phrase, Word, Letter, Dialog \n" + 
            " 'w' Word, Letter, Dialog \n" +
            " Mouse Pressed The Form Field, Audio IN, OSC Receiver. \n" +
            "\n" +
            "In Form Field \n" +
            "\n" +
            " If No File Found It Will Make File After 'Enter' is Pressed. \n" +
            " 'Del', Key, 'Enter' or 'LEFT' / 'RIGHT' \n" +
            " Mouse Pressed A-F Pic\n" +
            "\n" +
            "Out Form Field \n" +
            "\n" +
            " '|' To Switch To Draw Gui. \n"+
            " 'f' To Switch To Full Screen. \n"+
            " 'd' Display Dialog \n"+
            " 'L' Display Word \n"+
            " 'l' Display Letter \n"+
            " 'LEFT' / 'RIGHT' Cycle Data Logged. \n" +
            " 'UP' / 'DOWN' Cycle REC \n" + 
            " '<' , '>' or 'TAB' Cycle the Form Field. \n" +
            "\n";
            
            //glDisable(GL_CULL_FACE);
            ofSetColor(255);
            //ofDisableLighting();
            ofDrawBitmapString(s, ofPoint(ofGetWidth()-490, ofGetHeight()-524));
            
            ofDrawBitmapString(isIndexPlayBack ? "is set Index PlayBack" : " ", 10, ofGetHeight()-20);
            ofDrawBitmapString(isConsecutivePlayBack ? "is set Consecutive PlayBack" : " ", 10, ofGetHeight()-20);
            //glEnable(GL_CULL_FACE);
        }else {
            
            ofDrawBitmapString(isIndexPlayBack ? "is set Index PlayBack" : " ", 10, ofGetHeight()-20);
            ofDrawBitmapString(isConsecutivePlayBack ? "is set Consecutive PlayBack" : " ", 10, ofGetHeight()-20);
            //display-------------------_
            display.isImageBig = true;
            //----------display---------_
        }
    }
    
    if (isGuiDraw == false) {
        if (images.size() > 0){
            ofSetColor(ofColor::white);
            images[currentDialogImage].draw(0,0);
        }
    }
    
    int posLastSlash = recRecordString_0.guiRecDialogImages.rfind("/");
    if(posLastSlash > 0 && guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList){
        if (recRecordString_0.guiRecDialogImages != setRecordImageFolderTest && recRecordString_0.guiRecDialogImages != "") {
            dirDialogImage.listDir(recRecordString_0.guiRecDialogImages);
            dirDialogImage.sort();
            if( dirDialogImage.size() ){
                images.assign(dirDialogImage.size(), ofImage());
            }
            for(int i = 0; i < (int)dirDialogImage.size(); i++){
                images[i].loadImage(dirDialogImage.getPath(i));
                if (i < 6) {
                    myImage[i] = images[i];
                }
            }
            allHitAreaImage_0.imageWTest = 0;
            currentDialogImage = 0;
            setRecordImageFolderTest = setRecordImageFolder;
        }
    }
}

//--------------------------------------------------------------
void dialogger::keyPressed  (int key){
    if (key == 'K') {
        cout << " welllll " << endl;
        isSetAllDefault = true;
    }
    if (isGuiDraw == true) {
        //playBack--------------_
        if(key == '3' && isCanAllPlayBack == true){
            isAllPlayBack = !isAllPlayBack;
        }
        if(key == 'i' && isKeyFill == false){
            isIndexPlayBack = !isIndexPlayBack;
        }
        if(key == 'c' && isKeyFill == false){
            isConsecutivePlayBack = !isConsecutivePlayBack;
        }
        if(key == 'L' && isKeyFill == false){
            isPlayWord = !isPlayWord;
        }
        if(key == 'l' && isKeyFill == false){
            isPlayLetter = !isPlayLetter;
        }
        if(key == 'd' && isKeyFill == false){
            isPlayDialog = !isPlayDialog;
        }
        //-------playBack-------_
        
        if (isFormOsc == false) {
            //dialogPlayer--------------_
            if (isKeyFill == false)dialogPlayer_0.keyPressed(key);
            //-------dialogPlayer-------_
            
            //recRecordString------------------_
            if (isKeyFill == false && guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList) {
                recRecordString_0.keyPressed(key);
                if(key == OF_KEY_DOWN || key == 359 || key == OF_KEY_UP || key == 357){
                    isSetAllDefault = true;
                    //recRecordString_0.isGetPhrases = true;
                    recRecordString_0.isGetAll = true;
                    //playBack--------------_
                    //isAllPlayBack = false;
                    //-------playBack-------_
                }
                isSetRecordFileDefault = isSetAudioDefault = isSetDialogImagesDefault = isSetDialogImagesFolderDefault = true;
                recAddressCurrentDir = recordAddressDir.size()-1;
                recAudioCurrentDir = recordAudioDir.size()-1;
                recImageFolderCurrentDir = dirDialogFolder.size()-1;
            }
            //--------recRecordString----------_
            
            //ofDirectory------------------------_
            //Directory-Address-------_
            if (isKeyFill == false && isKeyFile == false && guiMessXML_0.recIndex_Y == 0) {        
                if(key == OF_KEY_RIGHT || key == 258){
                    if (setRecordFile != "") {     
                        if (isJustAtRunFile == true) {
                            recAddressCurrentDir = 0;
                            for(int i = 0; i < (int)recordAddressDir.size(); i++){
                                if(i == recAddressCurrentDir) {
                                    setRecordFileDefault = setRecordFile = recordFile = recordAddressDir.getName(i);
                                }
                            }
                            isJustAtRunFile = false;
                        }
                    }
                    isKeyFileRL = true;
                    isRecAddressCurrentDir = false;
                    isSetRecordFileDefault = false;
                    isRecordAddressR = true;
                }
                if(key == OF_KEY_LEFT || key == 256){
                    if (setRecordFile != "") {     
                        if (isJustAtRunFile == true) {
                            recAddressCurrentDir = 0;
                            for(int i = 0; i < (int)recordAddressDir.size(); i++){
                                if(i == recAddressCurrentDir) {
                                    setRecordFileDefault = setRecordFile = recordFile = recordAddressDir.getName(i);
                                }
                            }
                            isJustAtRunFile = false;
                        }
                    }
                    isKeyFileRL = true;
                    isRecAddressCurrentDir = false;
                    isSetRecordFileDefault = false;
                    isRecordAddressL = true;
                }
            }
            //---Directory-Address----_
            
            //Directory-Audio-------_
            if (isKeyFill == false && isKeyAudio == false && guiMessXML_0.recIndex_Y == 4) {
                if(key == OF_KEY_RIGHT || key == 258){
                    isRecAudioCurrentDir = false;
                    isSetAudioDefault = false;
                    isRecordAudioR = true;
                }
                if(key == OF_KEY_LEFT || key == 256){
                    isRecAudioCurrentDir = false;            
                    isSetAudioDefault = false;
                    isRecordAudioL = true;
                }
            }
            if (guiMessXML_0.recIndex_Y == 4){
                //dialogPlayer--------------_
                // dialogPlayer_0.keyPressed(key);
                //-------dialogPlayer-------_
            }
            //----Directory-Audio---_
            
            //Directory-ImageFolder-------_
            if (isKeyFill == false && isKeyDiaImage == false && guiMessXML_0.recIndex_Y == 9) {
                if(key == OF_KEY_RIGHT || key == 258){
                    isRecImageFolderCurrentDir = false;
                    isSetDialogImagesFolderDefault = false;
                    isSetDialogImagesDefault = false;
                    isRecordImageFolderR = true;
                }
                if(key == OF_KEY_LEFT || key == 256){
                    isRecImageFolderCurrentDir = false;
                    isSetDialogImagesFolderDefault = false;
                    isSetDialogImagesDefault = false;
                    isRecordImageFolderL = true;
                }
            }
            //----Directory-ImageFolder---_
            
            //Directory-Image-------_
            if (isKeyFill == false && isKeyDiaImage == false && guiMessXML_0.recIndex_Y == 9) {
                if(key == OF_KEY_UP || key == 357){
                    recImageCurrentDirTest = false;
                    isSetDialogImagesDefault = false;
                    isImageR = true;
                }
                if(key == OF_KEY_DOWN || key == 359){
                    recImageCurrentDirTest = false;
                    isSetDialogImagesDefault = false;
                    isImageL = true;
                }
            }
            //----Directory-Image---_
            //-------------ofDirectory-----------_
            
            //letterForm----------------------_
            if ( guiMessXML_0.recIndex_Y != 0
                && guiMessXML_0.recIndex_Y != 4
                && guiMessXML_0.recIndex_Y != 9
                && guiMessXML_0.recIndex_Y != guiMessXML_0.maxNumInList
                && isKeyFill == false) {
                if (key == OF_KEY_RIGHT || key == 258) {
                    guiMessXML_0.isRight = true;
                } 
                if (key == OF_KEY_LEFT || key == 256) {
                    guiMessXML_0.isLeft = true;
                }
            }
            if(key == '<') {
                guiMessXML_0.isDownList = true;
                if (guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList) {//is this needed
                    recordAddressDir.listDir("record/address/");
                    recordAddressDir.sort();
                }
                isSetAllDefault = true;
                //recRecordString_0.isGetPhrases = true;
                isKeyFileRL = isKeyAudioRL = isKeyImageFolderRL = false;
                recRecordString_0.isGetAll = true;
            } else if (key == '>' || key == 9) {
                guiMessXML_0.isUpList = true;
                if (guiMessXML_0.recIndex_Y == guiMessXML_0.maxNumInList) {
                    recordAddressDir.listDir("record/address/");
                    recordAddressDir.sort();
                }
                isSetAllDefault = true;
                isKeyFileRL = isKeyAudioRL = isKeyImageFolderRL = false;
                recRecordString_0.isGetAll = true;
            } else if(key == OF_KEY_RETURN || key == 13) {
                addKeyIndexZero = 0;
                toAddZero = "";
                isDelAtIndexZero = false;
                guiMessXML_0.isSetCursorAtSizeZero_X = false;
                
                if (guiMessXML_0.recIndex_Y == 0) {
                    if (setRecordFile != "" && isKeyFileRL == true) {     
                        if (isJustAtRunFile == true) {
                            recAddressCurrentDir = 0;
                            for(int i = 0; i < (int)recordAddressDir.size(); i++){
                                if(i == recAddressCurrentDir) {
                                    setRecordFileDefault = setRecordFile = recordFile = recordAddressDir.getName(i);
                                }
                            }
                            isJustAtRunFile = false;
                        }else {
                            guiMessXML_0.recIndex_Y = guiMessXML_0.maxNumInList;
                            recRecordWhichTagCon = recordFile = setRecordFile;
                        }
                        //ofDirectory--------_
                        recordAddressDir.listDir("record/address/");
                        recordAddressDir.sort();
                        //---ofDirectory-----_
                        isKeyFileRL = false;
                        isKeyFile = false;
                    }
                    recRecordString_0.setRecordAddress = 0;
                    recRecordString_0.isSaveAll = true;
                    recRecordString_0.isGetAll = true;
                    guiMessXML_0.isFileEnter = false;
                }
                if (guiMessXML_0.recIndex_Y == 2) {
                    recRecordWhichTagCon = recordArtistName = setRecordArtistName;
                    recRecordString_0.isRemoveTag = true;
                    isKeyArtistName = false;
                    guiMessXML_0.isArtistEnter = false;
                }
                if (guiMessXML_0.recIndex_Y == 3) {
                    recRecordWhichTagCon = recordSetName = setRecordSetName;
                    recRecordString_0.isRemoveTag = true;
                    isKeySetName = false;
                    guiMessXML_0.isSetEnter = false;
                }
                if (guiMessXML_0.recIndex_Y == 4) {
                    if (setRecordAudio != "" && isKeyAudioRL == true){
                        recRecordWhichTagCon = recordAudio = setRecordAudio;
                        //ofDirectory--------_
                        recordAudioDir.listDir("record/dialog/audio/");
                        recordAudioDir.sort();
                        //---ofDirectory-----_
                        isKeyAudioRL = false;
                        recRecordString_0.isRemoveTag = true;
                        isKeyAudio = false;
                    }
                    guiMessXML_0.isAudioEnter = false; 
                }
                if (guiMessXML_0.recIndex_Y == 5) {
                    recRecordWhichTagCon = recordFormat = setRecordFormat;
                    recRecordString_0.isRemoveTag = true;
                    isKeyRecFormat = false;
                    guiMessXML_0.isFormatEnter = false;
                }
                if (guiMessXML_0.recIndex_Y == 6) {
                    recRecordWhichTagCon = recordSide = setRecordSide;
                    recRecordString_0.isRemoveTag = true;
                    isKeyRecSide = false;
                    guiMessXML_0.isSideEnter = false;
                }
                if (guiMessXML_0.recIndex_Y == 7) {
                    if (setRecordString.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordString = "Word";
                    }
                    recRecordWhichTagCon = recordString = setRecordString;
                    recRecordString_0.isRemoveTag = true;
                    isKeyString = false;
                    recRecordString_0.isGetStringPlayBack = true;
                    recRecordString_0.isGetDialogPlayBack = true;
                    guiMessXML_0.isRecStringEnter = false;            }
                if (guiMessXML_0.recIndex_Y == 8) {
                    if (setRecordDialogString.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordDialogString = "A";
                    }
                    recRecordWhichTagCon = recordDialogString = setRecordDialogString;
                    recRecordString_0.isRemoveTag = true;
                    isKeyDiaString = false;
                    recRecordString_0.isGetStringPlayBack = true;
                    recRecordString_0.isGetDialogPlayBack = true;
                    guiMessXML_0.isRecDialogEnter = false;
                }
                if (guiMessXML_0.recIndex_Y == 9) {
                    if (setRecordImageFolder != "" && isKeyImageFolderRL == true) {
                        recordImage = setRecordImageFolder;
                        //ofDirectory--------_
                        dirDialogImageStringDefault = "record/dialog/images/";
                        dirDialogImageString = dirDialogImageStringDefault;
                        setDirirDialogImageString = setRecordImageFolder;
                        dirDialogImageString += setDirirDialogImageString;
                        recRecordWhichTagCon = dirDialogImageString += "/";
                        dirDialogImage.listDir(dirDialogImageString);
                        dirDialogImage.sort();
                        
                        if( dirDialogImage.size() ){
                            images.assign(dirDialogImage.size(), ofImage());
                        }
                        
                        for(int i = 0; i < (int)dirDialogImage.size(); i++){
                            images[i].loadImage(dirDialogImage.getPath(i));
                            if (i < 6) {
                                myImage[i] = images[i];
                            }
                        }
                        currentDialogImage = 0;
                        setRecordImageFolderTest = dirDialogImageString;
                        //---ofDirectory-----_
                    }
                    isKeyImageFolderRL = false;
                    recRecordString_0.isRemoveTag = true;
                    isKeyDiaImage = false;
                    guiMessXML_0.isImageEnter = false;
                }
            }else if(key == OF_KEY_DEL || key == 127) {
                addKeyIndexZero = 0;
                toAddZero = "";
                //playBack--------------_
                isAllPlayBack = false;
                //-------playBack-------_
                if (guiMessXML_0.recIndex_Y == 0) {
                    if (isJustAtRunFile == true) {
                        isJustAtRunFile = false;
                    }
                    setRecordFile = "";
                    //ofDirectory--------_
                    isRecAddressCurrentDir = true;
                    isSetRecordFileDefault = false;
                    //----ofDirectory----_
                    isKeyFileRL = true;
                    isKeyFile = true;
                    guiMessXML_0.isFileEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 2) {
                    if (setRecordArtistName.size() > 0) {
                        if (guiMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiMessXML_0.stringIndexRightLeft >= setRecordArtistName.size()) {
                            setRecordArtistName.erase(setRecordArtistName.end()-1,setRecordArtistName.end());
                            guiMessXML_0.stringIndexRightLeft--;
                        }else {
                            setRecordArtistName.erase(setRecordArtistName.begin()+guiMessXML_0.stringIndexRightLeft);
                            guiMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setRecordArtistName.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordArtistName = "";
                    }
                    guiMessXML_0.stringSize = setRecordArtistName.size();
                    stringSizeWas = setRecordArtistName.size();
                    isKeyArtistName = true;
                    guiMessXML_0.isArtistEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 3) {
                    if (setRecordSetName.size() > 0) {
                        if (guiMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiMessXML_0.stringIndexRightLeft >= setRecordSetName.size()) {
                            setRecordSetName.erase(setRecordSetName.end()-1,setRecordSetName.end());
                            guiMessXML_0.stringIndexRightLeft--;
                        }else {
                            setRecordSetName.erase(setRecordSetName.begin()+guiMessXML_0.stringIndexRightLeft);
                            guiMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setRecordSetName.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordSetName = "";
                    }
                    guiMessXML_0.stringSize = setRecordSetName.size();
                    stringSizeWas = setRecordSetName.size();
                    isKeySetName = true;
                    guiMessXML_0.isSetEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 4) {
                    //setRecordAudio = "";
                    //ofDirectory--------_
                    isRecAudioCurrentDir = true;
                    isSetAudioDefault = false;
                    //----ofDirectory----_
                    //isKeyAudio = true;
                    guiMessXML_0.isAudioEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 5) {
                    if (setRecordFormat.size() > 0) {
                        if (guiMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiMessXML_0.stringIndexRightLeft >= setRecordFormat.size()) {
                            setRecordFormat.erase(setRecordFormat.end()-1,setRecordFormat.end());
                            guiMessXML_0.stringIndexRightLeft--;
                        }else {
                            setRecordFormat.erase(setRecordFormat.begin()+guiMessXML_0.stringIndexRightLeft);
                            guiMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setRecordFormat.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordFormat = "";
                    }
                    guiMessXML_0.stringSize = setRecordFormat.size();
                    stringSizeWas = setRecordFormat.size();
                    isKeyRecFormat = true;
                    guiMessXML_0.isFormatEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 6) {
                    if (setRecordSide.size() > 0) {
                        if (guiMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiMessXML_0.stringIndexRightLeft >= setRecordSide.size()) {
                            setRecordSide.erase(setRecordSide.end()-1,setRecordSide.end());
                            guiMessXML_0.stringIndexRightLeft--;
                        }else {
                            setRecordSide.erase(setRecordSide.begin()+guiMessXML_0.stringIndexRightLeft);
                            guiMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setRecordSide.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordSide = "";
                    }
                    guiMessXML_0.stringSize = setRecordSide.size();
                    stringSizeWas = setRecordSide.size();
                    isKeyRecSide = true;
                    guiMessXML_0.isSideEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 7) {
                    if (setRecordString.size() > 0) {
                        if (guiMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiMessXML_0.stringIndexRightLeft >= setRecordString.size()) {
                            setRecordString.erase(setRecordString.end()-1,setRecordString.end());
                            guiMessXML_0.stringIndexRightLeft--;
                        }else {
                            setRecordString.erase(setRecordString.begin()+guiMessXML_0.stringIndexRightLeft);
                            guiMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setRecordString.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordString = "";
                    }
                    guiMessXML_0.stringSize = setRecordString.size();
                    stringSizeWas = setRecordString.size();
                    isKeyString = true;
                    guiMessXML_0.isRecStringEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 8) {
                    if (setRecordDialogString.size() > 0) {
                        if (guiMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiMessXML_0.stringIndexRightLeft >= setRecordDialogString.size()) {
                            setRecordDialogString.erase(setRecordDialogString.end()-1,setRecordDialogString.end());
                            guiMessXML_0.stringIndexRightLeft--;
                        }else {
                            setRecordDialogString.erase(setRecordDialogString.begin()+guiMessXML_0.stringIndexRightLeft);
                            guiMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setRecordDialogString.size() <= 0) {
                        isDelAtIndexZero = false;
                        setRecordDialogString = "";
                    }
                    guiMessXML_0.stringSize = setRecordDialogString.size();
                    stringSizeWas = setRecordDialogString.size();
                    isKeyDiaString = true;
                    guiMessXML_0.isRecDialogEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 9) {
                    //setRecordImageFolder = setRecordImage = "";
                    //ofDirectory--------_
                    isRecImageFolderCurrentDir = true;
                    isSetDialogImagesFolderDefault = false;
                    recImageCurrentDirTest = true;
                    isSetDialogImagesDefault = false;
                    //----ofDirectory----_
                    //isKeyDiaImage = true;
                    guiMessXML_0.isImageEnter = true;
                }
                guiMessXML_0.isDelete = true;
            } else if(key != '@' 
                      && key != OF_KEY_DEL && key != 127 
                      && key != OF_KEY_RETURN && key != 13 
                      && key != OF_KEY_RIGHT && key != 258 
                      && key != OF_KEY_LEFT && key != 256
                      && key != OF_KEY_UP && key != 357
                      && key != OF_KEY_DOWN && key != 359) {
                letterForm = key;
                if (guiMessXML_0.recIndex_Y == 0 && 
                    key != ':'&& 
                    key != ';'&& 
                    key != '?'&&
                    key != '>'&& 
                    key != '<'&& 
                    key != '{'&& 
                    key != '}'&& 
                    key != '['&& 
                    key != ']'&& 
                    key != '"'&& 
                    key != ')'&& 
                    key != '('&& 
                    key != '*'&& 
                    key != '&'&& 
                    key != '^'&& 
                    key != '%'&& 
                    key != '$'&& 
                    key != '#'&& 
                    key != '@'&& 
                    key != '!'&& 
                    key != '.'&& 
                    key != ','&& 
                    key != '~'&& 
                    key != '`'&& 
                    key != '+'&& 
                    key != '='&& 
                    key != '|'&& 
                    key != 92 && 
                    key != 27 && 
                    key != ' '&& 
                    key != 9) {
                    if (isKeyFile == true)setRecordFile += letterForm;
                    isKeyFile = true;
                    guiMessXML_0.isFileEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 2) {
                    if (setRecordArtistName.size() > 0) {
                        addKeyIndexZero++;
                        if (isDelAtIndexZero == true) {
                            guiMessXML_0.stringIndexRightLeft++;
                            toAddZero += letterForm;
                            if (toAddZero.size() > 1) {
                                toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                            }
                            setRecordArtistName.insert(0, toAddZero);
                            setRecordArtistName.erase(setRecordArtistName.begin(), setRecordArtistName.end()-stringSizeWas);
                            setRecordArtistName.insert(0, toAddZero);
                            
                        }
                        if (isDelAtIndexZero == false) {
                            guiMessXML_0.stringIndexRightLeft++;
                            setRecordArtistName.insert(guiMessXML_0.stringIndexRightLeft, letterForm);
                        }
                    }
                    
                    if (setRecordArtistName.size() <= 0) {
                        guiMessXML_0.stringIndexRightLeft = 0;
                        setRecordArtistName += letterForm;
                    }
                    isKeyArtistName = true;
                    guiMessXML_0.stringSize = setRecordArtistName.size();
                    guiMessXML_0.isArtistEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 3) {
                    if (setRecordSetName.size() > 0) {
                        addKeyIndexZero++;
                        if (isDelAtIndexZero == true) {
                            guiMessXML_0.stringIndexRightLeft++;
                            toAddZero += letterForm;
                            if (toAddZero.size() > 1) {
                                toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                            }
                            setRecordSetName.insert(0, toAddZero);
                            setRecordSetName.erase(setRecordSetName.begin(), setRecordSetName.end()-stringSizeWas);
                            setRecordSetName.insert(0, toAddZero);
                            
                        }
                        if (isDelAtIndexZero == false) {
                            guiMessXML_0.stringIndexRightLeft++;
                            setRecordSetName.insert(guiMessXML_0.stringIndexRightLeft, letterForm);
                        }
                    }
                    
                    if (setRecordSetName.size() <= 0) {
                        guiMessXML_0.stringIndexRightLeft = 0;
                        setRecordSetName += letterForm;
                    }
                    isKeySetName = true;
                    guiMessXML_0.stringSize = setRecordSetName.size();
                    guiMessXML_0.isSetEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 4 && 
                    key != ':'&& 
                    key != ';'&& 
                    key != '?'&&
                    key != '>'&& 
                    key != '<'&& 
                    key != '{'&& 
                    key != '}'&& 
                    key != '['&& 
                    key != ']'&& 
                    key != '"'&& 
                    key != ')'&& 
                    key != '('&& 
                    key != '*'&& 
                    key != '&'&& 
                    key != '^'&& 
                    key != '%'&& 
                    key != '$'&& 
                    key != '#'&& 
                    key != '@'&& 
                    key != '!'&&
                    key != '.'&&
                    key != ','&& 
                    key != '~'&& 
                    key != '`'&& 
                    key != '+'&& 
                    key != '='&& 
                    key != '|'&& 
                    key != 92 && 
                    key != 27 && 
                    key != ' '&& 
                    key != 9) {
                    isKeyAudio = true;
                    //if (isKeyAudio == true)setRecordAudio += letterForm;
                }
                if (guiMessXML_0.recIndex_Y == 5) {
                    if (setRecordFormat.size() > 0) {
                        addKeyIndexZero++;
                        if (isDelAtIndexZero == true) {
                            guiMessXML_0.stringIndexRightLeft++;
                            toAddZero += letterForm;
                            if (toAddZero.size() > 1) {
                                toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                            }
                            setRecordFormat.insert(0, toAddZero);
                            setRecordFormat.erase(setRecordFormat.begin(), setRecordFormat.end()-stringSizeWas);
                            setRecordFormat.insert(0, toAddZero);
                            
                        }
                        if (isDelAtIndexZero == false) {
                            guiMessXML_0.stringIndexRightLeft++;
                            setRecordFormat.insert(guiMessXML_0.stringIndexRightLeft, letterForm);
                        }
                    }
                    
                    if (setRecordFormat.size() <= 0) {
                        guiMessXML_0.stringIndexRightLeft = 0;
                        setRecordFormat += letterForm;
                    }
                    isKeyRecFormat = true;
                    guiMessXML_0.stringSize = setRecordFormat.size();
                    guiMessXML_0.isFormatEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 6) {
                    if (setRecordSide.size() > 0) {
                        addKeyIndexZero++;
                        if (isDelAtIndexZero == true) {
                            guiMessXML_0.stringIndexRightLeft++;
                            toAddZero += letterForm;
                            if (toAddZero.size() > 1) {
                                toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                            }
                            setRecordSide.insert(0, toAddZero);
                            setRecordSide.erase(setRecordSide.begin(), setRecordSide.end()-stringSizeWas);
                            setRecordSide.insert(0, toAddZero);
                            
                        }
                        if (isDelAtIndexZero == false) {
                            guiMessXML_0.stringIndexRightLeft++;
                            setRecordSide.insert(guiMessXML_0.stringIndexRightLeft, letterForm);
                        }
                    }
                    
                    if (setRecordSide.size() <= 0) {
                        guiMessXML_0.stringIndexRightLeft = 0;
                        setRecordSide += letterForm;
                    }
                    isKeyRecSide = true;
                    guiMessXML_0.stringSize = setRecordSide.size();
                    guiMessXML_0.isSideEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 7 &&
                    key != '1'&& 
                    key != '2'&& 
                    key != '3'&& 
                    key != '4'&& 
                    key != '5'&& 
                    key != '6'&& 
                    key != '7'&& 
                    key != '8'&& 
                    key != '9'&& 
                    key != '0') {
                    if (setRecordString.size() > 0) {
                        addKeyIndexZero++;
                        if (isDelAtIndexZero == true) {
                            guiMessXML_0.stringIndexRightLeft++;
                            toAddZero += letterForm;
                            if (toAddZero.size() > 1) {
                                toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                            }
                            setRecordString.insert(0, toAddZero);
                            setRecordString.erase(setRecordString.begin(), setRecordString.end()-stringSizeWas);
                            setRecordString.insert(0, toAddZero);
                            
                        }
                        if (isDelAtIndexZero == false) {
                            guiMessXML_0.stringIndexRightLeft++;
                            setRecordString.insert(guiMessXML_0.stringIndexRightLeft, letterForm);
                        }
                    }
                    
                    if (setRecordString.size() <= 0) {
                        guiMessXML_0.stringIndexRightLeft = 0;
                        setRecordString += letterForm;
                    }
                    isKeyString = true;
                    guiMessXML_0.stringSize = setRecordString.size();
                    guiMessXML_0.isRecStringEnter = true;
                }
                if ((guiMessXML_0.recIndex_Y == 8) && 
                    (key == 'a' || key == 'A' ||
                     key == 'b' || key == 'B' ||
                     key == 'c' || key == 'C' ||
                     key == 'd' || key == 'D' ||
                     key == 'e' || key == 'E' ||
                     key == 'f' || key == 'F' ||
                     key == ' ' )){
                    if (setRecordDialogString.size() > 0) {
                        addKeyIndexZero++;
                        if (isDelAtIndexZero == true) {
                            guiMessXML_0.stringIndexRightLeft++;
                            toAddZero += letterForm;
                            if (toAddZero.size() > 1) {
                                toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                            }
                            setRecordDialogString.insert(0, toAddZero);
                            setRecordDialogString.erase(setRecordDialogString.begin(), setRecordDialogString.end()-stringSizeWas);
                            setRecordDialogString.insert(0, toAddZero);
                            
                        }
                        if (isDelAtIndexZero == false) {
                            guiMessXML_0.stringIndexRightLeft++;
                            setRecordDialogString.insert(guiMessXML_0.stringIndexRightLeft, letterForm);
                        }
                    }
                    
                    if (setRecordDialogString.size() <= 0) {
                        guiMessXML_0.stringIndexRightLeft = 0;
                        setRecordDialogString += letterForm;
                    }
                    isKeyDiaString = true;
                    guiMessXML_0.stringSize = setRecordDialogString.size();
                    guiMessXML_0.isRecDialogEnter = true;
                }
                if (guiMessXML_0.recIndex_Y == 9 && 
                    key != ':'&& 
                    key != ';'&& 
                    key != '?'&&
                    key != '>'&& 
                    key != '<'&& 
                    key != '{'&& 
                    key != '}'&& 
                    key != '['&& 
                    key != ']'&& 
                    key != '"'&& 
                    key != ')'&& 
                    key != '('&& 
                    key != '*'&& 
                    key != '&'&& 
                    key != '^'&& 
                    key != '%'&& 
                    key != '$'&& 
                    key != '#'&& 
                    key != '@'&& 
                    key != '!'&&
                    key != '.'&&
                    key != ','&& 
                    key != '~'&& 
                    key != '`'&& 
                    key != '+'&& 
                    key != '='&& 
                    key != '|'&& 
                    key != 92 && 
                    key != 27 && 
                    key != ' '&& 
                    key != 9) {
                    isKeyDiaImage = true;
                    //if (isKeyDiaImage == true)setRecordImageFolder += letterForm;
                }
                guiMessXML_0.isDelete = false;
                guiMessXML_0.isImageEnter = true;
            }   
            //---------letterForm-------------_
        }
        //osc-------------------------------_
        if (isFormOsc == true) {
            if (isKeyFill == false && isKeyPort == false && guiOscMessXML_0.recIndex_Y == 1) {
            }
            
            //letterForm----------------------_
            if (guiOscMessXML_0.recIndex_Y != guiOscMessXML_0.maxNumInList
                && isKeyFill == false) {
                if (key == OF_KEY_RIGHT || key == 258) {
                    guiOscMessXML_0.isRight = true;
                } 
                if (key == OF_KEY_LEFT || key == 256) {
                    guiOscMessXML_0.isLeft = true;
                }
            }
            
            if(key == '<') {
                guiOscMessXML_0.isDownList = true;
                isKeyFileRL = isKeyAudioRL = isKeyImageFolderRL = false;
            } else if (key == '>' || key == 9) {
                guiOscMessXML_0.isUpList = true;
                isKeyFileRL = isKeyAudioRL = isKeyImageFolderRL = false;
            } else if(key == OF_KEY_RETURN || key == 13) {
                addKeyIndexZero = 0;
                toAddZero = "";
                isDelAtIndexZero = false;
                guiOscMessXML_0.isSetCursorAtSizeZero_X = false;
                
                if (guiOscMessXML_0.recIndex_Y == 0) {
                    if (setStringPort.at(0) == ' ') {
                        setStringPort.erase(setStringPort.begin());
                    }
                    stringPort = setStringPort;
                    stringToIntPort = stringPort;
                    port = ofToInt(stringToIntPort);
                    receiver.setup(port);
                    isKeyPort = false;
                    guiOscMessXML_0.isPortEnter = false;
                }
                if (guiOscMessXML_0.recIndex_Y == 1) {
                    if (setHost.at(0) == ' ') {
                        setHost.erase(setHost.begin());
                    }
                    host = setHost;
                    isKeyHost = false;
                    guiOscMessXML_0.isHostEnter = false;
                }
                if (guiOscMessXML_0.recIndex_Y == 2) {
                    if (setOscAddres.at(0) == ' ') {
                        setOscAddres.erase(setOscAddres.begin());
                    }
                    oscAddres = setOscAddres;
                    isKeyOscAddres  = false;
                    guiOscMessXML_0.isAddrasEnter = false;
                }
            }else if(key == OF_KEY_DEL || key == 127) {
                addKeyIndexZero = 0;
                toAddZero = "";
                if (guiOscMessXML_0.recIndex_Y == 0) {
                    if (setStringPort.size() > 0) {
                        if (guiOscMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiOscMessXML_0.stringIndexRightLeft >= setStringPort.size()) {
                            setStringPort.erase(setStringPort.end()-1,setStringPort.end());
                            guiOscMessXML_0.stringIndexRightLeft--;
                        }else {
                            setStringPort.erase(setStringPort.begin()+guiOscMessXML_0.stringIndexRightLeft);
                            guiOscMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setStringPort.size() <= 0) {
                        isDelAtIndexZero = false;
                        setStringPort = "";
                    }
                    guiOscMessXML_0.stringSize = setStringPort.size();
                    stringSizeWas = setStringPort.size();
                    isKeyPort = true;
                    guiOscMessXML_0.isPortEnter = true;
                }
                if (guiOscMessXML_0.recIndex_Y == 1) {
                    if (setHost.size() > 0) {
                        if (guiOscMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiOscMessXML_0.stringIndexRightLeft >= setHost.size()) {
                            setHost.erase(setHost.end()-1,setHost.end());
                            guiOscMessXML_0.stringIndexRightLeft--;
                        }else {
                            setHost.erase(setHost.begin()+guiOscMessXML_0.stringIndexRightLeft);
                            guiOscMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setHost.size() <= 0) {
                        isDelAtIndexZero = false;
                        setHost = "";
                    }
                    guiOscMessXML_0.stringSize = setHost.size();
                    stringSizeWas = setHost.size();
                    isKeyHost = true;
                    guiOscMessXML_0.isHostEnter = true;
                }
                if (guiOscMessXML_0.recIndex_Y == 2) {
                    if (setOscAddres.size() > 0) {
                        if (guiOscMessXML_0.stringIndexRightLeft == 0) {
                            isDelAtIndexZero = true;
                        }
                        if (guiOscMessXML_0.stringIndexRightLeft >= setOscAddres.size()) {
                            setOscAddres.erase(setOscAddres.end()-1,setOscAddres.end());
                            guiOscMessXML_0.stringIndexRightLeft--;
                        }else {
                            setOscAddres.erase(setOscAddres.begin()+guiOscMessXML_0.stringIndexRightLeft);
                            guiOscMessXML_0.stringIndexRightLeft--;
                        }
                    }
                    if (setOscAddres.size() <= 0) {
                        isDelAtIndexZero = false;
                        setOscAddres = "";
                    }
                    guiOscMessXML_0.stringSize = setOscAddres.size();
                    stringSizeWas = setOscAddres.size();
                    isKeyOscAddres = true;
                    guiOscMessXML_0.isAddrasEnter = true;
                }
            } else if(key != '@' 
                      && key != OF_KEY_DEL && key != 127 
                      && key != OF_KEY_RETURN && key != 13 
                      && key != OF_KEY_RIGHT && key != 258 
                      && key != OF_KEY_LEFT && key != 256
                      && key != OF_KEY_UP && key != 357
                      && key != OF_KEY_DOWN && key != 359) {
                letterForm = key;
                if ((guiOscMessXML_0.recIndex_Y == 0) && 
                    (key == '1' ||
                     key == '2' ||
                     key == '3' ||
                     key == '4' ||
                     key == '5' ||
                     key == '6' ||
                     key == '7' || 
                     key == '8' ||
                     key == '9' ||
                     key == '0')){
                        if (setStringPort.size() > 0) {
                            addKeyIndexZero++;
                            if (isDelAtIndexZero == true) {
                                guiOscMessXML_0.stringIndexRightLeft++;
                                toAddZero += letterForm;
                                if (toAddZero.size() > 1) {
                                    toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                                }
                                setStringPort.insert(0, toAddZero);
                                setStringPort.erase(setStringPort.begin(), setStringPort.end()-stringSizeWas);
                                setStringPort.insert(0, toAddZero);
                                
                            }
                            if (isDelAtIndexZero == false) {
                                guiOscMessXML_0.stringIndexRightLeft++;
                                setStringPort.insert(guiOscMessXML_0.stringIndexRightLeft, letterForm);
                            }
                        }
                        
                        if (setStringPort.size() <= 0) {
                            guiOscMessXML_0.stringIndexRightLeft = 0;
                            setStringPort += letterForm;
                        }
                        guiOscMessXML_0.stringSize = setStringPort.size();
                        guiOscMessXML_0.isPortEnter = true;
                    }
                if ((guiOscMessXML_0.recIndex_Y == 1) && 
                    (key == '1'||
                     key == '2' ||
                     key == '3' ||
                     key == '4' ||
                     key == '5' ||
                     key == '6' ||
                     key == '7' || 
                     key == '8' ||
                     key == '9' ||
                     key == '0' ||
                     key == '.')){
                        if (setHost.size() > 0) {
                            addKeyIndexZero++;
                            if (isDelAtIndexZero == true) {
                                guiOscMessXML_0.stringIndexRightLeft++;
                                toAddZero += letterForm;
                                if (toAddZero.size() > 1) {
                                    toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                                }
                                setHost.insert(0, toAddZero);
                                setHost.erase(setHost.begin(), setHost.end()-stringSizeWas);
                                setHost.insert(0, toAddZero);
                                
                            }
                            if (isDelAtIndexZero == false) {
                                guiOscMessXML_0.stringIndexRightLeft++;
                                setHost.insert(guiOscMessXML_0.stringIndexRightLeft, letterForm);
                            }
                        }
                        
                        if (setHost.size() <= 0) {
                            guiOscMessXML_0.stringIndexRightLeft = 0;
                            setHost += letterForm;
                        }
                        guiOscMessXML_0.stringSize = setHost.size();
                        guiOscMessXML_0.isHostEnter = true;
                    }
                if ((guiOscMessXML_0.recIndex_Y == 2) && 
                    (key != ':'&& 
                     key != ';'&& 
                     key != '?'&&
                     key != '>'&& 
                     key != '<'&& 
                     key != '{'&& 
                     key != '}'&& 
                     key != '['&& 
                     key != ']'&& 
                     key != '"'&& 
                     key != ')'&& 
                     key != '('&& 
                     key != '*'&& 
                     key != '&'&& 
                     key != '^'&& 
                     key != '%'&& 
                     key != '$'&& 
                     key != '#'&& 
                     key != '@'&& 
                     key != '!'&&
                     key != '.'&&
                     key != ','&& 
                     key != '~'&& 
                     key != '`'&& 
                     key != '+'&& 
                     key != '='&& 
                     key != '|'&& 
                     key != 92 && 
                     key != 27 && 
                     key != ' '&& 
                     key != 9)){
                        if (setOscAddres.size() > 0) {
                            addKeyIndexZero++;
                            if (isDelAtIndexZero == true) {
                                guiOscMessXML_0.stringIndexRightLeft++;
                                toAddZero += letterForm;
                                if (toAddZero.size() > 1) {
                                    toAddZero.erase(toAddZero.begin()+addKeyIndexZero, toAddZero.end());
                                }
                                setOscAddres.insert(0, toAddZero);
                                setOscAddres.erase(setOscAddres.begin(), setOscAddres.end()-stringSizeWas);
                                setOscAddres.insert(0, toAddZero);
                                
                            }
                            if (isDelAtIndexZero == false) {
                                guiOscMessXML_0.stringIndexRightLeft++;
                                setOscAddres.insert(guiOscMessXML_0.stringIndexRightLeft, letterForm);
                            }
                        }
                        
                        if (setOscAddres.size() <= 0) {
                            guiOscMessXML_0.stringIndexRightLeft = 0;
                            setOscAddres += letterForm;
                        }
                        guiOscMessXML_0.stringSize = setOscAddres.size();
                        guiOscMessXML_0.isAddrasEnter = true;
                    }
            }   
            //---------letterForm-------------_
        }
        //----------------osc---------------_
    }
}

//--------------------------------------------------------------
void dialogger::keyReleased(int key){
}

//--------------------------------------------------------------
void dialogger::mousePressed(int x, int y, int button){
    if (isGuiDraw == true) {
        //allHitAreaImage----------------------_
        isAddHitDialog = true;
        if (allHitAreaImage_0.isHitOk == true) {
            if (guiMessXML_0.recIndex_Y == 8){
                isKeyDiaString = true;
                guiMessXML_0.isRecDialogEnter = true;
            }
            hitDialogIndex = allHitAreaImage_0.hitDialogIndex;
            hitAreaImageIndex = allHitAreaImage_0.hitAreaImageIndex;
        }
        //-----------allHitAreaImage-----------_
        
        //guiMessXML_0----------------------_
        if (guiMessXML_0.isIn == true) {
            guiMessXML_0.isSel = true;
            dialogPlayer_0.isSel = false;
            guiOscMessXML_0.isSel = false; 
            guiMessXML_0.recIndex_Y = guiMessXML_0.maxNumInList;
            guiOscMessXML_0.recIndex_Y = guiOscMessXML_0.maxNumInList;
            isFormOsc = false;
        }
        //------------guiMessXML_0----------_
        
        //osc-------------------------------_
        if (guiOscMessXML_0.isIn == true) {
            guiOscMessXML_0.isSel = true;
            guiMessXML_0.isSel = false;
            dialogPlayer_0.isSel = false;
            guiMessXML_0.recIndex_Y = guiMessXML_0.maxNumInList;
            guiOscMessXML_0.recIndex_Y = guiOscMessXML_0.maxNumInList;
            isPlayBackIn = false;
            isFormOsc = true;
        }
        //----------------osc---------------_
        
        //dialogPlayer_0-------------------------------_
        if (dialogPlayer_0.isIn == true) {
            dialogPlayer_0.isSel = true;
            guiMessXML_0.isSel = false;
            guiOscMessXML_0.isSel = false;
            guiMessXML_0.recIndex_Y = guiMessXML_0.maxNumInList;
            guiOscMessXML_0.recIndex_Y = guiOscMessXML_0.maxNumInList;
            isFormOsc = false;
            isPlayBackIn = true;
        }
        //----------------dialogPlayer_0---------------_
    }
}

//--------------------------------------------------------------
void dialogger::mouseReleased(int x, int y, int button){
    if (isGuiDraw == true) {
        hitDialogIndex = "";
        hitAreaImageIndex = 0;
    }
}
