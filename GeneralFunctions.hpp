#include<iostream>
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
    currentKnownWords.insertIntoTree("HELLO");
    currentKnownWords.insertIntoTree("WORLD");
    currentKnownWords.insertIntoTree("HI");
    currentKnownWords.insertIntoTree("HOW");
    currentKnownWords.insertIntoTree("ARE");
    currentKnownWords.insertIntoTree("YOU");
}

string morseCodeDecipher01(string morseInput, string currentString){ //Deciphers morse code. moresInput is what is left of the string and currentString is what is being added to

    string morseOutput, checker, tempCurrentString;
    char* tempMorseInput;

    if(morseInput.size() == 0 && currentKnownWords.currentStringInTree(currentString)){ //base case reached indicating the word is in the dictionary and should be returned
        return currentString;
    }else if(morseInput.size() == 0){   //WordNotInDictionary
        return "Failure";
    }

    //Check if morse is a letter
   
    morseInput.copy(tempMorseInput, 1, 0);
    checker = maps(tempMorseInput);
    if(!(checker == "No Key")){   //check first letter
	tempCurrentString = currentString + checker;
	tempMorseInput = morseInput;
	tempMorseInput.erase(0,1);
	morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);
        	
	if(morseOutput != "Failure"){
	    return morseOutput;
	}
    }

    if(morseInput.size() >= 2){
    	morseInput.copy(tempMorseInput, 2, 0); 
	checker = maps(tempMorseInput);
    	
	if(!(checker == "No Key")){   //check first two letters
            empCurrentString = currentString + checker;
            tempMorseInput = morseInput;
            tempMorseInput.erase(0,2);
            morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);
            
	    if(morseOutput != "Failure"){
                return morseOutput;
            }
	}
    }

    if(morseInput.size() >= 3){ //check first three letters
        copy(morseInput, morseInput + 3, tempMorseInput);
        checker = maps(tempMorseInput);
        if(!(checker == "No Key")){   //check first two letters
            tempCurrentString = currentString + checker;
            tempMorseInput = morseInput;
            tempMorseInput.erase(0,3);
            morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);

            if(morseOutput != "Failure"){
                return morseOutput;
            }
        }
    }

    if(morseInput.size() >= 4){ //check first three letters
        copy(morseInput, morseInput + 4, tempMorseInput);
        checker = maps(tempMorseInput);
        if(!(checker == "No Key")){   //check first two letters
            tempCurrentString = currentString + checker;
            tempMorseInput = morseInput;
            tempMorseInput.erase(0,4);
            morseOutput = morseCodeDecipher01(tempMorseInput, tempCurrentString);

            if(morseOutput != "Failure"){ 
                return morseOutput;
            }
        }
    }


    return "No Matching Word.\n";

}

