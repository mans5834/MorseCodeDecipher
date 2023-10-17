#include "GeneralFunctions.hpp"


int main(){

    int chosenOption = introduction(), error = 0;
    string MorseInput, DecipheredMorseCode;

    do{

        if(chosenOption == 1){

            cout << "\n\nEnter your morse code: ";
            cin >> MorseInput;
            DecipheredMorseCode = MorseCodeDecipher01(MorseInput);
            error = 0;

        }else if(chosenOption == 2){

            //not yet implemented

        }else{   //handles user putting in wrong input

            cout << "\n\nError " << chosenOption << " is not an option. Try again.\n\n\n"<< endl;
            error = 1;
            chosenOption = introduction();

        }

    }while(error == 1);

    cout << DecipheredMorseCode << endl;

}