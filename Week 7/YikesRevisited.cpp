/*
* File Output by name
* File find by name
* Once found, delete or append
* The output will be in the file, including time, x, y, and trajectory
* 3 digits to right of decimal
* Numbers should line up
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <array>

using namespace std;

class Matrix {
	public:
		enum {MAX_SIZE=100};
		Matrix();
		bool Dimension(int rows, int cols);
		void SetValue(int row, int col, double value);
		double GetValue(int row, int col);
		void Input();
		void Display(ostream& out);
		int Rows();
		int Columns();
		void Clear();

	private:
		array< array<double,MAX_SIZE>, MAX_SIZE > values;
		int rows,cols;
};

Matrix::Matrix() {
	Clear();
}

int Matrix::Rows() {
	return rows;
}

int Matrix::Columns() {
	return cols;
}

void Matrix::Clear() {
	Dimension(0,0);
}

bool Matrix::Dimension(int r, int c) {
   bool rv=false;
   if (r >= 0 && r <= MAX_SIZE && c >= 0 && c <= MAX_SIZE) {
		rv=true;
		rows=r;
		cols=c;
		for (int i=0;i<r;i++) {
			for (int j=0;j<c;j++) {
				values[i][j]=0.0;
			}
		}	
	}
	return rv;
}

void Matrix::Display(ostream& out) {
	if (rows > 0 && cols > 0) {
		for (int r=0; r<Rows(); r++) {
			for (int c=0; c<Columns(); c++) {
				out.width(15);
				out.precision(2);
				out.setf(ios::showpoint|ios::fixed|ios::right);
				out << values[r][c];
			}
			out << endl;
		}
		out << endl;
	}
	else {
		out << "Matrix has no dimensions.\n";
	}
}

void Matrix::Input() {
	int rows=ReadValue<int>("Rows? ", 1, MAX_SIZE);
	int cols=ReadValue<int>("Cols? ", 1, MAX_SIZE);
	Dimension(rows,cols);
	for (int r=0; r<Rows(); r++) {
		for (int c=0; c<Columns(); c++) {
			cout << "Position "<<r+1<<","<<c+1<<": ";
			cin >> values[r][c];
		}
	}
}

void Matrix::SetValue(int row, int col, double value) {
	if (row<rows && col < cols) {
		values.at(row).at(col)=value;
	}
	else {
		throw("row,col out of matrix range");
	}
}

double Matrix::GetValue(int row, int col) {
	if (row<rows && col < cols) {
		return values.at(row).at(col);
	}
	else {
		throw("row,col out of matrix range");
	}
}

bool AddMatrix(Matrix& a, Matrix& b, Matrix& result) {
	bool rv=false;
	if (a.Rows()==b.Rows() && a.Columns()==b.Columns()) {
		rv=true;
		result.Dimension(a.Rows(),a.Columns());
		for (int r=0;r<a.Rows();r++) {
			for (int c=0;c<a.Columns();c++) {
				result.SetValue(r,c,a.GetValue(r,c)+b.GetValue(r,c));
			}
		}
	}
	return rv;
}


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
		// Distance, Time, and Height
		double feetps=velocity * 1.4667;
		double angles = angle*M_PI/180.0;

		double distance=(pow(feetps,2)/32.0) * sin(2.0*angles);

		double timeAir=distance/(feetps * cos(angles));

		double maxHeight=(feetps * sin(angles)) * timeAir / 2.0 - 0.5 * 32.0 * pow(timeAir/2.0, 2.0);

		// Processing and output for x,y cordinates
		double timerSpace = timeAir/20.0;
		double incTime = 0.0;
		while (incTime < timeAir) {
			double xCord=(feetps * cos(angles)) * incTime;
			double yCord=(feetps * sin(angles)) * incTime - 0.5 * 32 * pow(incTime, 2);
			cout << "Time: "<< incTime << " Seconds   X-Cord: " << xCord << " Feet   Y-Cord: " << yCord << " Feet   \n";
			incTime= incTime+timerSpace;
		}
		
		// output

		cout << "Yikes will land " << distance << " feet from the cannon\nHe will spend " << timeAir << " seconds the air.\nHis maximum height wil be " << maxHeight << " feet.\n";

		// Expected output for 100MPH 30 Deg:
		// Distance = 578.815~       Height = 83.545~    Time = 4.56~   
		// Based from own calculations and quick rechecks from https://amesweb.info/Physics/Trajectory-Calculator.aspx

		return 0;
	}

}

