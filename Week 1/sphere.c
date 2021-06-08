/*
 * Program to calculate the volue of a sphere with radius=2
*/

#include <iostream>

const double PI=3.14;

int main()
{
	// Variables
	// int long short unsigned 
	// float double long double
	double radius=2.0;

	// Calculation
	// * / + - () % 
	double volume=4.0 / 3.0 * PI * radius * radius * radius;

	// Output
	// Expecting 33.493
	std::cout << "Volume is " << volume << std::endl;
	return 0;
}
