/*
* Create a program that uses a class to store information on a planet, as well as calculate additional information.  Your program will need to use a class that must store at a minimum:
* The planets name
* Mass
* Diameter
* A member function that will calculate the surface area
* A member function that will calculate the density of the planet (mass / volume)
* A member function that will calculate the acceleration due to gravity at the planets surface
* Assume that planets are spheres.
* All members (name,mass,diameter) must be private, with get and set functions for each.  Remember to enforce the constraint that the mass and diameter must be > 0.  Your class may optionally have an input and display function.  
* Write a program that will prompt the user for the members of the class and will redisplay the name, mass, diameter as well as the surface area, density and acceleration due to gravity.
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

class planet {
    private:
        string planetName;
        double planetMass, planetDiameter;
    public:
		bool setMass(double x);
        bool setDiameter(double y);
		double getMass();
        double getDiameter();
        // String getPlanetName
        // Maybe this works, will have to test.
        double planetSurfaceArea();
		double planetVolume();
        double planetDensity();
        double planetAcceleration();
};

// bool cube::setEdge(double x) {
// 	bool rv=false;
// 	edge=x;
// 	rv=true;
// 	return rv;
// }

// double cube::getEdge() {
// 	return edge;
// }

// double cube::cubeSurfaceArea() {
// 	return 6*pow(edge, 2.0);
// }

// double cube::cubeVolume() {
// 	return pow(edge, 3.0);
// }

void input(planet& planetInfo);
void failInput();

int main() {

    // Input information about planet
    planet planetInfo;
    input(planetInfo);

    // Output info about planet just input - For now it doesn't have to store info about multiple planets, but if it did use arrays?..
    // cout << The planet name is << planetInfo.name[i] << "for planet selection i.";
    // cout << The planet mass is << planetInfo.mass[i] << " and the diameter is " << planetInfo.diameter[i] << " units.";
    // cout << The planet surface area is << planetInfo.planetSurfaceArea[i] << " units, the mass is " << planetInfo.planetDensity[i] << " units dense, and has an acceleration due to gravity of " << planetInfo.planetAcceleration[i] << " units/second.";
    
    // Program should loop so that the user is asked it input another planet or fetch another planets info
	return 0;    

}

void failInput() {
    cout << "\nError! Cannot read input\n";
    cin.clear();
    cin.ignore(INT_MAX,'\n');
}

// Input for cube
void input(planet& planetInfo) {
	double x, y;
    string name;

    // Need to add error checking for each input, Or combine into single input that goes line by line
    // Look at other code from teacher for example

	cout << "Planet Name:";
	cin >> name;

    cout << name << "'s mass:";
    cin >> x;

    cout << name << "'s diameter:";
    cin >> y;

	// while (cin.fail()==1) { 
    //     failInput();
	// 	cout << "Edge Length in Inches:";
	// 	cin >> x;
    // }

	// while (x <= 0.0) {
	// 	cout << "The edge must be greater than 0.\nEdge Length in Inches:";
	// 	cin >> x;
	// }

    planet.setName(name);
	planet.setMass(x);
    planet.setDiameter(y);

}