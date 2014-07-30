#include "Fraction.h"
#include <stdexcept>

//Default numerator is 0 and default denominator is 1.
Fraction::Fraction() : Fraction(0,1){}
Fraction::Fraction(int num) : Fraction(num, 1){}
Fraction::Fraction(int num, int den) : _num(num), _den(den){
	if (_den == 0) {
		throw std::invalid_argument("Denominator == 0");
	}
}

int Fraction::num() const{ return _num; }
void Fraction::num(int num){ _num = num; }

int Fraction::den() const{ return _den; }
void Fraction::den(int den){
	_den = den;	if (_den == 0) {
		throw std::invalid_argument("Denominator == 0");
	}
}

int simplify(int num, int den){
	if (den == 0){
		return num;
	}
	return simplify(den, fmod(num, den));
}

void Fraction::normalize(){
	int temp = simplify(_num, _den);
	_num = _num / temp;
	_den = _den / temp;
}



Fraction operator+(const Fraction& f1, const Fraction& f2){
	return Fraction(f1._num * f2._den + f1._den * f2._num, f1._den * f2._den);
}

Fraction operator-(const Fraction& f1, const Fraction& f2){
	return Fraction(f1._num * f2._den - f1._den * f2._num, f1._den * f2._den);
}

Fraction operator*(const Fraction& f1, const Fraction& f2){
	return Fraction(f1._num * f2._num, f1._den * f2._den);
}

Fraction operator/(const Fraction& f1, const Fraction& f2){
	return Fraction(f1._num * f2._den, f1._den * f2._num);
}


Fraction& Fraction::operator+=(const Fraction& other){
	_num = _num * other._den + _den * other._num;
	_den = _den * other._den;
	normalize();

	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
	_num = _num * other._den - _den * other._num;
	_den = _den * other._den;
	normalize();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other){
	_num = _num * other._num;
	_den = _den * other._den;
	normalize();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other){
	_num = _num * other._den;
	_den = _den * other._num;
	normalize();
	return *this;
}

ostream& operator<<(ostream& os, const Fraction& f1){
	return os << "Fraction[ " << f1._num / simplify(f1._num, f1._den) << ", " << f1._den / simplify(f1._num, f1._den) << "]";
}
