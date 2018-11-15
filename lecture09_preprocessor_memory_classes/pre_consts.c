#include <stdio.h>
#include <stdlib.h>

#define LN printf("\n")

int main() {
	printf(__DATE__); LN;
	printf("%d", __LINE__); LN;
	printf(__FILE__); LN;
	printf(__TIME__); LN;
	
	return 0;
}