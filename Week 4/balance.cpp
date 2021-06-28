/*
* Monthly Balance Calculator
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
    // variables
	double b=0.0, a=0.0, r=0.0, m=0.0;

	// input
	cout << "Enter initial balance, annual percentage rate, monthly deposits, and amount of months account will be open. (All values as numbers EX: 111.23):";
	cin >> b >> a >> r >> m;
    
	// processing

    int index=0;
    while (index < m) {
        double monthly = ((r/12+1)*b+a)
        cout << "The balance month " << index + 1 << " is $" << monthly << endl;
        index++;
    }

	return 0;
}