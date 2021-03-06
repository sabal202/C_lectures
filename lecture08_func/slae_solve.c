#include <stdlib.h>
#include <stdio.h>

/*
Enter n - size of matrix
Enter matrix n x (n + 1)
Example:
3
1 2 30 1
2 30 4 1
30 4 5 1
*/

void kramer(int n, double ** M0);

void replace_col(int n, int col, double ** M, double * b);

double det(int n, double ** M0);

double det_gauss(int n, double ** M);

void gauss(int n, double ** M0);

double ** new_matrix(int n, int m) {
	double ** M = (double **) calloc(n, sizeof(double *));
	for (int i = 0; i < n; ++i)
        M[i] = (double *) calloc(m, sizeof(double));
    return M;
}

int main() {
	int n;
	scanf("%d", &n);
	double ** M = new_matrix(n, n + 1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n + 1; ++j) 
			scanf("%lf", &M[i][j]);
	printf("\nGauss:\n");
	gauss(n, M);
	
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n + 1; ++j) {
	// 		printf("%10.6lf ", M[i][j]);
	// 	}
	// 	printf("\n");
	// }
	printf("\nKramer:\n");
	kramer(n, M);
}


void replace_col(int n, int col, double ** M, double * b) {
	for (int i = 0; i < n; ++i)
		M[i][col] = b[i];
}

void kramer(int n, double ** M0) {
	double * b = (double*) calloc(n, sizeof(double));
	for (int i = 0; i < n; ++i)
		b[i] = M0[i][n];
	double ** M = new_matrix(n, n);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			M[i][j] = M0[i][j];

	double detA = det(n, M);
	if (detA == 0) {
		printf("ERROR Det = 0\n");
		return;
	}
	printf("Det = %lf\n", detA);
	double * x = (double*) calloc(n, sizeof(double));
	for (int i = 0; i < n; ++i) {
		double * tempv = (double*) calloc(n, sizeof(double));		
		for (int j = 0; j < n; ++j) 
			tempv[j] = M[j][i];

		replace_col(n, i, M, b);

		printf("A_%d:\n", i);
		for (int y = 0; y < n; ++y) {
			for (int u = 0; u < n; ++u) {
				printf("%10.6lf ", M[y][u]);
			}
			printf("\n");
		}
		double detAi = det(n, M);
		printf("detA_%d = %lf\n", i, detAi);

		replace_col(n, i, M, tempv);
		x[i] = detAi / detA;
	}
	for (int j = 0; j < n; ++j) {
		printf("x_%d = %lf\n", j + 1, x[j]);
	}
}

double det(int n, double ** M0) {
	if (n == 2) {
		return M0[0][0] * M0[1][1] - M0[0][1] * M0[1][0];
	}
	double ** M = new_matrix(n, n);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			M[i][j] = M0[i][j];
	double res = 0;

	int ind = 0;
	int maxnum = 0;
	for (int i = 0; i < n; ++i) {
		int num0 = 0;
		for (int j = 0; j < n; ++j) {
			if (M[i][j] == 0)
				num0 ++;
		}
		if (num0 > maxnum) {
			maxnum = num0;
			ind = i;
		}
	}

	/* magic */
	for (int j = 0; j < n; ++j) {
		/* create minor */
		double ** Minor = new_matrix(n - 1, n - 1);
		for (int k = 0, c0 = 0; k < n; ++k) {
			if (k != ind) {
				for (int l = 0, c1 = 0; l < n; ++l) {
					if (l != j) {
						Minor[c0][c1] = M[k][l];
						c1++;
					}
				}
				c0++;
			}
		}
		// printf("Minor for i=%d,j=%d:\n", ind, j);
		// for (int i = 0; i < n - 1; ++i) {
		// 	for (int j = 0; j < n - 1; ++j) {
		// 		printf("%10.6lf ", Minor[i][j]);
		// 	}
		// 	printf("\n");
		// }
		res += ((ind + j) % 2 ? -1 : 1) * M[ind][j] * det(n - 1, Minor);
	}
	
	return res;
}

double det_gauss(int n, double ** M) {
	double res = 1;
	for (int i = 0; i < n; ++i) 
		res *= M[i][i];
	return res;
}

void gauss(int n, double ** M0) {
	double ** M = new_matrix(n, n + 1);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n + 1; ++j) 
			M[i][j] = M0[i][j];

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (M[i][i] == 0) {
				printf("ERROR Det = 0\n");
				return;
			}
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
		printf("ERROR Det = 0\n");
		return;
	} else {
		printf("Det = %lf\n", det);
	}

	double * x = (double *) calloc(n, sizeof(double));
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