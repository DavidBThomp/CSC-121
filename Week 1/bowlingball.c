/*
 * Program to calculate how long it takes a bowling ball to
 * hit the ground when dropped from a building of a height
 * input by the user.
 *
 * t = sqrt ( 2 * h / g ) 
 * h=height of building in meters
 * g=acc. due to gravity (9.8 m/sec/sec)
 * t=seconds
*/

#include <iostream>
#include <cmath>

using namespace std;

const double GRAVITY_MPS=9.8;

int main()
{
	// variables
	double height_m=0.0, seconds=0.0;

	// input
	cout << "Enter height in meters:";
	cin >> height_m;

	// processing
	seconds=sqrt( 2.0 * height_m / GRAVITY_MPS);
	
	// output
	cout << "Seconds: " << seconds << endl;
	return 0;
}