#include <stdlib.h>
#include <stdio.h>

double gauss_det (int n, double M0[n][n]);

void mul(int n, double A[n][n], double B[n][n]);

double ** inversed(int n, double M[n][n]);

double ** new_matrix(int n, int m) {
	double ** M = (double **) malloc(sizeof(double*) * n);
	for (int i = 0; i < n; ++i)
        M[i] = (double *) malloc(sizeof(double) * m);
    return M;
}

int main() {
	int n;
	scanf("%d", &n);
	double ** M = new_matrix(n, n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			scanf("%lf", &M[i][j]);
	
	double ** inv_temp = inversed(n, M);
	
	double inv[n][n];
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			inv[i][j] = inv_temp[i][j];

	printf("inverted: \n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%10.6lf ", inv[i][j]);
		}
		printf("\n");
	}
	printf("proof:\n");
	mul(n, inv, M);
}

double gauss_det(int n, double M0[n][n]) {
	double M[n][n];
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			M[i][j] = M0[i][j];

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double k = M[j][i] / M[i][i];
			for (int l = 0; l < n; ++l) 
				M[j][l] -= k * M[i][l];
		}
	}

	double det = 1;
	for (int i = 0; i < n; ++i) 
		det *= M[i][i];
	return det;
}

double ** inversed(int n, double M[n][n]) {
	double ** inversedM = new_matrix(n, n);
    
	double detM = gauss_det(n, M);
	for (int i = 0; i < n; ++i) {	
		for (int j = 0; j < n; ++j) {
			double Minor[n - 1][n - 1];
			for (int k = 0, c0 = 0; k < n; ++k) {
				if (k != i) {
					for (int l = 0, c1 = 0; l < n; ++l) {
						if (l != j) {
							Minor[c0][c1] = M[k][l];
							c1++;
						}
					}
					c0++;
				}
			}
			double detA = gauss_det(n - 1, Minor);
			if (detA != 0)
				inversedM[i][j] = ((i + j) % 2 ? -1 : 1) * detA / detM;
			else printf("\nError\n");
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j > i) {
				double temp = inversedM[i][j];
				inversedM[i][j] = inversedM[j][i];
				inversedM[j][i] = temp;
			}
			
		}
	}
	return inversedM;
}

void mul(int n, double A[n][n], double B[n][n]) {
	printf("mul:\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			double s = 0;
			for (int k = 0; k < n; ++k)
				s += A[i][k] * B[k][j];
			printf("%10.6lf ", s);
		}
		printf("\n");
	}
}