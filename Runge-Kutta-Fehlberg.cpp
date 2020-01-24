#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// All the functions that will be used.
double Y(double);
double function(double, double);
double K1(double, double, double);
double K2(double, double, double, double);
double K3(double, double, double, double, double);
double K4(double, double, double, double, double, double);
double K5(double, double, double, double, double, double, double);
double K6(double, double, double, double, double, double, double, double);
double RK4(double, double, double, double, double, double, double);
double RK5(double, double, double, double, double, double, double, double);
double q(double, double, double, double);

int main()
{
	// Create the file where the data will be stored.
	ofstream outputFile;
	outputFile.open("Runge-Kutta-Fehlberg, h = 0.5.txt");

	double a = 1, b = 3; // t boundary.
	double h = 0.5; // Initial Mesh size.
	double hmax = 0.5; // Mesh size cannot get bigger than this.
	double hmin = 0.05; // Mesh size cannot get smaller than this.
	double y = 0; // Initial value.
	double yn = 0; // RK4 initial value.
	double ynb = 0; // RK5 initial value.
	double Q = 0; // Scaling.
	double tol = pow(10, -6); // Tolerance.
	double R = 0; // Error.
	double k1, k2, k3, k4, k5, k6; // K values.
	bool cont = true; // Loop will execute until the limit is reached.

	double t = a; // initial time.

				   // Heading for the file.
	outputFile << "Time" << "		" << "w(t)" << "		"<< "h" << "		" << "y(t)" <<  endl;

	outputFile << fixed << setprecision(6) << t << "	" << y << "	" << h << "	" << Y(t) <<  endl; // Inital points.
	
	while (cont)
	{
		// The K values.
		k1 = K1(y, t, h);
		k2 = K2(y, t, h, k1);
		k3 = K3(y, t, h, k1, k2);
		k4 = K4(y, t, h, k1, k2, k3);
		k5 = K5(y, t, h, k1, k2, k3, k4);
		k6 = K6(y, t, h, k1, k2, k3, k4, k5);

		// Finding the values.
		yn = RK4(y, t, h, k1, k3, k4, k5);
		ynb = RK5(y, t, h, k1, k3, k4, k5, k6);

		R = (1 / h) * abs(ynb - yn); // Error.

		//Cases.
		if (R < tol)
		{
			t += h;
			y = yn;

			outputFile << fixed << setprecision(6) << t << "	" << y << "	" << h << "	" << Y(t) << endl; // Inital points.
		}

		// The q value.
		Q = q(tol, h, ynb, yn);

		// Conditions on Q.
		if (Q <= 0.1)
		{
			h *= 0.1;
		}
		else if (Q >= 4)
		{
			h *= 4;
		}
		else
		{
			h *= Q;
		}

		if (h > hmax)
		{
			h = hmax;
		}
		
		// Changing conditions on t.
		if (t >= b)
		{
			cont = false;
		}
		else if (t + h > b)
		{
			h = b - t;
		}
		else if (h < hmin)
		{
			cont = false;
			cout << "Minimum h exceeded.";
		}
	}

	outputFile.close(); // Close the file.

	return 0;
}

// Solution.
double Y(double t)
{
	double yt = t * tan(log(t));
	return yt;
}

// Function of y and t.
double function(double y, double t)
{
	double fyt = 1 + (y / t) + pow((y / t), 2);
	return fyt;
}

//K values.
double K1(double y, double t, double h)
{
	double K1 = h * function(y, t);
	return K1;
}

double K2(double y, double t, double h, double K1)
{
	double K2 = h * function(y + (K1 / 4.), t + (h / 4.));
	return K2;
}

double K3(double y, double t, double h, double K1, double K2)
{
	double K3 = h * function(y + (3. / 32.) * K1 + (9. / 32.) * K2, t + (3. / 8.) * h);
	return K3;
}

double K4(double y, double t, double h, double K1, double K2, double K3)
{
	double K4 = h * function(y + (1932. / 2197.) * K1 - (7200. / 2197.) * K2 + (7296. / 2197.) * K3, t + (12. / 13.) * h);
	return K4;
}

double K5(double y, double t, double h, double K1, double K2, double K3, double K4)
{
	double K5 = h * function(y + (439. / 216.) * K1 - 8 * K2 + (3680. / 513.) * K3 - (845. / 4104.) * K4, t + h);
	return K5;
}

double K6(double y, double t, double h, double K1, double K2, double K3, double K4, double K5)
{
	double K6 = h * function(y - (8. / 27.) * K1 + 2. * K2 - (3544. / 2565.) * K3 + (1859. / 4104.) * K4 - (11. / 40.) * K5, t + (h / 2));
	return K6;
}

// Runge-Kutta Method.
// Order 4.
double RK4(double y, double t, double h, double K1, double K3, double K4, double K5)
{
	double yi1 = y + (25. / 216.) * K1 + (1408. / 2565.) * K3 + (2197. / 4104.) * K4 - (1. / 5.) * K5;
	return yi1;
}

// Order 5.
double RK5(double y, double t, double h, double K1, double K3, double K4, double K5, double K6)
{
	double yi1 = y + (16. / 135.) * K1 + (6656. / 12825.) * K3 + (28561. / 56430.) * K4 - (9. / 50.) * K5 + (2. / 55.) * K6;		
	return yi1;
}

// The q value.
double q(double tol, double h, double yt, double y)
{
	double q = pow((tol * h) / (2 * abs(yt - y)), (1. / 4.));
	return q;
}