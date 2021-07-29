/*
* Converts C to F
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <climits>

using namespace std;

int celToFar(string fileName);
int farToCel(string fileName);
void failInput();
void appendDelete(string fileName);
void inputFile(string fileName, double temp, char unit);

int main()
{
    int menuChoice = 0;
    double celConvert, farConvert, fileInput;
    char celOrFar;

	// File Opening
	string fileName;
	cout << "Please input file name you would like to work with:";
	cin >> fileName;

	while (cin.fail()==1) { 
		failInput();
		cout << "Please input file name you would like to work with:";
		cin >> fileName;
	}

    ifstream myfile(fileName);

    try{
        if (myfile.is_open()) {
            // While file is open, take inputs seperated by space
            while(myfile >> fileInput >> celOrFar) {
                ;
                // Make a way to read input
                // Possibly use new line to break up inputs...
            }
            myfile.close();
        
            // Choose if the file gets appended to or deleted
            appendDelete(fileName);

        } else {
            // Move this into a function that will loop back and run program
            cout << "Unable to find file." << endl << "Please enter a file name for data:";
			cin >> fileName;

			while (cin.fail()==1) { 
				failInput();
				cout << "Unable to create file." << endl << "Please enter a file name for data:";
				cin >> fileName;
			}
			ofstream thefile(fileName);
            cout << "File created!" << endl;
        }

    } catch (int e) {
        cout << "Failure:" << e;
    }

    // Menu
    double temp;
    char unit;
    cout << "This program will convert farenheit or celsius.\n1. Celsius\n2. Farenheit\n3. Quit\nWhich would you like to convert from:";
    cin >> menuChoice;

    while (menuChoice != 3) {
        if (menuChoice == 1) {
            farConvert = celToFar(fileName);
            temp = farConvert;
            unit = 'F';
            inputFile(fileName, temp, unit);
        }

        if (menuChoice == 2) {
            celConvert = farToCel(fileName);
            temp = celConvert;
            unit = 'C';
            inputFile(fileName, temp, unit);
        }

        cout << "Please select another option or quit.\n1. Celsius\n2. Farenheit\n3. Quit\nWhich would you like to convert from:";
        cin >> menuChoice;

    }

    cout << "Thank you for using the program! Data is store in a file for all conversions done!" << endl;

	return 0;
}

void appendDelete(string fileName) {
    char appendDelete;

    // Move all this into a function
    cout << "Would you like to (d)elete the file and start fresh, or (a)ppend and add the file:";
    cin >> appendDelete;
    while (cin.fail()==1) { 
        failInput();
        cout << "Would you like to (d)elete the file and start fresh, or (a)ppend and add the file:";
        cin >> appendDelete;
    }
    
    // Possibly have to make this loop on failure?
    if (appendDelete == 'd' || appendDelete == 'D') {
        ofstream deleteFile;
        deleteFile.open(fileName, ios::out);
        deleteFile.close();

    } else if (appendDelete == 'a' || appendDelete == 'A') {
        ;
    } else {
        cout << "Please use a valid input, either 'A' or 'D'." << endl;
    }
}


int celToFar(string fileName) {
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

        double temp = cel;
        char unit = 'C';
        inputFile(fileName, temp, unit);

    } catch (int e) {
        cout << "An exception occured, Exception Number:" << e << endl;
    }

    return far;
}

int farToCel(string fileName) {
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
            cout << "The temperature in celsius is " << cel << "°C\n";
        }

        double temp = far;
        char unit = 'F';
        inputFile(fileName, temp, unit);

    } catch (int e) {
        cout << "An exception occured, Exception Number:" << e << endl;
    }

    return cel;
}

void failInput() {
	// while (cin.fail()==1) { 
	// 	cout << "\nError! Cannot read input.\n";
	// 	cin.clear();
	// 	cin.ignore(INT_MAX,'\n');
	// 	cout << "1. Add Planet\n2. Delete Planet\n3. Find Planet\n4. List Planets\n5. Order Planets\n6. Quit\nEnter choice number:";
	// 	cin >> menuChoice;
	// }

    cout << "\nError! Cannot read input.\n";
    cin.clear();
    cin.ignore(INT_MAX,'\n');

}

void inputFile(string fileName, double temp, char unit) {
        // Output will look similar to this, so even if deleted it will add on.
        ofstream output;
        output.open(fileName, ios::app);

        if (output.is_open()==1) {
        output.setf(ios::fixed | ios::right);
        output << setprecision(3);
        output << temp << " " << unit << endl;
            if (output.fail()==1) {
                cerr << "Error writing to file!\n";
            }
        }
        output.close();
}