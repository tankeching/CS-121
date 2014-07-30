#include "Rectangles.h"

Rectangle::Rectangle() : _length(0), _width(0) {}
Rectangle::Rectangle(double length, double width) : _length(length), _width(width) {}

void Rectangle::length(double length){
	_length = length;
}

void Rectangle::width(double width){
	_width = width;
}

double Rectangle::area() const { return _length * _width; }

int main(){
	Rectangle a, b;
	double length, width, area1, area2;

	cout << "Enter length and width of rectangle 1: ";
	cin >> length >> width;
	a.length(length);
	a.width(width);
	area1 = length * width;

	cout << "Enter length and width of rectangle 2: ";
	cin >> length >> width;
	b.length(length);
	b.width(width);
	area2 = length * width;

	cout << "Rectangle 1's area is: " << a.area() << endl;
	cout << "Rectangle 2's area is: " << b.area() << endl;

	if(area1 > area2){
		cout << "Rectangle1's area is GREATER THAN Rectangle 2's area." << endl;
	}

	else if(area1 < area2){
		cout << "Rectangle 1's area is LESS THAN Rectangle 2's area." << endl;
	}

	else if (area1 == area2){
		cout << "Rectangle 1's area is EQUAL TO Rectangle 2's area." << endl;
	}

	return 0;

}



