#include <iostream>
#include <iomanip>
using namespace std;

void printArray1D(int* px, int nCols){
	for (int i = 0; i < nCols; i++){
		cout << *(px + i) << " ";
	}
}

void printArray2D(int* px, int nRows, int nCols){
	int  total = nRows * nCols;
	cout << right;
	for (int i = 0; i < total; i++){
		cout << setw(4) << *(px + i) << " ";
		if (i % nCols == nCols - 1)  {  cout << endl;  }
	}
	cout << endl;
}

void printArray3D(int* px, int nFloors, int nRows, int nCols){
	int  total = nRows * nCols;
	cout << right;
	for (int i = 0; i < total * nFloors; i++){
		cout << setw(4) << *(px + i) << " ";
		if (i % nCols == nCols - 1)  { cout << endl; }
		if (i % total == total - 1)  { cout << endl; }
	}
	cout << endl;
}