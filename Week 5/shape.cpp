
/*
* Shapes 2 Assignment
* User input cannot be negative
* Seperate Class for each Shape
* Dimensions will be members and private
* Each class will have:
* Volume function, surface area function, constructor, get and set functions.
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class cube {
    private:
        double edge;
    public:
		bool setEdge(double x);
		double getEdge();
        double cubeSurfaceArea();
		double cubeVolume();
};

bool cube::setEdge(double x) {
	bool rv=false;
	edge=x;
	rv=true;
	return rv;
}

double cube::getEdge() {
	return edge;
}

double cube::cubeSurfaceArea() {
	return 6*pow(edge, 2.0);
}

double cube::cubeVolume() {
	return pow(edge, 3.0);
}



class sphere {
	private: 
		double sphereRad;
	public:
		bool setRad(double x);
		double getRad();
		double sphereSurfaceArea();
		double sphereVolume();
};

bool sphere::setRad(double x) {
	bool rv=false;
	sphereRad=x;
	rv=true;
	return rv;
}

double sphere::getRad() {
	return sphereRad;
}

double sphere::sphereSurfaceArea() {
	return 4.0*M_PI*pow(sphereRad, 2.0);;
}

double sphere::sphereVolume() {
	return (4.0/3.0)*M_PI*pow(sphereRad, 3.0);
}



class rectPrism {

};

class cylinder {

};

class cone {

};




void inputCube(cube& edge);
void inputSphere(sphere& sphereRad);
void failInput();

int main() {

	int menuChoice=0;

	// print menu
	cout << "1. Cube\n2. Sphere\n3. Rectangular Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
	cin >> menuChoice;

	// If menu input fails, reprint and reenter number
    while (cin.fail()==1) { 
        failInput();
        cout << "1. Cube\n2. Sphere\n3. Rectangular Prism\n4. Cylinder\n5. Cone\n6. Quit\nEnter choice number: ";
        cin >> menuChoice;
    }


    while (menuChoice != 6) {

        // Menu choice for cube
		if (menuChoice==1) {
			// Inputs
		   cube edge;
		   inputCube(edge);

			// Outputs
			cout << "The surface area of the cube is " << edge.cubeSurfaceArea() << " inches.\n";
			cout << "The volume of the cube is " << edge.cubeVolume() << " cubic inches.\n";

		}

        // Menu choice for Sphere
		if (menuChoice==2) {
		    sphere sphereRad;
			inputSphere(sphereRad);

			cout << "The surface area of the sphere is " << sphereRad.sphereSurfaceArea() << " inches.\n";
			cout << "The volume of the sphere is " << sphereRad.sphereVolume() << " cubic inches.\n";
		}

        // Menu choice for Rectangular Prism
		if (menuChoice==3) {
		   ;
		}

        // Menu choice for Cylinder
		if (menuChoice==4) {
		   ;
		}

        // Menu choice for Cone
		if (menuChoice==5) {
		    ;
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

// Input for cube
void inputCube(cube& edge) {
	double x;
	cout << "Edge Length:";
	cin >> x;

	while (cin.fail()==1) { 
        failInput();
		cout << "Edge Length:";
		cin >> x;
    }

	while (x <= 0.0) {
		cout << "The edge must be greater than 0.\nEdge Length:";
		cin >> x;
	}

	edge.setEdge(x);

}

void inputSphere(sphere& sphereRad) {
	double x;
	cout << "Sphere Radius:";
	cin >> x;

	while (cin.fail()==1) { 
        failInput();
		cout << "Sphere Radius:";
		cin >> x;
    }

	while (x <= 0.0) {
		cout << "The sphere radius must be greater than 0.\nSphere Radius:";
		cin >> x;
	}

	sphereRad.setRad(x);

}