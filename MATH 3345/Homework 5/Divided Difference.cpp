#include <iostream>

using namespace std;

//This is the function of the two terms.
double F(int n, double array[], double array2[])
{
	double fx = 0;
		
	fx = (array2[n] - array2[n - 1]) / (array[n] - array[n - 1]);

	return fx;
}

//This is the product portion of the formula.
double Product(int n, double x, double array[])
{
	double XX = 1;
	int i = 0;

	while (n > 0)
	{
		XX = XX * (x - array[i]);
		i += 1;
		n -= 1;
	}

	return XX;
}

int main()
{
	//These are the variables.
	const int Size = 6;
	double Xn[Size] = { 1950, 1960, 1970, 1980, 1990, 2000 };
	double Fn[Size] = { 151326, 179323, 203302, 226542, 249633, 281422 };
	double F1 = 0, F2 = 0, F3 = 0, 
		F4 = 0, F5 = 0, F6 = 0;

	double P1 = 0, P2 = 0, P3 = 0, P4 = 0, P5 = 0, P6 = 0;

	//This is the value and where the solution will be in.
	double x = 1940, fx = 0;

	//Algorithm for the Polynomials.
	F1 = F(1, Xn, Fn);

	//F2.
	F2 = (F(2, Xn, Fn) - F1) / (Xn[2] - Xn[0]);

	//F3
	double F123 = ((F(3, Xn, Fn) - F(2, Xn, Fn)) / (Xn[3] - Xn[1]));

	F3 = (F123 - F2) / (Xn[3] - Xn[0]);

	//F4.
	double F234 = (F(4, Xn, Fn) - F(3, Xn, Fn)) / (Xn[4] - Xn[2]);
	double F1234 = (F234 - F123) / (Xn[4] - Xn[1]);

	F4 = (F1234 - F3) / (Xn[4] - Xn[0]);

	//F5.
	double F345 = (F(5, Xn, Fn) - F(4, Xn, Fn)) / (Xn[4] - Xn[2]);
	double F2345 = (F345 - F234) / (Xn[5] - Xn[2]);
	double F12345 = (F2345 - F1234) / (Xn[5] - Xn[1]);

	F5 = (F12345 - F4) / (Xn[5] - Xn[0]);

	//F6.
	double F456 = (F(6, Xn, Fn) - F(5, Xn, Fn)) / (Xn[6] - Xn[4]);
	double F3456 = (F456 - F345) / (Xn[6] - Xn[3]);
	double F23456 = (F3456 - F2345) / (Xn[6] - Xn[2]);
	double F123456 = (F23456 - F12345) / (Xn[6] - Xn[1]);

	F6 = (F123456 - F5) / (Xn[6] - Xn[0]);

	//The Polynomials are now.
	P1 = Fn[0] + F1 * Product(1, x, Xn);
	P2 = P1 + F2 * Product(2, x, Xn);
	P3 = P2 + F3 * Product(3, x, Xn);
	P4 = P3 + F4 * Product(4, x, Xn);
	P5 = P4 + F5 * Product(5, x, Xn);
	P6 = P5 + F6 * Product(6, x, Xn);

	//Output the solutions.
	cout << "The first order polynomial evaluated at x = " << x << " is " << P1 << "." << endl;
	cout << "The second order polynomial evaluated at x = " << x << " is " << P2 << "." << endl;
	cout << "The third order polynomial evaluated at x = " << x << " is " << P3 << "." << endl;
	cout << "The fourth order polynomial evaluated at x = " << x << " is " << P4 << "." << endl;
	cout << "The fifth order polynomial evaluated at x = " << x << " is " << P5 << "." << endl;
	cout << "The sixth order polynomial evaluated at x = " << x << " is " << P6 << "." << endl;

	return 0;

}