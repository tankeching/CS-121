#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, k;
	int j = 0;

	for (i = 1; i <= 15; i++)
	{
		cout << right << setw(2) << i << ". I will not talk in class." << endl;

		if (i % 5 == 0)
		{
			cout << endl;
		}
	}

	cout << "---------------------------------------" << endl;

	for (k = 10; k >= 1; k--)
	{
		cout << right << setw(2) << k << ". C++ rocks!" << endl;

		j++;

		if (j % 3 == 0)
		{
			cout << endl;
		}
	}
	
	return 0;
}