#ifndef __Class__Car__
#define __Class__Car__

#include <iostream>
#include <string>
using namespace std;

class Car{
public:
	Car();
	Car(int year, string make, string model, double speed);

	double speed() const;
	void speed(double speed);

	void accel(double accel);
	void deccel(double deccel);

	void stats();

	int year() const;
	string make() const;
	string model() const;

private:
	double _speed, _accel;
	string _make, _model;
	int _year;


};

#endif