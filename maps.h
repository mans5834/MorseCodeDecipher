#include<map>
#include<string>

using namespace std;

//Function declarations
string maps(string morseLetter);
//End of function declarations

string maps(string morseLetter){   //Creates a map to associate dots and dashes with the letter in morse code

    string Output;

    map<string, string> intToMorse;
    intToMorse["01"] = "A";
    intToMorse["1000"] = "B";
    intToMorse["1010"] = "C";
    intToMorse["100"] = "D";
    intToMorse["0"] = "E";
    intToMorse["0010"] = "F";
    intToMorse["110"] = "G";
    intToMorse["0000"] = "H";
    intToMorse["00"] = "I";
    intToMorse["0111"] = "J";
    intToMorse["101"] = "K";
    intToMorse["0100"] = "L";
    intToMorse["11"] = "M";
    intToMorse["10"] = "N";
    intToMorse["111"] = "O";
    intToMorse["0110"] = "P";
    intToMorse["1101"] = "Q";
    intToMorse["010"] = "R";
    intToMorse["000"] = "S";
    intToMorse["1"] = "T";
    intToMorse["001"] = "U";
    intToMorse["0001"] = "V";
    intToMorse["011"] = "W";
    intToMorse["1001"] = "X";
    intToMorse["1011"] = "Y";
    intToMorse["1100"] = "Z";

    Output = intToMorse.at(morseLetter);

    return Output;

}