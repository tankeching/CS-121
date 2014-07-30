
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"

void displayShape(const Shape& sh){
	cout << "sh is a(n): " << sh.name() << endl;
	cout << "the area of sh is: " << sh.area() << endl;
	cout << "the perimeter of sh is: " << sh.perimeter() << endl;
	cout << "the length of sh is: " << sh.length() << endl;
	cout << "the width of sh is: " << sh.width() << endl;
}

int main()
{
	const Shape& c = Circle();
	const Shape& d = Circle(3);

	const Shape& e1 = Ellipse();
	const Shape& e2 = Ellipse(4, 2);

	const Shape& sq = Square();
	const Shape& sq2 = Square(10);

	const Shape& rect1 = Rectangle();
	const Shape& rect2 = Rectangle(10, 5);

	//const Shape& tri1 = Triangle(); invalid triangle
	const Shape& tri1 = Triangle();
	const Shape& tri2 = Triangle(13, 4, 10);
	

	displayShape(c);
	displayShape(d);

	displayShape(e1);
	displayShape(e2);

	displayShape(sq);
	displayShape(sq2);

	displayShape(rect1);
	displayShape(rect2);

	displayShape(tri2);


	cout << "...done." << endl;

	return 0;
}