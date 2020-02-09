#include <iostream>

using namespace std;

//Will contain the function.
double function(double);

//Will perform the Trapezoid method.
double Trapezoid(double, double);

int main()
{
	double a = 1, b = 1.6;
	cout << "The value for the integral of the function (2x)/(x^2-4) from " << a << " to " << b << " is: ";
	cout << Trapezoid(a, b) << endl;
}

double function(double x)
{
	double f = 0;

	//Function.
	f = (2 * x) / (pow(x, 2) - 4);

	//Returns value.
	return f;
}

double Trapezoid(double x0, double x1)
{
	double integral = 0;
	double h = (x1 - x0);
	
	//Trapezoid method.
	integral = (h / 2) * (function(x0) + function(x1));

	//Returns the integral.
	return integral;
}