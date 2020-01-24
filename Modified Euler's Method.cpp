#include <iostream>
#include <fstream>

using namespace std;

double function(double, double);
double Euler(double, double, double);

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("Modified Euler's, h = 0.5.txt");

	double a = 0, b = 1; // t boundary.
	double h = 0.5; // Mesh size.
	double yn = 0; // initial value.

	double s = (b - a) / h; // Number of steps.

	double ti = a;

	// Heading for the file.
	outputFile << "Time" << "	" << "Y(t)" << endl;

	outputFile << ti << "	" << yn << endl; // Inital points.

	for (int i = 0; i < s; i++)
	{
		yn = Euler(yn, ti, h);

		outputFile << ti + h << "	" << yn << endl;
		ti += h;
	}

	outputFile.close(); // Close the file.

	return 0;
}

// Function of y and t.
double function(double y, double t)
{
	double fxy = t * exp(3 * t) - 2 * y;
	return fxy;
}

// Modified Euler's Method.
double Euler(double y, double t, double h)
{
	double yi1 = y + (h / 2) * (function(y, t) + function((y + h * function(y, t)), t + h));

	return yi1;
}