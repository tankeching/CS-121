#include <iostream>
using namespace std;

void printArray1D(int* px, int nCols){
	for (int i = 0; i < 6; i++){
		cout << *(px + i) << " ";
	}
}

void printArray2D(int* px, int nRows, int nCols){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 6; j++){
			cout << *(px + i + 1) * j << " ";
		}
		cout << endl;
	}
}

void printArray3D(int* px, int nFloors, int nRows, int nCols){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 6; k++){
				
			}
			cout << endl;
		}
		cout << endl;
	}
}