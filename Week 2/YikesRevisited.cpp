/*
* Yikes the clown cannon revisted assignment
* Take input in MPH and angle in degrees and calculates landing
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

	if (velocity < 0) {
		cout << "The velocity must be greater than 0 miles per hour.\n";
	} else if (angle < 0 || angle > 90) {
		cout << "The angle must be between 0 and 90 degrees.\n";
	} else {
		// processing
		double feetps=velocity * 1.4667;
		double angles = angle*M_PI/180.0;
		double distance=((feetps * feetps)/32.0) * sin(2.0*angles);

		// output
		cout << "Yikes will land " << distance << " feet from the cannon\n";
		return 0;
	}

}
