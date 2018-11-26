#include <stdio.h>


int (*fun)(int, int), sum(int, int), sub(int, int);

int main() {
	int a = 10, b = 20, c;
	c = sum(a, b);
	printf("c = %d\tsum = %d\trazn = %d\n", c, sum(a, b), sub(a, b));
	fun = sum;
	printf("*fun = %d\n", (*fun)(a, b));
	fun = razn;
	printf("*fun = %d\n", (*fun)(a, b));	

	return 0;
}

int sum(int x, int y) {
	return (x + y); 
}
int sub(int x, int y) {
	return (y - x); 
}
