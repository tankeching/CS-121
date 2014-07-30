#include "Fraction.h"

#include <iostream>
#include <iomanip>
using namespace std;

void init(char c, Fraction x[], int n){
	for (int i = 0; i < n; i++){
		x[i] = Fraction(i, n);
		cout << c << "=[" << setw(2) << i << "]=" << x[i] << "   ";
		if (i % 3 == 2 ){ cout << endl; }
	}
	cout << endl << endl;
}

int main(){


	cout << right;

	Fraction x[20], y[10];

	init('x', x, sizeof(x) / sizeof(x[0]));
	init('y', y, sizeof(y) / sizeof(y[0]));

	for (int i = 1; i < 3; i++){
		cout << x[i] << " + " << y[i] << " = " << (x[i] + y[i]) << endl;
		cout << x[i] << " - " << y[i] << " = " << (x[i] - y[i]) << endl;
		cout << x[i] << " * " << y[i] << " = " << (x[i] * y[i]) << endl;
		cout << x[i] << " / " << y[i] << " = " << (x[i] / y[i]) << endl;
	}

	cout << endl;

	Fraction f = x[9];
	Fraction g = y[9];


	cout << f; cout << " += " << g << " = " << (f += g) << endl;
	cout << f; cout << " -= " << g << " = " << (f -= g) << endl;
	cout << f; cout << " *= " << g << " = " << (f *= g) << endl;
	cout << f; cout << " /= " << g << " = " << (f /= g) << endl;

	cout << "...done." << endl;
	


	return 0;
}
