/* 
 * This program converts polar coordinates to cartesian
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// variables
	double x=0.0, y=0.0, radius=0.0, degrees=0.0;

	// input
	cout << "Enter radius and angle (degrees):";
	cin >> radius >> degrees;

	// processing
	double radians=degrees*M_PI/180.0;
	x=radius * cos(radians);
	y=radius * sin(radians);

	cout << "(" << x << "," << y <<")\n";
	return 0;
}