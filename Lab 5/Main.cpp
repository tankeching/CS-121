#include "Ex1.h"


int main(){
	int x[6];
	int xy[3][6];
	int zyx[3][4][6];

	for (int i = 0; i < 6; i++){
		x[i] = (i + 3)*(i + 4);
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 6; j++){
			xy[i][j] = (i + 1) * j;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 6; k++) {
				zyx[i][j][k] = (i + 3)*(i + 4) * 2 * j + k*k;
			}
		}
	}

	printArray1D(x, sizeof(x) / sizeof(x[0]));
	cout << endl << endl;
	printArray2D(reinterpret_cast<int*>(xy), 3, 6);
	cout << endl << endl;
	printArray3D(reinterpret_cast<int*>(zyx), 3, 4, 6);

	return 0;
}