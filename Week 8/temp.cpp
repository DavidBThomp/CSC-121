/*
* Converts C to F
*/

#include <iostream>
#include <cmath>

using namespace std;

int celToFar();
int farToCel();

int main()
{
    int menuChoice = 0;
    double celConvert, farConvert;

    cout << "This program will convert farenheit or celsius.\n1. Celsius\n2. Farenheit\n3. Quit\nWhich would you like to convert from:";
    cin >> menuChoice;

    while (menuChoice != 3) {
        if (menuChoice == 1) {
            farConvert = celToFar();
        }

        if (menuChoice == 2) {
            celConvert = farToCel();
        }






        cout << "Please select another option or quit.\n1. Celsius\n2. Farenheit\n3. Quit\nWhich would you like to convert from:";
        cin >> menuChoice;

    }

    cout << "Thank you for using the program! Data is store in a file for all conversions done!" << endl;

	return 0;
}


int celToFar() {
    // variables
	double cel=0.0, far=0.0;

    try {

        // input
        cout << "Enter degrees in Celsius:";
        cin >> cel;

        if (cel < 0.0) {
            throw 1;
        } else if (cel > 100.0) {
            throw 2;
        } else {
            // processing
            far = (cel*9.0/5.0) + 32.0;

            // output
            cout << "The temperature in farenheit is " << far << "°F\n";
        }

    } catch (int e) {
        cout << "An exception occured, Exception Number:" << e << endl;
    }

    return far;
}

int farToCel() {
    // variables
	double cel=0.0, far=0.0;

    try {

        // input
        cout << "Enter degrees in Farenheit:";
        cin >> far;

        if (far < 0.0) {
            throw 1;
        } else if (far > 100.0) {
            throw 2;
        } else {
            // processing
            cel = (far-32.0)/1.8;

            // output
            cout << "The temperature in celsius is " << far << "°C\n";
        }

    } catch (int e) {
        cout << "An exception occured, Exception Number:" << e << endl;
    }

    return cel;
}
