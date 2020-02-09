#include <iostream>
#include <fstream>

using namespace std;

double function(double, double);
double Euler(double, double,double);

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("h = 0.2.txt");

	double a = 0, b = 5; // t boundary.
	double h = 0.2; // Mesh size.
	double yn = 0; // initial value.

	double s = (b - a) / h; // Number of steps.

	double ti = a;
	
	// Heading for the file.
	outputFile << "Time"  << "	" << "Y(t)" << endl;

	outputFile << ti << "	" << yn << endl; // Inital points.

	for (int i = 0; i < s; i++)
	{
		outputFile << ti + h << "	" << Euler(yn, ti, h) << endl;
		ti += h;
		yn = Euler(yn, ti, h);
	}

	outputFile.close(); // Close the file.

	return 0;
}

// Function of y and t.
double function(double y, double t)
{
	double fxy = (-y) + t + 1;
	return fxy;
}

// Euler's Method.
double Euler(double y, double t, double h)
{
	double yi1 = y + h * function(y, t);
	return yi1;
}