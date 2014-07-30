#include "Car.h"

Car::Car(){}
Car::Car(int year, string make, string model, double speed):
_year(year), _make(make), _model(model), _speed(speed){}

double Car::speed() const{ return _speed; }
void Car::speed(double speed){ _speed = speed; }

void Car::accel(double accel){ _speed = _speed + accel; }
void Car::deccel(double deccel){
	if (deccel ==0){
		_speed = 0;
	}
	else{
	_speed = _speed - deccel;
	}
}

void Car::stats(){
	cout << "Car[year=" << _year << ",make=" << _make << ",model=" << "_make=" << _make
		<< ",speed=" << _speed << "]" << endl;
}

int Car::year() const{ return _year; }
string Car::make() const{ return _make; }
string Car:: model() const{ return _model; }


int main(){
	Car a(2013, "Dodge", "Viper", 150 );
	Car b(2012, "Ferrari", "458 Italita", 160);


	cout << "Car program..." << endl;

	a.stats();
	b.stats();

	a.accel(60);
	a.stats();

	b.accel(55);
	b.stats();

	cout << "Polizia! Hit the brakes!" << endl;

	a.deccel(0);
	b.deccel(0);

	a.stats();
	b.stats();


	cout << "Whew! that was a close one!" << endl;


	return 0;
}