#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// The functions.
double f1(double, double);
double f2(double, double, double);
double g(double);

// The correct values.
double Y(double);


// K values for function 1.
double K11(double, double, double);
double K12(double, double, double, double, double);
double K13(double, double, double, double, double);
double K14(double, double, double, double, double);

//K values for function 2.
double K21(double, double, double, double);
double K22(double, double, double, double, double, double);
double K23(double, double, double, double, double, double);
double K24(double, double, double, double, double, double);


double RK4(double, double, double, double, double, double, double); // Runge Kutta Order 4.

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("Second Order DE RK4 System, h = 0.1.txt");

	double a = 0, b = 1; // t boundary.
	double h = 0.1; // Mesh size.
	double y = 0, w2 = 0; // initial value.
	double k11, k12, k13, k14, k21, k22, k23, k24; // K values.
	int P = 8; // Precision.

	double s = (b - a) / h; // Number of steps.

	double t = a; // initial time.

	// Heading for the file.
	outputFile << showpoint << setprecision(P) << "Time" << "		" << "W(t)" << "		" << "Y(t)" << endl;

	outputFile << showpoint << setprecision(P) << t << "	" << y << "	" << Y(t) << endl; // Inital points.

	for (int i = 0; i < s; i++)
	{
		// The K values.
		k11 = K11(w2, h, t);
		k21 = K21(y, w2, h, t);

		k12 = K12(w2, t, h, k11, k21);
		k22 = K22(y, w2, t, h, k11, k21);

		k13 = K13(w2, t, h, k12, k22);
		k23 = K23(y, w2, t, h, k12, k22);

		k14 = K14(w2, t, h, k13, k23);
		k24 = K24(y, w2, t, h, k13, k23);

		// Finding U(t_(i+1)).
		y = RK4(y, t, h, k11, k12, k13, k14);
		w2 = RK4(w2, t, h, k21, k22, k23, k24);

		t += h; // Increase the time.

		outputFile << showpoint << setprecision(P) << t << "	" << y << "	" << Y(t) << endl; // Points.

	}

	outputFile.close(); // Close the file.

	return 0;
}

// g(t).
double g(double t)
{
	double g = t * exp(t) - t;
	return g;
}

// Function 1.
double f1(double u2, double t)
{
	double u1p = u2;
	return u1p;
}

// Function 2.
double f2(double u1, double u2, double t)
{
	double u2p = 2 * u2 - u1 + g(t);
	return u2p;
}

// Y(t).
double Y(double t)
{
	double Y = (1. / 6.) * t * t * t * exp(t) - t * exp(t) + 2 * exp(t) - t - 2;
	return Y;
}

//K1 values.
double K11(double w2, double h, double t)
{
	double K11 = h * f1(w2, t);
	return K11;
}

double K12(double w2, double t, double h, double K11, double K21)
{
	double K12 = h * f1(w2 + (K21 / 2), t + (h / 2));
	return K12;
}

double K13(double w2, double t, double h, double K12, double K22)
{
	double K13 = h * f1(w2 + (K22 / 2), t + (h / 2));
	return K13;
}

double K14(double w2, double t, double h, double K13, double K23)
{
	double K14 = h * f1(w2 + K23, t + h);
	return K14;
}

//K2 values.
double K21(double w1, double w2, double h, double t)
{
	double K21 = h * f2(w1, w2, t);
	return K21;
}

double K22(double w1, double w2, double t, double h, double K11, double K21)
{
	double K22 = h * f2(w1 + (K11 / 2), w2 + (K21 / 2), t + (h / 2));
	return K22;
}

double K23(double w1, double w2, double t, double h, double K12, double K22)
{
	double K23 = h * f2(w1 + (K12 / 2), w2 + (K22 / 2), t + (h / 2));
	return K23;
}

double K24(double w1, double w2, double t, double h, double K13, double K23)
{
	double K24 = h * f2(w1 + K13, w2 + K23, t + h);
	return K24;
}

// Runge-Kutta Method.
double RK4(double w, double t, double h, double K1, double K2, double K3, double K4)
{
	double wi1 = w + (1. / 6.) * (K1 + 2 * K2 + 2 * K3 + K4);
	return wi1;
}