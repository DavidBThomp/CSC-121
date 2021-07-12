/*
* 1.  Add a planet
* 2.  Delete a planet
* 3.  Find a planet
* 4.  Display list
* 5.  Quit
* For option 1, the user should be prompted for the planets name, diameter and mass and where in the list the planet should be placed.
* For option 2, the user should be prompted for position of the planet to remove.  The planet will then be removed from the vectory.
* For option 3, the user should be prompted for the name of the planet.  The vector will be searched and all information on that planet will be displayed when found.  Note that if the planet is not found, an error message should be displayed.
* For option 4, the contents of the entire vector should be displayed.
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class planet {
    private:
        string planetName;
        double planetMass, planetDiameter;
    public:
        // Set variables
		bool setMass(double x);
        bool setDiameter(double y);
        bool setName(string name);

        // Get variables
		double getMass();
        double getDiameter();
        string getName();

        // Vector functions
        void display();
};

bool planet::setMass(double x) {
    bool rv=false;
	planetMass=x;
	rv=true;
	return rv;
}

bool planet::setDiameter(double y) {
    bool rv=false;
	planetDiameter=y;
	rv=true;
	return rv;
}

bool planet::setName(string name) {
    bool rv=false;
	planetName=name;
	rv=true;
	return rv;
}

double planet::getMass() {
	return planetMass;
}

double planet::getDiameter() {
	return planetDiameter;
}

string planet::getName() {
	return planetName;
}

void planet::display()
{
    cout << "Name: " << planetName << "   Mass: " << planetMass << " KGs    Diameter: " << planetDiameter << " meters" << endl;
}

void input(planet& planetInfo);
void failInput();

void display(vector<planet>& list);
bool insert(vector<planet>& list, planet planetInfo, bool rv);

int main() {

    vector<planet> list;
    display(list);


    int menuChoice=0;

	// print menu
	cout << "1. Add Planet\n2. Delete Planet\n3. Find Planet\n4. List Planets\n5. Quit\nEnter choice number:";
	cin >> menuChoice;

	// If menu input fails, reprint and reenter number
    while (cin.fail()==1) { 
        cout << "\nError! Cannot read input. Make sure input is a number.\n";
        cin.clear();
        cin.ignore(INT_MAX,'\n');
	    cout << "1. Add Planet\n2. Delete Planet\n3. Find Planet\n4. List Planets\n5. Quit\nEnter choice number:";
        cin >> menuChoice;
    }


    while (menuChoice != 5) {

        // Menu choice adding planet
		if (menuChoice==1) {

            try {
                planet planetInfo;
                input(planetInfo);

                int listlen = list.size();

                if (listlen <= 0) {
                    list.push_back(planetInfo); 
                    cout << "Name: " << planetInfo.getName() << "\nMass: " << planetInfo.getMass() << " KGs\nDiameter: " << planetInfo.getDiameter() << " meters" << endl;
                } else {
                    bool rv;
                    rv = insert(list, planetInfo, rv);

                    if (rv == true) {
                        cout << "Name: " << planetInfo.getName() << "\nMass: " << planetInfo.getMass() << " KGs\nDiameter: " << planetInfo.getDiameter() << " meters" << endl;
                    } else {
                        cout << "\nPlease use a position that is in the list or one above the list.\n\n";
                    }
                }


            } catch (int e) {
                // Stores error in int e and then displays error.
                cerr << "An exception was thrown! Error number " << e << endl;
            }

		}

        // Menu choice for deleting planet
		if (menuChoice==2) {
            ;


		}

        // Menu choice for finding planets by name
		if (menuChoice==3) {
            ;



		}

        // Menu choice for listing off planets
		if (menuChoice==4) {
            display(list);



		}

        // Invalid menu choice
		if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5) {
			cout << "\nError! Invalid menu choice\n";
		}
            
		// print menu
		cout << "Please select an option or quit program.\n1. Add Planet\n2. Delete Planet\n3. Find Planet\n4. List Planets\n5. Quit\nEnter choice number:";
		cin >> menuChoice;

	}

    // User selects quit(5) option 
	cout << "Thanks for using this program.\n";

	return 0;    

}

void failInput() {
    cout << "\nError! Cannot read input. Make sure mass and diameter are greater than 0 numbers.\n";
    cin.clear();
    cin.ignore(INT_MAX,'\n');
}

// Input for planet
void input(planet& planetInfo) {
	double x, y;
    string name;

    // Need to add error checking for each input, Or combine into single input that goes line by line
    // Look at other code from teacher for example

    cout << "Planet Name:";     
    cin >> name;
    
    cout << name << "'s mass in KGs:";
    cin >> x;

    cout << name << "'s diameter in meters:";
    cin >> y;

    while (cin.fail()==1) { 
        failInput();
        // Could make user input into a function, possibly for final project to make code more DRY
        cout << "Planet Name:";     
        cin >> name;
        
        cout << name << "'s mass in KGs:";
        cin >> x;

        cout << name << "'s diameter in meters:";
        cin >> y;
    }

    while (x <= 0.0 || y <= 0.0) {
		cout << "The planets radius mass and radiusmust be greater than 0.\n" << name << "'s mass in KGs:";
		cin >> x;

        cout << name << "'s diameter in meters:";
        cin >> y;
	}

    planetInfo.setName(name);
	planetInfo.setMass(x);
    planetInfo.setDiameter(y);

}

// Display list of planets
void display(vector<planet>& list) {
   if (list.empty()==1) {
      cout << "List is empty.\n";
   }
   else {
      long len=list.size();
      for (long i=0;i<len;i++)
      {
              list[i].display();
      }
      cout << endl;
   }
}

bool insert(vector<planet>& list, planet planetInfo, bool rv) {
    int position;
    cout << "Position in list:";
    cin >> position;

    while (cin.fail()==1) { 
        failInput();
        cout << "Invalid input, please try again\nPosition in list:";     
        cin >> position;
    }

    while (position < 0.0) {
        cout << "Input must be greater than 0.\nPosition in list:";     
        cin >> position;
    }

    position = position - 1;

    rv = false;
    if (position >= 0 && position <= list.size()) {
        rv = true;
        planet end;

        // add room for the value to be stored
        list.push_back(end);

        // shift values to the right to make room
        for (int i = list.size()-1; i >= position ; i--) {
            list[i]=list[i-1];
        }
        list[position] = planetInfo;
    } else {
        rv = false;
    }

   return rv;
}