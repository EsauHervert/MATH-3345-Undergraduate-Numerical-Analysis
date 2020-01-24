//Headers
#include <iostream>
#include <cmath>

using namespace std;

//This is the function that we will use to solve the problem
void function(double x)
{
	double fx = 0;
	fx = x * cos(x) - 2 * pow(x, 2) + 3 * x - 1;
	cout << x << "	" << fx << endl;
}

int main()
{
	//Here we will take the value x that we will use to find f(x)
	double value1 = .2, value2 = .3, value3 = 1.2, value4 = 1.3;
	function(value1);
	function(value2);
	function(value3);
	function(value4);

	return 0;
}
