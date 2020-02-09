#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

//This is the function that is in question, I will have it return the value so that it can be tested.
double function(double x)
{
	double fx = 0;
	fx = ((2 - exp(x) + 2 * x) / 3);
	return fx;
}

int main()
{
	//X is going to be the value that will be tested in the loop and delx will be the small increment of x.
	//Xmax and xmin are going to be where the Largest and smallest f(x) is at. They will both start at 0.
	double X = 0, delx = 0.00001, Xmax = 0, xmin = 0;
	
	//THis do loop will go through the range from 0 to 1 via increments of delx
	do
	{
		//Here the value will be tested to see which x gives the Largest f(x) and updated if needed.
		if (function(X) > function(Xmax))
		{
			Xmax = X;
		}

		//Here the value will be tested to see which x gives the smallest f(x) and updated if needed.
		if (function(X) < function(xmin))
		{
			xmin = X;
		}

		//This is where the X value will be increased so that all the range can be tested.
		X = X + delx;

	} while (X <= 1);

	//This is where the Largest and smallest values will be outputted.
	cout << "The Maximun value is found at: x = " << Xmax << ", f(x) = " << function(Xmax) << endl;
	cout << "The minimun value is found at: x = " << xmin << ", f(x) = " << function(xmin) << endl;

	return 0;
}