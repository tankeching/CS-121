#include <iostream>
#include <string>
using namespace std;

int main()
{
	char response;
	string medium;
	double feet;
	double speed = 0;

	do{

	cout << "Calculate the speed of sound in different media." << endl;
	cout << endl;
	cout << "1. Air" << endl;
	cout << "2. Water" << endl;
	cout << "3. Steel" << endl;
	cout << "4. Quit the Program" << endl;


		cout << "Enter your choice: ";
		cin >> response;

		while (response < '0' || response > '4')
		{
			cout << "Invalid input. Please choose 1 (Air), 2 (Water), 3 (Steel), or 4 (Quit)." << endl;
			cout << "Enter your choice: ";
			cin >> response;
		}

		switch(response)
		{
		case '1': medium = "Air"; speed = 1100;  break;
		case '2': medium = "Water"; speed = 4900;  break;
		case '3': medium = "Steel"; speed = 16400; break;
		}

		if (response == '4')
		{
			cout << "Program terminated by user." << endl;
			exit(0);
		}


		cout << "Enter feet for the sound wave to travel in " << medium << " : ";
		cin >> feet;

		cout << "It will take " << feet / speed << " s for sound to travel " << feet << " feet in " << medium << "." << endl;
		cout << endl;

	} while (response != '4');


	return 0;
}