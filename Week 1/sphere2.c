#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Variables
	double radius=2.0;

	// Calculation
	double volume=4.0 / 3.0 * M_PI * pow(radius,3.0);

	// Output
	// Expecting 33.493
	cout << "Volume is " << volume << endl;
	return 0;
}