#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
	srand(time(NULL));
	long long R = 400;
	double pi = 0.11111;
	double e = 1e-5;
	double pi_last = pi + R;
	int in_circle = 0;
	int N = 0;
	while (fabs(pi_last - pi) > e || N < 100) {
		pi_last = pi;
		double x = (rand() % (2 * R) - R) / (1.0*R);
		double y = (rand() % (2 * R) - R) / (1.0*R);
		N++;
		if (x*x + y*y < 1) {
			in_circle++;
		}
		
		pi = (in_circle * 4.0) / (N*1.0);

		printf("%d %d %f\n", in_circle, N, pi);
	}
	printf("--------%f\n", pi);
	// 3.141263
	return 0;
}