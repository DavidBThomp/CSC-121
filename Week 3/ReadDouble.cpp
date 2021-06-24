/*
* ReadDouble Assignment
* Take User Input as a String and read input into valid number
* First charcter can be +, -, or decimal            DONE
* rest of char can be numeric, comma, or decimal        DONE
* commas must be in proper location, before decimal, and seperating 3 digit groups
* no commas after decimal point
* only one decimal point
*/

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cctype>

using namespace std;


void ReadChar(string &input) {

    bool isValid=true;
    string convert;
    
    isValid=true;
    

    // Check that first input value is + - 0
    if (input[0]!='+' && input[0]!='-' && isdigit(input[0]) == 0) {
        std::cout << "Error! First digit input is not \"-\", \"+\", or \"0\".\n";
        isValid=false;
    } else {
        // captures first charcter (+, -, 0)
        convert=input.substr(0,1);
    }

    // check that the remaining characters are numeric
    long len=input.length();
    for (long index=1; index < len && isValid==true; index++) {
        if (input[index]==',' || input[index]=='.') {
            ;  // do nothing if character is a ','
        }
        else if (isdigit(input[index]) == 0){
            //if the value is not a number
            cout << "Error! Input was not an integer.\n";
            isValid=false;
        }
        else {
            // adds first string back to validated input
            convert += input.substr(index,1);
        }
    }

    // Checks period Behavior
    int periodIndex;
    for (long index=1; index < len && isValid==true; index++) {
        if (input[index]=='.') {
            periodIndex = index;
        }
    }
    cout << periodIndex;
    

    cout << "The string input was " << input << endl;


}


int main()
{
    // Get user input
    string input;
	cout << ("Enter a value: ");
    getline(cin,input);

    ReadChar(input);

	return 0;
}
