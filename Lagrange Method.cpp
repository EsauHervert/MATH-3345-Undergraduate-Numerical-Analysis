#include <iostream>

using namespace std;

//This is the where the values will be taken in and out will be the Lagrange polynomial
// evaluated at the point x.
double LagrangePolynomial(int k, double x, double Array[], int length)
{
	//Initializing the values.
	double Lagrange = 0, Top = 1, Bot = 1;

	//This is the loop that will perform the product.
	for (int i = 0; i < length; i++)
	{
		//Taking care of the kth term.
		if (i != k)
		{
			Top = Top * (x - Array[i]);
			Bot = Bot * (Array[k] - Array[i]);
		}
	}

	Lagrange = Top / Bot;
	
	return Lagrange;
}

int main()
{
	//These are the following points that will be used.
	const int Size = 4;
	//These are the x_n.
	double X_n[Size] = { 0.698, 0.733, 0.768, 0.803 };

	//These are the f(x_n).
	double F_x[Size] = { .7661, .7432, .7193, .6946 };

	//Our point of interest.
	double x = .750, f_x = 0;

	//Now using the Lagrange polynomials to find out value.
	for (int j = 0; j < Size; j++)
	{
		f_x = f_x + LagrangePolynomial(j, x, X_n, Size) * F_x[j];
	}
	
	cout << "The value for cos(x) at x = " << x << " is " << f_x << "." << endl;
}