#define DEBUG 1

#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	matrix<double> M(n, m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; j++)
			cin >> M[i][j];

	cout << M;

	matrix<double> L = M;

	L[0][0] = 0;

	cout << "L: \n" << L << "M: \n" << M;
	L.transponate();
	cout << "L: \n" << transponated(L) << "M: \n" << M;

	try {
		cout << "Det = " << M.det() << endl;
	} catch (exception& e) { 
		cerr << "exception: " << e.what() << endl; 
	}

	M.to_triag();
	cout << M << endl;

	// cout << inverted << "exit" << endl;
	return 0;
}