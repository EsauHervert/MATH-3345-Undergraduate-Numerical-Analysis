#include <iostream>
#include <fstream>

using namespace std;

double function(double, double);
double K1(double, double, double);
double K2(double, double, double, double);
double K3(double, double, double, double);
double K4(double, double, double,double);
double RK4(double, double, double, double, double, double, double);

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("Runge-Kutta, h = 0.5.txt");

	double a = 0, b = 1; // t boundary.
	double h = 0.5; // Mesh size.
	double yn = 0; // initial value.
	double k1, k2, k3, k4; // K values.

	double s = (b - a) / h; // Number of steps.

	double ti = a; // initial time.

	// Heading for the file.
	outputFile << "Time" << "	" << "Y(t)" << endl;

	outputFile << ti << "	" << yn << endl; // Inital points.

	for (int i = 0; i < s; i++)
	{
		// The K values.
		k1 = K1(yn, ti, h);
		k2 = K2(yn, ti, h, k1);
		k3 = K3(yn, ti, h, k2);
		k4 = K4(yn, ti, h, k3);

		// Finding y(t_(i+1)).
		yn = RK4(yn, ti, h, k1, k2, k3, k4);

		outputFile << ti + h << "	" << yn << endl; // Write the information.
		ti += h; // Increase the time.
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

//K values.
double K1(double y, double t, double h)
{
	double K1 = h * function(y, t);
	return K1;
}

double K2(double y, double t, double h, double K1)
{
	double K2 = h * function(t + (h / 2), y + (K1 / 2));
	return K2;
}

double K3(double y, double t, double h, double K2)
{
	double K3 = h * function(y + (K2 / 2), t + (h / 2));
	return K3;
}

double K4(double y, double t, double h, double K3)
{
	double K4 = h * function(y + K3, t + h);
	return K4;
}

// Runge-Kutta Method.
double RK4(double y, double t, double h, double K1, double K2, double K3, double K4)
{
	double r = (double) 1 / 6; // have to convert to double for precision purposes.
	double yi1 = y + r * (K1 + 2 * K2 + 2 * K3 + K4);
	return yi1;
}