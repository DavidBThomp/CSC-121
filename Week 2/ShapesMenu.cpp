/*
* Menu and shapes Assignment
* Allows selection of shape and calculation of surface area and volume
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

double cubeSurfaceArea(double cubeLen);
double cubeVolume(double cubeLen);
double sphereSurfaceArea(double sphereRad);
double sphereVolume(double sphereRad);

int main()
{
	int menuChoice=0;

	// print menu
	cout << "1. Cube\n2. Sphere\n3. Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
	cin >> menuChoice;

	while (cin.fail()==1) {
		cout << "\nError! Cannot read input\n";
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout << "1. Cube\n2. Sphere\n3. Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
		cin >> menuChoice;
	}

	while (menuChoice != 6) {

        // Menu choice for cube
		if (menuChoice==1) {
		    double cubeLen=0.0;
			cout << "Enter length of edge in inches:";
        	cin >> cubeLen;
			while (cubeLen < 0.0) {
				cout << "Error! Length must be greater than 0.0\n";
				cout << "Enter side in inches:";
        		cin >> cubeLen;
			}
			double cubeSA=cubeSurfaceArea(cubeLen);
            double cubeVOL=cubeVolume(cubeLen);
			cout << "The surface area of the cube is " << cubeSA << " inches.\nThe volume of the cube is " << cubeVOL << " cubic inches.\n";
		}

        // Menu choice for Sphere
		if (menuChoice==2) {
		    double sphereRad=0.0;
			cout << "Enter radius in inches:";
        	cin >> sphereRad;
			while (sphereRad < 0.0) {
				cout << "Error! Radius must be greater than 0.0\n";
				cout << "Enter radius in inches:";
        		cin >> sphereRad;
			}
			double sphereSA=sphereSurfaceArea(sphereRad);
            double sphereVOL=sphereVolume(sphereRad);
			cout << "The surface area of the sphere is " << sphereSA << " inches.\nThe volume of the cube is " << sphereVOL << " cubic inches.\n";
		}

		if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5 && menuChoice != 6) {
			cout << "\nError! Invalid menu choice\n";
		}
            
		// print menu
		cout << "Please select another shape or quit program.\n1. Cube\n2. Sphere\n3. Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
		cin >> menuChoice;

        while (cin.fail()==1) {
		    cout << "\nError! Cannot read input\n";
		    cin.clear();
		    cin.ignore(INT_MAX,'\n');
		    cout << "1. Cube\n2. Sphere\n3. Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
		    cin >> menuChoice;
	    }

	} // while (menuChoice != QUIT)

	cout << "Thanks for using this program.\n";
	return 0;
}

double cubeSurfaceArea(double cubeLen) {
    double cubeSA=6*pow(cubeLen, 2.0);
    return cubeSA;
}

double cubeVolume(double cubeLen) {
    double cubeVOL=pow(cubeLen, 3.0);
    return cubeVOL;
}

double sphereSurfaceArea(double sphereRad) {
    double sphereSA=4.0*M_PI*pow(sphereRad, 2.0);
    return sphereSA;
}

double sphereVolume(double sphereRad) {
    double sphereVOL=(4.0/3.0)*M_PI*pow(sphereRad, 3.0);
    return sphereVOL;
}
