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
	fx = 2 * PI * pow((x + .25), 2) + (2 * PI * x + .25) * (1000 / (PI * pow(x, 2)));
	return fx;
}

//This is where the main program is at.
int main()
{
	double x = 5.3638597;
	cout << function(x) << endl;
	return 0;

}