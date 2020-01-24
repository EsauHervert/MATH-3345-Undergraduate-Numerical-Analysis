#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

long double f(long double, long double);
long double Y(long double);

// Runge-Kutta method.
long double K1(long double, long double, long double);
long double K2(long double, long double, long double, long double);
long double K3(long double, long double, long double, long double);
long double K4(long double, long double, long double, long double);
long double RK4(long double, long double, long double, long double, long double, long double, long double);

long double AM3(long double, long double, long double, long double, long double, long double, long double, long double, long double);

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("Adams-Moulton Three-Step Implicit Method, h = 0.01.txt");

	long double a = 0, b = 0.2; // t boundary.
	long double h = 0.01; // Mesh size.
	long double y0 = 0, y1 = 0, y2 = 0, y3 = 0;;
	long double yn = 0; // W(t) value.
	long double t = a; // initial time.
	long double k1, k2, k3, k4; // K values.

	// Initial values.
	y0 = Y(t);
	y1 = Y(t + h);
	y2 = Y(t + 2 * h);

	// Heading for the file.
	outputFile << "Time" << "			" << "W(t)" << "			" << "Y(t)" << endl;
	outputFile << showpoint << setprecision(10) << t << "		" << y0 << "		" << Y(t) << endl; // Inital points.
	outputFile << showpoint << setprecision(10) << t + h << "		" << y1 << "		" << Y(t + h) << endl; // Inital points.
	outputFile << showpoint << setprecision(10) << t + 2 * h << "		" << y2 << "		" << Y(t + 2 * h) << endl; // Inital points.
	outputFile << endl;

	while (t < b - 2 * h)
	{
		k1 = K1(y2, t + 3 * h, h);
		k2 = K2(y2, t + 3 * h, h, k1);
		k3 = K3(y2, t + 3 * h, h, k2);
		k4 = K4(y2, t + 3 * h, h, k3);

		y3 = RK4(y2, t + 3 * h, h, k1, k2, k3, k4);

		// Finding y(t_(i+1)).
		yn = AM3(t + 3 * h, t + 2 * h, t + h, t, y3, y2, y1, y0, h);

		outputFile << showpoint << setprecision(10) << t + 3 * h << "		" << yn << "		" << Y(t + 3 * h) << endl; // Write the information.

		t += h; // Increase the time.
		// Change the initial values.
		y0 = y1;
		y1 = y2;
		y2 = yn;
	}

	outputFile.close(); // Close the file.

	return 0;
}

// Y(t).
long double Y(long double t)
{
	long double Yt = 1 - log(1 - exp(1) * t);
	return Yt;
}

// Function of y and t.
long double f(long double y, long double t)
{
	long double fxy = exp(y);
	return fxy;
}

// Adams-Bashforth Three-Step Explicit Method
long double AM3(long double tip1, long double ti, long double tim1, long double tim2, long double wip1, long double wi, long double wim1, long double wim2, long double h)
{
	long double W = wi + (h / 24) * (9 * f(wip1, tip1) + 19 * f(wi, ti) - 5 * f(wim1, tim1) + f(wim2, tim2));
	return W;
}

//K values.
long double K1(long double y, long double t, long double h)
{
	long double K1 = h * f(y, t);
	return K1;
}

long double K2(long double y, long double t, long double h, long double K1)
{
	long double K2 = h * f(y + (h / 2), y + (K1 / 2));
	return K2;
}

long double K3(long double y, long double t, long double h, long double K2)
{
	long double K3 = h * f(y + (h / 2), y + (K2 / 2));
	return K3;
}

long double K4(long double y, long double t, long double h, long double K3)
{
	long double K4 = h * f(y + K3, t + h);
	return K4;
}

// Runge-Kutta Method.
long double RK4(long double y, long double t, long double h, long double K1, long double K2, long double K3, long double K4)
{
	long double r = (long double)1 / 6; // have to convert to double for precision purposes.
	long double yi1 = y + r * (K1 + 2 * K2 + 2 * K3 + K4);
	return yi1;
}