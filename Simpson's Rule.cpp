#include <iostream>

using namespace std;

//Will contain the function.
double function(double);

//Will perform the Trapezoid method.
double Simpson(double, double);

int main()
{
	double a = 1, b = 1.6;
	cout << "The value for the integral of the function (2x)/(x^2-4) from " << a << " to " << b << " is: ";
	cout << Simpson(a, b) << endl;
}

double function(double x)
{
	double f = 0;

	//Function.
	f = (2 * x) / (pow(x, 2) - 4);

	//Returns value.
	return f;
}

double Simpson(double x0, double x2)
{
	double integral = 0;
	double h = (x2 - x0) / 2;
	double x1 = x0 + h;

	//Simpson method.
	integral = (h / 3) * (function(x0) + 4 * function(x1) + function(x2));

	//Returns the integral.
	return integral;
}