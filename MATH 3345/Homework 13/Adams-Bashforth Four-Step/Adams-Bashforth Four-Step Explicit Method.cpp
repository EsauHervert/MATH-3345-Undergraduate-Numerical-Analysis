#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

long double f(long double, long double);
long double Y(long double);
long double AB4(long double, long double, long double, long double, long double, long double, long double, long double, long double);

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("Adams-Bashforth Four-Step Explicit Method, h = 0.1.txt");

	long double a = 1, b = 2; // t boundary.
	long double h = 0.1; // Mesh size.
	long double y0 = 0, y1 = 0, y2 = 0, y3 = 0;
	long double yn = 0; // W(t) value.
	long double t = a; // initial time.


					   //Initial values.
	y0 = Y(t);
	y1 = Y(t + h);
	y2 = Y(t + 2 * h);
	y3 = Y(t + 3 * h);

	// Heading for the file.
	outputFile << "Time" << "			" << "W(t)" << "			" << "Y(t)" << endl;
	outputFile << showpoint << setprecision(10) << t << "		" << y0 << "		" << Y(t) << endl; // Inital points.
	outputFile << showpoint << setprecision(10) << t + h << "		" << y1 << "		" << Y(t + h) << endl; // Inital points.
	outputFile << showpoint << setprecision(10) << t + 2 * h << "		" << y2 << "		" << Y(t + 2 * h) << endl; // Inital points.
	outputFile << showpoint << setprecision(10) << t + 3 * h << "		" << y3 << "		" << Y(t + 3 * h) << endl; // Inital points.

	outputFile << endl;

	while (t < b - 3 * h)
	{
		// Finding y(t_(i+1)).
		yn = AB4(t + 3 * h, t + 2 * h, t + h, t, y3, y2, y1, y0, h);

		outputFile << showpoint << setprecision(10) << t + 4 * h << "		" << yn << "		" << Y(t + 4 * h) << endl; // Write the information.

		t += h; // Increase the time.
		// Change the initial values.
		y0 = y1;
		y1 = y2;
		y2 = y3;
		y3 = yn;
	}

	outputFile.close(); // Close the file.

	return 0;
}

// Y(t).
long double Y(long double t)
{
	long double Yt = t / (1 + log(t));
	return Yt;
}

// Function of y and t.
long double f(long double y, long double t)
{
	long double fxy = (y / t) - (y / t) * (y / t);
	return fxy;
}

// Adams-Bashforth Four-Step Explicit Method
long double AB4(long double ti, long double tim1, long double tim2,long double tim3, long double wi, long double wim1, long double wim2, long double wim3, long double h)
{
	long double W = wi + (h / 24) * (55 * f(wi, ti) - 59 * f(wim1, tim1) + 37 * f(wim2, tim2) - 9 * f(wim3, tim3));
	return W;
}
