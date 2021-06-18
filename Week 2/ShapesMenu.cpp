/*
* Menu and shapes Assignment
* Allows selection of shape and calculation of surface area and volume
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// variables
	double velocity=0.0, angle=0.0;

	// input
	cout << "Yikers the clown is being shot out a cannon, help him determine where he lands!\n";
	cout << "Enter his velocity (Miles Per Hour) and angle (degrees):";
	cin >> velocity >> angle;

	// processing
	// Distance, Time, and Height
	double feetps=velocity * 1.4667;
	double angles = angle*M_PI/180.0;
		
	// output

	cout << "Something Out";

	return 0;
}



