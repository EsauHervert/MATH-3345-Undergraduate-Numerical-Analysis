#include <iostream>
#include <cmath>

using namespace std;

//This is where the function will be in.
double function(double x)
{
	long double fx = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	f1 = sin(3 * x);
	f2 = 3 * exp(-2 * x)* sin(x);
	f3 = -3 * exp(-x)* sin(2 * x);
	f4 = -exp(-3 * x);
	fx = f1 + f2 + f3 + f4;
	return fx;
}

//This is where the derivative will be in.
double derfunction(double x)
{
	double dfx = 0, df1 = 0, df2 = 0, df3 = 0, df4 = 0;
	df1 = 3 * cos(3 * x);
	df2 = 3 * exp(-2 * x)* cos(x) - 6 * exp(-2 * x)* sin(x);
	df3 = -6 * exp(-x)* cos(2 * x) + 3 * exp(-x)* sin(2 * x);
	df4 = 3 * exp(-3 * x);
	dfx = df1 + df2 + df3 + df4;
	return dfx;
}

//This is the function which will take out p_n and give us p_(n+1)
double NewtonMethod(double p)
{
	//These are the parts of the Newton method.
	double pnext = 0;

	//This will give us p_(n+1)
	pnext = p - (function(p) / derfunction(p));
	return pnext;
}

//This is the main function.
int main()
{
	//These are the values that we will be using.
	double p = 0, fx = 0, tol = 0;
	bool flag = false;

	//We will use a counter to see how many steps it took to solve this problem.
	int steps = 0;

	//This is where we will be calculating the tolerance.
	tol = 1 / pow(10, 5);
	
	//This is where we will get the user to guess a value.
	cout << "Input your guess for the root." << endl;
	cin >> p;

	//THis is where the method will be iterated as needed if needed.
	do
	{
		if (abs(function(p)) <= tol)
		{
			flag = true;
		}
		else
		{
			p = NewtonMethod(p);
			steps += 1;
		}
		
	} while (flag == false);
	
	//This is the solution.
	cout << "The value for the root via the Newton method for " << steps << " iterations is " << p << endl;
	cout << "The function evaluated at this root is: " << function(p) << endl;

	return 0;
}