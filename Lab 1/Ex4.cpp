#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double squareFeet;
	int depth;
	double cubicFeet, cubicYards, totalPrice;
	double price = 22.00;

	cout << "Number of square feet to be covered in mulch: ";
	cin >> squareFeet;
	cout << "Number of inches deep: ";
	cin >> depth;

	cubicFeet = squareFeet * (depth / 12.0);
	cubicYards = cubicFeet / 27;
	totalPrice = cubicYards * price;

	cout << endl;
	cout << "Number of cubic yards needed: " << cubicYards << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Price per cubic yard: $" << setw(7) << price << endl;
	cout << "Total price: $" << setw(7) << totalPrice << endl << endl;

	return 0;
}