#include <iostream>
using namespace std;

int main()
{
	const int chars_line = 16;
	int i = 0;
	int ignore;
	char c = 33;
	for (char c = 32; c < 127; c++, i++)
	{
		cout << c << " ";
		if (i % 16 == 15)
		{
			cout << endl;
		}
	}
	cout << "DEL" << endl;
	cin >> ignore;
	return 0;
}