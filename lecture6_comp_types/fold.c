#include <stdlib.h>
#include <stdio.h>
float n, m;

float find_det(int a, int b, double M[a][b], int x1, int x2, int y1, int y2) {
	float res = 0;
	if (x2 - x1 + 1 == 2 && y2 - y2 + 1== 2) {
		return M[x1][y1] * M[x2][y2] - M[x2][y1] * M[x1][y2];
	}

	return res;
}

int main() {
	
	scanf("%f%f", &n, &m);
	// double M[n][m];
	// double c;
	printf("%f %f\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%f", &c);
			M[i][j] = c;
			printf("%f\n", c);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%f ", M[i][j]);
		}
		printf("\n");
	}
	printf("%f\n", find_det(n,m, M, 0, 0, 1, 1));

}