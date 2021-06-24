/*
* ReadDouble Assignment
* Take User Input as a String and read input into valid number
* First charcter can be +, -, or decimal
* rest of char can be numeric, comma, or decimal
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
