#include <stdio.h>
#include <stdlib.h>

#define v(x) (x*x*x)
#define V(x) ((x)*(x)*(x))

int main() {
	float a = 2;
	printf("v = %f\n", v(a + 3));
	printf("V = %f\n", V(a + 3));
	return 0;
}