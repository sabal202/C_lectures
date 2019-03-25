#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	matrix<double> M(n, m);

	for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        	cin >> M[i][j];

	cout << M;

	matrix<double> L = M;

	cout << "Replace 1st line of L(copy of M) to 1...1:" << endl;

	double * P = (double *) calloc(m, sizeof(double));
	for (int i = 0; i < m; i++) {
		P[i] = 1;
	}
	L[0] = P;

	cout << L;
	cout << "Double transponated L and M:" << endl;
	// cout << "L: \n" << L << "M: \n" << M;
	L.transponate();
	cout << "L: \n" << transponated(L) << "M: " << endl << M << endl;

	try {
		cout << "det(M) = " << M.det() << endl;
	} catch (exception& e) { 
		cerr << "exception: " << e.what() << endl; 
	}

	try {
		matrix<double> I = inverted(M);
		cout <<"inv(M): \n" << I << endl;

		cout << "Test mult:" << endl;
		cout << I * M;
	} catch (exception& e) { 
		cerr << "exception: " << e.what() << endl; 
	}


	cout << "M to triag:" << endl;
	M.to_triag();
	cout << M << endl;


	return 0;
}