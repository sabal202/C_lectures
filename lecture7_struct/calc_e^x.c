#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double ex = 1;
	double x;
	printf("e^");
	scanf("%lf", &x);

	double sum_i = x;
	int i = 1;
	double pow_x = 1;
	double last_ex = -1;
	while ((ex - last_ex) > 1e-7) {
		printf("ex=%.10lf\tsum_i=%.10lf\ti=%d\n", ex, sum_i, i);
		last_ex = ex;
		++i;
		ex += sum_i;
		sum_i *= x / i;
	}
	printf("e^%f=%.6lf\n", x, ex);
	return 0;
}
