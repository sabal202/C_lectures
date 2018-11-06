#include <stdio.h>

int main()
{
	int A[3][4] = {{1, 2, 3, 4},
					{2, 4, 0 , 1},
					{3, -1, 2, 4}};
	int B[4][2] = {{2, -1},
					{3, 2},
					{3, 4},
					{2, -2}};
	int C[3][2];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j) {
			C[i][j] = 0;
			for (int k = 0; k < 4; ++k)
				C[i][j] += A[i][k] * B[k][j];
		}
	printf("C:\n");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j)
			printf("%3d ", C[i][j]);
		printf("\n");
	}
	return 0;
}