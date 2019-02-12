#include<iostream>
using namespace std;
int main()
{
	int i, j, i1, m, n, k;
	cout << "Number of rows: \n";
	cin >> m;
	cout << " Number of cols: \n";
	cin >> n; cout << " Number of cols of B: \n";
	cin >> k;
	// multiplication
	float **A, **B, **C;
	A = new float *[m];
	B = new float *[n];
	C = new float *[m];
	for (i = 0; i < m; i++)
	{
		A[i] = new float[n];
		C[i] = new float[k];
	}
	for (i = 0; i < n; i++) 
	{
		B[i] = new float[k];
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			A[i][j] = i + j;
	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			B[i][j] = i + j;
	cout << "A:\n";
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	cout << "B:\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
	cout << "C:\n";
	for (i = 0; i < m; i++)
		for (j = 0; j < k; j++)
		{
			C[i][j] = 0;
			for (i1 = 0; i1 < n; i1++)
				C[i][j] += A[i][i1] * B[i1][j];
		}
	for (i = 0; i < m; i++) {
		for (j = 0; j < k; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	return 0;
}
