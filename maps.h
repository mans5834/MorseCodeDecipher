#include<map>
#include<unordered_map>
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

    if(intToMorse.find(morseLetter) == intToMorse.end()){   //checks to makesure the letter is present in the map
        return "No Key";
    }

    Output = intToMorse.at(morseLetter);
    //cout << Output << endl;
    return Output;

}

//Creating necessary tree class and struct to store words
struct treeNode{
    unordered_map<char, treeNode*> children;
    bool endOfWord;
    //constructor to initialize endOfWord
    treeNode() : endOfWord(false){}
};

class Dictionary{
    private:
        treeNode* root;
    public:
        Dictionary(){ //initialize the root
	    root = new treeNode();
  	}
        
        void insertIntoTree(const string &newWord){
	    treeNode* temp = root; //holds the current node
	    for(char c : newWord){
	        if(temp->children.find(c) == temp->children.end()){ //checks if the character is in any of the children nodes yet
		    temp->children[c] = new treeNode(); //expand the tree and make the new child able to have children
		}
		
		temp = temp->children[c];
	    }
            
            temp->endOfWord = true; //the tree has stopped addign so we are at the end of the word
	}

	bool currentStringInTree(const string currentString){ //searches the tree to see if there is a matching word or partial word;
	    treeNode* temp = root;
	    for(char c : currentString){
 	        if(temp->children.find(c) == temp->children.end()){
                    return false;
		}
		temp = temp->children[c];
            }
            return true;
	}
};
