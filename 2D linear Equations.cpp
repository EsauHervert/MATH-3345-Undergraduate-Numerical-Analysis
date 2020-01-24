#include <iostream>

using namespace std;

//This program will solve 2D linear equations:

int main()
{
	double A, B, C, D, E, F;
	cout << "Input A: ";
	cin >> A;
	cout << "Input B: ";
	cin >> B; 
	cout << "Input C: ";
	cin >> C;
	cout << "Input D: ";
	cin >> D;
	cout << "Input E: ";
	cin >> E;
	cout << "Input F: ";
	cin >> F;

	double x1, x2;
	x2 = (C*D - A*F) / (D*B - A*E);
	x1 = (C - B*x2) / A;

	cout << "The Values for x1: " << x1 << " and x2: " << x2 << endl;
}