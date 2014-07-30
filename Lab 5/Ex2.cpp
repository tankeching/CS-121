#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void displayVector1D(const vector<int>& v){
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++){
		cout << *it <<  " ";
	}
	cout << endl;
}

void displayVector2DRowsCols( const vector<vector<int>>& vs, size_t r, size_t c){
	cout << right;
	cout << "vector<vector<int>> version..." << endl;

	for (size_t i = 0; i < r; i++){
		for (size_t j = 0; j < c; j++){
			cout << setw(3) << vs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void displayVector2D( const vector<vector<int>>& vs){
	displayVector2DRowsCols(vs, vs.size(), vs[0].size());
}

int main(){
	vector<int> u;
	
	for (int i = 0; i < 10; i++){
		u.push_back(i*i*i);
	}
	cout << "display u..." << endl;
	displayVector1D(u);
	cout << endl << endl;

	cout << "beginning vector 2d...." << endl;
	vector<vector<int>> vs;

	for (int i = 0; i < 5; i++){
		vector<int> v;
	for (int j = 0; j < 8; j++){
			v.push_back(3 * (i + 1) + j * j);
		}
		vs.push_back(v);
	}

	displayVector2D(vs);
	cout << "...ending vector2D" << endl;
	
	return 0;
}