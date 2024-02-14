#include<iostream>
#include<vector>
#include "maps.h"

Dictionary currentKnownWords; //create the dictionary that will be searched

//Start of function declarations
int introduction();
void createDictionary();
string morseCodeDecipher01(string morseInput);
//End of function declarations

int introduction(){ //Explains intitial instructions for program use

    int option = 0;

    cout << "Hi, this program will help to decipher morse code that does not include breaks." << endl;
    cout << "Please follow the instructions below to understand how to interact with the program." << endl;
    cout << "\n 1. After these instructions you will be prompted to enter the word you are trying to decipher." << endl;
    cout << " 2. The morse code will then be deciphered and you will be told what the word is or if the morse code does not represent a word in the English language." << endl;
    cout << "\n\n Would you like to enter your morse code as 0's and 1's representing dots and dashes or use \".\" as a dot and \"-\" as a dash?" << endl;
    cout << "Enter \"1\" for the first option and \"2\" for the second option." << endl;
    cin >> option;

    return option;

}

void createDictionary(){
    string wordsToInsert[] = {"HELLO", "WORLD", 
			      "ARE", "AT", 
		              "BE", "BASIC", 
			      "CAR", "CAT", 
                              "DUCK", "DRIVE", 
			      "ENTER", "EXIT", 
		              "FAR", "FAIR",
			      "GATE", "GRAB",
			      "HAT", "HARD",
			      "I", "IN",
			      "JAB", "JACKET",
			      "KING", "KOALA",
			      "LOVE", "LAUGH",
			      "MONEY", "MAD",
			      "NO", "NOTHING",
			      "OTHER", "OUT",
			      "PEOPLE", "PARK",
			      "QUESTION", "QUARTER",
			      "RIGHT", "REACH",
			      "SAY", "SINK",
			      "TEETH", "TOUGH",
		              "UNDER", "OUT",
			      "VERY", "VARYING",
			      "WHERE", "WEAR",
			      "XEROX", "XERIC",
			      "YES", "YOUR",
			      "ZIP", "ZAG"};
    int size = 54;

    for(int i = 0; i < size; i++){
        currentKnownWords.insertIntoTree(wordsToInsert[i]);
    }

}

string morseCodeDecipher01(string morseInput, string currentString){ //Deciphers morse code. moresInput is what is left of the string and currentString is what is being added to
    cout << "h\n";

    string morseOutput, checker, tempCurrentString;
    string tempMorseInput;

    if(morseInput.size() == 0 && currentKnownWords.currentStringInTree(currentString)){ //base case reached indicating the word is in the dictionary and should be returned
        return currentString;
    }else if(morseInput.size() == 0){   //WordNotInDictionary
        return "Failure";
    }

    //Check if morse is a letter
   
    tempMorseInput = morseInput.substr(0,1);
    checker = maps(tempMorseInput);
    if(!(checker == "No Key")){   //check first letter
	tempCurrentString = currentString + checker;
	tempMorseInput = morseInput.substr(0, morseInput.size());
        tempMorseInput.erase(0,1);
	morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);
	if(morseOutput != "Failure"){
	    return morseOutput;
	}
    }

    if(morseInput.size() >= 2){
	tempMorseInput = morseInput.substr(0,2);
	checker = maps(tempMorseInput);
  	
	if(!(checker == "No Key")){   //check first two letters
            tempCurrentString = currentString + checker;
            tempMorseInput = morseInput.substr(0, morseInput.size());
            tempMorseInput.erase(0,2);
            morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);
            
	    if(morseOutput != "Failure"){
                return morseOutput;
            }
	}
    }

    if(morseInput.size() >= 3){ //check first three letters
        tempMorseInput = morseInput.substr(0,3);
	checker = maps(tempMorseInput);
        if(!(checker == "No Key")){   //check first two letters
            tempCurrentString = currentString + checker;
            tempMorseInput = morseInput.substr(0, morseInput.size());
            tempMorseInput.erase(0,3);
	    morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);

            if(morseOutput != "Failure"){
                return morseOutput;
            }
        }
    }

    if(morseInput.size() >= 4){ //check first three letters
	tempMorseInput = morseInput.substr(0,4);
        checker = maps(tempMorseInput);
	if(!(checker == "No Key")){   //check first two letters
            tempCurrentString = currentString + checker;
            tempMorseInput = morseInput.substr(0, morseInput.size());
	    tempMorseInput.erase(0,4); 
            morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);

            if(morseOutput != "Failure"){ 
                return morseOutput;
            }
        }
    }


    return "Failure";

}

