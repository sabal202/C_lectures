#include <stdlib.h>
#include <stdio.h>

double det_gauss(int n, double M[n][n + 1]) {
	double res = 1;
	for (int i = 0; i < n; ++i) 
		res *= M[i][i];
	return res;
}

void gauss(int n, double M0[n][n + 1]) {
	double M[n][n + 1];
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n + 1; ++j) 
			M[i][j] = M0[i][j];

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double k = M[j][i] / M[i][i];
			for (int l = 0; l < n + 1; ++l) 
				M[j][l] -= k * M[i][l];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			printf("%10.6lf ", M[i][j]);
		}
		printf("\n");
	}
	double det = det_gauss(n, M);
	if (det == 0) {
		printf("Det = 0\n");
		return;
	} else {
		printf("Det = %lf\n", det);
	}

	double x[n];
	for (int i = n - 1; i >= 0; --i) {
		double q = M[i][n];
		for (int j = i + 1; j < n; ++j) {
			q -= M[i][j] * x[j];
		}
		x[i] = q / M[i][i];
	}
	for (int j = 0; j < n; ++j) {
		printf("x_%d = %lf\n", j + 1, x[j]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	double M[n][n + 1];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			scanf("%lf", &M[i][j]);
		}
	}
	gauss(n, M);

}