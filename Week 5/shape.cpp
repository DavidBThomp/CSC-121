
/*
* Shapes 2 Assignment
* User input cannot bbe negative
* Seperate Class for each Shape
* Dimensions will be members and private
* Each class will have:
* Volume function, surface area function, constructor, get and set functions.
*/

#include <iostream>

using namespace std;

class cube {
    private:
        double length;
    public:
        double cube();
        double cubeSurfaceArea();
};

double cube::cube {
    length = 0.0;
}




class sphere {

};

class rectPrism {

};

class cylinder {

};

class cone {

};





void failInput();

int main() {

	int menuChoice=0;

	// print menu
	cout << "1. Cube\n2. Sphere\n3. Rectangular Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
	cin >> menuChoice;

    while (cin.fail()==1) { 
        failInput();
        cout << "1. Cube\n2. Sphere\n3. Rectangular Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
        cin >> menuChoice;
    }


    while (menuChoice != 6) {

        // Menu choice for cube
		if (menuChoice==1) {
		   
		}

        // Menu choice for Sphere
		if (menuChoice==2) {
		    
		}

        // Menu choice for Rectangular Prism
		if (menuChoice==3) {
		   
		}

        // Menu choice for Cylinder
		if (menuChoice==4) {
		   
		}

        // Menu choice for Cone
		if (menuChoice==5) {
		    
		}

		if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5 && menuChoice != 6) {
			cout << "\nError! Invalid menu choice\n";
		}
            
		// print menu
		cout << "Please select another shape or quit program.\n1. Cube\n2. Sphere\n3. Rectangular Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
		cin >> menuChoice;

	} // while (menuChoice != QUIT)

	cout << "Thanks for using this program.\n";
	return 0;    
}

void failInput() {
    cout << "\nError! Cannot read input\n";
    cin.clear();
    cin.ignore(INT_MAX,'\n');
}