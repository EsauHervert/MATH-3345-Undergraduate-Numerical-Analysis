#include <iostream>
#include <cmath>

using namespace std;

//This is the iteration that we will use.
double Iteration(double p)
{
	double pn = 0;
	pn = (2 - exp(p) + (p * p)) / 3;
	return pn;
}

//This is the main function.
int main()
{
	//Here are the initilizations.
	double root = 0, p = 0, tol = 0, test = 0;
	int steps = 0;
	bool flag = false;

	//The tolerance will be 10^-4.
	tol = 1 / (pow(10,5));

	//Here the loop will be done until we are withing the tolerance.
	while (flag == false)
	{
		test = p - Iteration(p);
		p = Iteration(p);
		steps += 1;

		//Here are the tests to end the loops.
		if (abs((test - root)) < tol)
		{
			flag = true;
		}
		if (steps >= 100)
		{
			flag = true;
		}
	}

	//Displaying the information.

	cout << "The root is: " << p << endl;
	cout << "The number of steps it took was: ";
	cout << steps << endl;
}