#include <iostream>
#include <cmath>
#include <math.h>
#include <complex>

using namespace std;

//Global Constants, if any.

//This is where the function is at.
double function(double x)
{
	double fx = 0;
	fx = 600 * pow(x, 4) - 550 * pow(x, 3) + 200 * pow(x, 2) - 20 * x - 1;
	return fx;
}

//This returns C.
double returnC(double p2)
{
	double C = 0;
	C = function(p2);
	return C;
}

//This returns B.
double returnB(double p0,double p1, double p2)
{
	double B = 0, Top = 0, Bottom = 0;
	Top = pow(p0 - p2, 2)*(function(p1) - function(p2)) - pow(p1 - p2, 2)*(function(p0) - function(p2));
	Bottom = (p0 - p2)*(p1 - p2)*(p0 - p1);
	B = Top / Bottom;
	
	return B;
}

//This returns A.
double returnA(double p0, double p1, double p2)
{
	double A = 0, Top = 0, Bottom = 0;
	Top = pow(p1 - p2, 2)*(function(p0) - function(p2)) - pow(p0 - p2, 2)*(function(p1) - function(p2));
	Bottom = (p0 - p2)*(p1 - p2)*(p0 - p1);
	A = Top / Bottom;

	return A;
}

//This returns P3.
double ReturnP3(double p2, double A, double B, double C)
{
	double P3 = 0, disc = 0, sign = 0;
	disc = pow(B, 2) - 4 * A * C;
	sign = B / abs(B);
	if (disc >= 0)
	{
		P3 = p2 - (2 * C) / (B + sign * pow(disc, .5));
	}
	else if (disc < 0)
	{
		P3 = p2 - -B/A;
	}
	 
	return P3;
}

//This is where the main program is at.
int main()
{
	//The starting points are here.
	long double p = 0, p0 = 0.1, p1 = .5, p2 = 1, tol = 0;
	bool flag1 = false;
	tol = pow(10, -4);

	//This is just to know how many iterations had to be done.
	int steps = 0;

	//Doint the first iteration.
	p = ReturnP3(p2, returnA(p0, p1, p2), returnB(p0, p1, p2), returnC(p2));
	steps += 1;

	//This loop will perform the process as many times as needed.
	do
	{
		//This is where our values will be tested and adjusted as needed.
		if (abs(function(p)) <= tol)
		{
			flag1 = true;
		}
		else if (abs(function(p)) > tol) // Reassigns the values.
		{
			p0 = p1;
			p1 = p2;
			p2 = p;

			p = ReturnP3(p2, returnA(p0, p1, p2), returnB(p0, p1, p2), returnC(p2));
		}
		else //In case of an error.
		{
			cout << "There is a problem" << endl;
			flag1 = true;
		}

		//This is the step counter.
		steps = steps + 1;

		//This is for any step limitations.
		/*
		if (steps == 30)
		{
		flag1 = true;
		}
		*/

	} while (flag1 == false);

	//This is the solution.
	cout << "The value for the root via the Muller's method for " << steps << " iterations is " << p << endl;
	cout << "The function evaluated at this root is: " << function(p) << endl;

	return 0;
}