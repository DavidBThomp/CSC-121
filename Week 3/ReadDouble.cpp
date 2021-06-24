/*
* ReadDouble Assignment
* Take User Input as a String and read input into valid number
* 
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
