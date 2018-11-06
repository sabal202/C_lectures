#include <stdio.h>

int main() {
	int x, y = 10, *address;
	address = &x;
	*address = y;
	printf("y = %d\tx = %d\tpointer = %p", y, x, address);
}