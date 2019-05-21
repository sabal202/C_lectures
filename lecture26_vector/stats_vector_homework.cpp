#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double f(double x, double M2, double D2, double D1, double R, double M1) {
	return M2 + (D2 / D1) * R * (x - M1);
}

int main()
{
	ofstream fout("output.txt");

	if (!fout) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}

	ifstream fin("input.txt");

	if (!fin) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}
	int n;
	fin >> n;
	vector<int> X, Y;
	for (int i = 0; i < n; ++i) {
		int h, w;
		fin >> h >> w;
		X.push_back(h);
		Y.push_back(w);
	}

	double M1 = 0, M2 = 0;
	for (int i = 0; i < n; ++i) {
		M1 += X[i];
		M2 += Y[i];
	}
	M1 /= n; 
	M2 /= n;

	double D1;
	for (int i = 0; i < n; ++i){
		D1 += (X[i] - M1) * (X[i] - M1);
	}
	D1 /= n;
	D1 = sqrt(D1);
	double D2;
	for (int i = 0; i < n; ++i){
		D2 += (Y[i] - M2) * (Y[i] - M2);
	}
	D2 /= n;
	D2 = sqrt(D2);
	double R;
	for (int i = 0; i < n; ++i){
		R += (X[i] - M1) * (Y[i] - M2);
	}
	R /= n;
	R /= D1;
	R /= D2;
	fout << "y = " << M2 << " + (" << D2 << " / " << D1 << ") * " << R << " * (x - " << M1 << ")\n";

	for (int i = 100; i <= 250; i += 5) {
		fout << i << ": " << f(i*1.0, M2, D2, D1, R, M1) << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
