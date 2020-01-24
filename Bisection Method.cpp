#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

//Global Constants, if any.
double PI = 3.14159;

//This is where the function is at.
long double function(long double x)
{
	long double fx = 0;
	fx = -(2000 * x + (500 / PI)) / pow((x), 3) + 4 * PI * (x + .25);
	return fx;
}

//This is where the main program is at.
int main()
{
	//The starting points are here where it goes from 0 to 0.48.
	long double a = 1, b = 10, xn = 0, tol = 0;
	bool flag1 = false;
	tol = pow(10, -4);

	//This is just to know how many iterations had to be done.
	int steps = 0;

	//This do loop will perform the bisection method for 10 iterations.
	do
	{
		//This is where the half way value is at.
		xn = (a + b) / 2;

		//This is where our values will be tested and adjusted as needed.
		if (function(xn) < 0)
		{
			a = xn;
		}
		else if (function(xn) > 0)
		{
			b = xn;
		}
		else if (function(xn) == 0)
		{
			flag1 = true;
		}
		else //In case there are any errors.
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

		//This is for the tolerance.
		if (abs(function(xn)) <= tol)
		{
			flag1 = true;
		}

	} while (flag1 == false);

	//This is the solution.
	cout << "The value for the root via the Bisection method for " << steps << " iterations is " <<
		setprecision(8) << xn << endl;
	cout << "The function evaluated at this root is: " << function(xn) << endl;

	return 0;

}