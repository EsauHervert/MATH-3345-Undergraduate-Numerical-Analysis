#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

const long double Pi = 3.14159265359;

//This is the function that we are trying to find the root for.
double Function(double x)
{
	double fx = 0;
	fx = 600 * pow(x, 4) - 550 * pow(x, 3) + 200 * pow(x, 2) - 20 * x - 1;

	return fx;
}

//This is the secant method.
double Secant(double p_1, double p_2)
{
	double p = 0;

	p = p_1 - (Function(p_1) * (p_1 - p_2)) / (Function(p_1) - Function(p_2));

	return p;
}

//This is the main program.
int main()
{
	//Initialise all our variables.
	double p = 0, p_1 = 0.1, p_2 = 1, tol = 0;
	int steps = 0;
	bool flag = true;
	tol = pow(10, -4);

	//do loop that will perform the secant method 10 times.
	do
	{
		p = Secant(p_1, p_2);

		//This is where the points will be tested to see which way the iteration continues.
		if (abs(Function(p)) < tol)
		{
			flag = false;
		}
		else if (Function(p) * Function(p_1) < 0)
		{
			p_2 = p_1;
			p_1 = p;
		}
		else if (Function(p) * Function(p_2) < 0)
		{
			p_1 = p_2;
			p_2 = p;
		}
		//In case of errors.
		else
		{
			cout << "Error" << endl;
			flag = false;
		}

		steps += 1;

		//Step limit, if any.
		/*
		if (steps == 10)
		{
			flag = false;
		}
		*/

	} while (flag == true);

	//This is the solution.
	cout << "The value for the root via the False Position method for " << steps << " iterations is " << p << endl;
	cout << "The function evaluated at this root is: " << Function(p) << endl;

	return 0;
}