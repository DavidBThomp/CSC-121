/* 
 * This program converts cartesian coordinates to polar
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// variables
	double x=0.0, y=0.0, radius=0.0, degrees=0.0;

	// input
	cout << "Enter x and y: ";
	cin >> x >> y;

	// processing
	radius=sqrt( pow(x,2.0) +  pow(y,2.0) );
	double radians=atan2(y,x);
	degrees=radians*180.0/M_PI;

	// output
	cout << radius << " at " << degrees << "degrees\n";
	return 0;
}