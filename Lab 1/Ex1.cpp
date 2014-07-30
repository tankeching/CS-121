#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int base;
	int number;
	char response;

	do{
		cout << "Enter number to convert: ";
		cin >> number;

		cout << "Number is " << hex << showbase << number << " (base 16)" << endl;
		cout << "Number is " << dec << showbase << number << " (base 10)" << endl;
		cout << "Number is " << oct << showbase << number << " (base 8)" << endl;
		cout << "Number is 0b" << bitset<32>(number) << " (base 2)" << endl;


		cout << "Do another conversion (y/n)? ";
		cin >> response;
		response = tolower(response);
		
		cout << endl;

	} while (response == 'y');

	cout << "Done." << endl;

	return 0;
}