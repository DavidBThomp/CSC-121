/*
* Menu and shapes Assignment
* Allows selection of shape and calculation of surface area and volume
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
        
        
int main() {
    double sr1=0.0, sr2=0.0, sm1=0.0, sm2=0.0, distance=0.0;

    // Get Sphere Information
    cout << "Enter sphere's radius and then sphere's masses in Meters and KGs(Sphere 1 Radius, Sphere 2 Radius, Sphere 1 Mass, Sphere 2 Radius):";
    cin >> sr1 >> sr2 >> sm1 >> sm2;
    while (cin.fail()==1) {
        cout << "\nError! Cannot read input\n";
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << "Enter sphere's radius and then sphere's masses (Sphere 1 Radius, Sphere 2 Radius, Sphere 1 Mass, Sphere 2 Radius):";
        cin >>  sr1 >> sr2 >> sm1 >> sm2;
    }
    while (sr1 < 0.0 || sr2 < 0.0 || sm1 < 0.0 || sm2 < 0.0) {
        cout << "Error! Length must be greater than 0.0 for all sides.\n";
        cout << "Enter sphere's radius and then sphere's masses (Sphere 1 Radius, Sphere 2 Radius, Sphere 1 Mass, Sphere 2 Radius):";
        cin >>  sr1 >> sr2 >> sm1 >> sm2;
    }

    // Get Distance Information
    cout << "Enter the distance between the two spheres in meters:";
    cin >> distance;
    while (cin.fail()==1) {
        cout << "\nError! Cannot read input\n";
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << "Enter the distance between the two spheres in meters:";
        cin >>  distance;
    }
    while (distance < 0.0) {
        cout << "Error! Length must be greater than 0.0 for all sides.\n";
        cout << "Enter the distance between the two spheres in meters:";
        cin >>  distance;
    }

    // Calculations
    // double cubeSA=cubeSurfaceArea(cubeLen);
    // double cubeVOL=cubeVolume(cubeLen);
    cout << "sr1, sr2, sm1, and sm2 are all respectively " << sr1 << sr2 << sm1 << sm2<< ".\nThe distance is " << distance << " meters.\n";
}