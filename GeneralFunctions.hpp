#include<iostream>
#include "maps.h"

//Start of function declarations
int introduction();
string MorseCodeDecipher01(string morseInput);
//End of function declarations

int introduction(){   //Explains intitial instructions for program use

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

string MorseCodeDecipher01(string morseInput){   //Deciphers morse code

    string morseOutput;

    if(morseInput.size() == 0){
        return;
    }
    if()

    morseOutput = maps(morseInput);

    return morseOutput;

}