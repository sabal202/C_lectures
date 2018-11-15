#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

float sr(float);

int main() {
	float x = 1;
	char sStr[] = "Enter x value:";
	CharToOem(sStr, sStr);
	while (x != 0) {
		printf("%s\n", sStr);
		scanf("%f", &x);
		if (x != 0)
			printf("res = %f\n", sr(x));
	}
	return 0;
}

float sr(float v) {
	static float res = 0;
	static int count = 0;
	count++;
	res += v;
	return res / (float) count;
}