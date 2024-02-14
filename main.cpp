#include "GeneralFunctions.hpp"


int main(){

    int chosenOption = introduction(), error = 0;
    string MorseInput, DecipheredMorseCode;

    createDictionary();

    do{
	//make correct choice based on option
        if(chosenOption == 1){
            cout << "\n\nEnter your morse code: ";
            cin >> MorseInput;
            DecipheredMorseCode = morseCodeDecipher01(MorseInput, "");
            error = 0;
		
	    if(DecipheredMorseCode == "Failure"){
                cout << "\nThe morse code you have entered is not a word." << endl;
    	    }else{
	        cout << "\nThe word you have entered has been deciphered and found to be: "<< DecipheredMorseCode << endl;
            }
 
        }else if(chosenOption == 2){

            //not yet implemented

        }else{   //handles user putting in wrong input
            cout << "\n\nError " << chosenOption << " is not an option. Try again.\n\n\n"<< endl;
            error = 1;
            chosenOption = introduction();

        }

	if(error != 1){
	   cout << "Would you like to decipher another morse code word? (enter y or n)\n";
	   cin >> MorseInput;
	   if(MorseInput == "y"){
	       error = 1;
	   }
	}

    }while(error == 1);
}
