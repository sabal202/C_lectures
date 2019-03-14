#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
	cout << "You've entered command line" << endl;
	matrix<double> M(3, 4);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; j++) {
			cin >> M[i][j];
		}
	}
	cout << "Det = " << M.det() << endl;
	M.to_triag();
	cout << M;
	return 0;
}