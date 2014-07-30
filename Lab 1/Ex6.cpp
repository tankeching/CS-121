#include "Circle.h"

const double pi = 3.14;

Circle::Circle() : _radius(0){}
Circle::Circle(double radius) : _radius(radius){}

void Circle::radius(double radius){ _radius = radius; }
double Circle::radius() const{ return _radius; }

double Circle::area() const{ return _radius * _radius * pi; }
double Circle::perimeter() const{ return 2 * pi * _radius; }

int main()
{
	Circle c, d(314.2);

	cout << "The radius of c is: " << c.radius() << endl;
	cout << "Change radius to 2.5" << endl;
	c.radius(2.5);
	cout << "The radius of c is: " << c.radius() << endl;
	cout << "The area of c is: " << c.area() << endl;
	cout << "The perimeter of c is: " << c.perimeter() << endl;

	cout << "The radius of d is: " << d.radius() << endl;
	cout << "The area of d is: " << d.area() << endl;
	cout << "The perimeter of d is: " << d.perimeter() << endl;

	cout << "...done." << endl;

	return 0;
}
