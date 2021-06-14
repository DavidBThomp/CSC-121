#include <iostream>
#include <cmath>

using namespace std;
const int SPHERE=1;
const int CUBE=2;
const int CYLINDER=3;
const int QUIT=4;

int main()
{
	int menuChoice=0;

	// print menu
	cout << "1. Sphere\n2. Cube\n3. Cylinder\n4. Quit\nEnter choice: ";
	cin >> menuChoice;

	while (menuChoice != QUIT) {
	// Menu choice for sphere
		if (menuChoice==SPHERE) {
			double radius=0.0;
			cout << "Enter radius in inches:";
        		cin >> radius;
			while (radius < 0.0) {
				cout << "Error! Radius must be >= 0.0\n";
				cout << "Enter radius in inches:";
        			cin >> radius;
			}
			double volume=4.0 / 3.0 * M_PI * pow(radius,3.0);
			cout << "Volume is " << volume << " cubic inches\n";
		}

		// Menu choice for cube
		if (menuChoice==CUBE) {
			double side=0.0;
			cout << "Enter side in inches:";
        		cin >> side;
			while (side < 0.0) {
				cout << "Error! Side must be >= 0.0\n";
				cout << "Enter side in inches:";
        			cin >> side;
			}
			double volume=pow(side,3.0);
			cout << "Volume is " << volume << " cubic inches\n";
		}

		if (menuChoice==CYLINDER) {
			double height=0.0, radius=0.0, volume=0.0;
			cout << "Enter height in inches:";
			cin >> height;
			while (height < 0.0) {
				cout << "Error! Height must be >= 0.0\n";
				cout << "Enter height in inches:";
				cin >> height;
			}

			cout << "Enter radius in inches:";
			cin >> radius; 
			while (radius < 0.0) {
				cout << "Error! Radius must be >= 0.0\n";
				cout << "Enter radius in inches:";
				cin >> radius;
			}

			volume=M_PI*pow(radius,2.0)*height;
			cout << "Volume is " << volume << "cubic inches\n";
		}

		if (menuChoice != SPHERE && menuChoice != CUBE && menuChoice != CYLINDER) {
			cout << "Error! Invalid menu choice\n";
		}

		// print menu
		cout << "1. Sphere\n2. Cube\n3. Cylinder\n4. Quit\nEnter choice: ";
		cin >> menuChoice;

	} // while (menuChoice != QUIT)

	cout << "Bye\n";

	return 0;