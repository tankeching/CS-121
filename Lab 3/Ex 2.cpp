#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void generateTable( double startTemp, double endTemp, double stepSize, char choice);
void getParameters(double& startTemp, double& endTemp, double& stepSize);
void displayTemp(double temp, char choice);
char displayMenu();

//functions defined
char displayMenu()
{
	char choice;
	cout << "Program that creates a table of the following..." << endl;
	cout << endl;
	cout << setw(15) << "Menu" << endl;
	cout << "1. Convert Fahrenheit to Celsius" << endl;
	cout << "2. Convert Celsius to Fahrenheit" << endl;
	cout << "3. Convert Celsius to Kelvin" << endl;
	cout << "4. Convert Kelvin to Celsius" << endl;
	cout << "5. Quit Program" << endl;
	cout << endl;

	cout << "Enter menu choice: ";
	cin >> choice;

	while(choice < '1' || choice > '5')
	{
		cout << "Invalid Menu choice. Enter 1, 2, 3, 4, 5." << endl;
		cout << "Enter menu choice: ";
		cin >> choice;
	}

	return choice;

}


void generateTables( double startTemp, double endTemp, double stepSize, char choice)
{
	for(double Temp = startTemp; Temp <= endTemp; Temp += stepSize)
	{
		displayTemp(Temp,choice);
	}
}	


void displayTemp(double Temp, char choice)
{
	cout << right << fixed << showpoint << setprecision(2);	

	if (choice == '1')								//Fahrenheit to Celsius
	{
			cout << Temp << " F ===> " << 5/9.0 * (Temp - 32) << " C" << endl;
	}

	if(choice == '2')								//Celsius to Fahrenheit
	{
			cout << Temp << " C ===> " << (9/5.0 *Temp) + 32 << " F" << endl;
	}

	if(choice == '3')								//Celsius to Kelvin
	{
			cout << Temp << " C ===> " << Temp + 273.0 << " K" << endl;
	}

	if(choice == '4')								//Kelvin to Celsius
	{

			cout << Temp << " K ===> " << Temp - 273.0 << " C" << endl;
	}

	if(choice == '5')								//Quit Program
	{
		cout << "...Quitting Program." << endl;
		exit(0);
	}
}

void getParameters(double& startTemp, double& endTemp, double& stepSize)
{
		cout << "Enter starting temperature: ";
		cin >> startTemp;
		cout << "Enter ending temperature: ";
		cin >> endTemp;
		cout << "Enter step size: ";
		cin >> stepSize;

}

int main()
{
	char choice;
    double startTemp;
	double endTemp;
    double stepSize;
	
	do
	{
		choice = displayMenu();
		if(choice > '1' && choice < '5')
		{
			getParameters(startTemp,endTemp,stepSize);
			generateTables(startTemp,endTemp,stepSize,choice);
		}

		cout << endl;
	
	}while(choice != '5');

	if (choice == '5'){
		cout << "...Quitting Program." << endl;
		exit(0);
	}

	
	return 0;
}

	