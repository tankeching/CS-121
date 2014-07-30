#include <iostream>
using namespace std;

void printLine(int n, char c, char cFill, int width){
	
	int nFill = (width - n) / 2;

	for (int i = 0; i < nFill; i++){
		cout << cFill;
	}

	for (int i = 0; i < n; i++){
		cout << c;
	}

	for (int i = 0; i < nFill; i++){
		cout << cFill;
	}

	cout << endl;
}

void printDiamond(int n, char c, char cFill, int width){
	printLine(n, c, cFill, width);

	if (n < width){
		printDiamond(n + 2, c, cFill, width);
	}

	if (n != width){
		printLine(n, c, cFill, width);
	}
}


int main(){

	printDiamond(1, '$', '.', 15);
}