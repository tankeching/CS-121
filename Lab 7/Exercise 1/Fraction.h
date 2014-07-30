#ifndef __Fraction__
#define __Fraction__

#include <iostream>
using namespace std;

class Fraction{
public:
	Fraction();
	Fraction(int num);
	Fraction(int nNum, int nDen);

	void num(int num);
	int num() const;
	
	void den(int den);
	int den() const;


	void normalize(); //Finds GCF of a fraction.

	friend Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator/(const Fraction& f1, const Fraction& f2);

	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	friend ostream& operator<<(ostream& os, const Fraction& f1);



private:
	int _num, _den;
};

#endif
