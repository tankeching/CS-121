#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double loan, interestRate, payment, paid, interest, rate;
	
	cout << "Enter Loan Amount: $";
	cin >> loan;

	cout << "Enter Interest Rate: %";
	cin >> interestRate;

	rate = interestRate / 100.00;

	cout << "Enter Number of Payments: ";
	cin >> payment;
	
	paid = (rate * pow((1.00 + rate), payment) * loan) / (pow((1.00 + rate), payment) - 1);
	
	cout << "Loan Amount:" << setw(7) << "$" << loan << endl;
	cout << "Monthly Interest Rate: "<< "%" << interestRate << endl;
	cout << "Number of Payments: " << payment << endl;
	cout << "Amount paid back: " << (payment * paid) << endl;
	cout << "Interest paid: " << (payment * paid - loan) << endl;

	return 0;
}