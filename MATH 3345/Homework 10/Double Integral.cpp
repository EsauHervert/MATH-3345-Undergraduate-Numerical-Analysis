#include <iostream>

using namespace std;

//Functions that will be used in the code.
double fxy(double, double);
double W(int, int, double, double);

int main()
{
	//The end points of the integrals.
	double a = 2.1, b = 2.5, c = 1.2, d = 1.4;

	//The separation of the region.
	int mf = 4, nf = 4;

	//These are the intervals.
	double h = (b - a) / mf, k = (d - c) / nf;


	//Other variables.
	double Total = 0;
	double Integral = 0;
	double x = 0, y = 0;

	//Loop of the integral that will calculate the integral
	for (int i = 0; i <= mf; i++)
	{
		x = a + h * i;
		for (int j = 0; j <= nf; j++)
		{
			y = c + k* j;
			Total += fxy(x, y) *  W(i, j, mf, nf);
		}
	}

	//Multiplying the value by the correction.
	Integral = ((h * k) / 9) * Total;

	cout << "The value of the Integral f(x,y) = x*y^2 for m = " << mf << " , n = " << nf << " is: " << Integral << endl;

	return 0;

}

//This is the function of 2 variables.
double fxy(double x, double y)
{
	double fxy = x * y * y;

	return fxy;
}

//The "weight" function.
double W(int n, int m, double nf, double mf)
{
	double W = 1;

	//For n.
	if (n == 0 || n == nf)
	{
		W *= 1;
	}
	else if (n % 2 == 1)
	{
		W *= 4;
	}
	else if (n % 2 == 0)
	{
		W *= 2;
	}

	//For m.
	if (m == 0 || m == mf)
	{
		W *= 1;
	}
	else if (m % 2 == 1)
	{
		W *= 4;
	}
	else if (m % 2 == 0)
	{
		W *= 2;
	}

	return W;
}