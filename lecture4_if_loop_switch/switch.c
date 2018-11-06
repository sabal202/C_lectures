#include <stdio.h>

int main()
{
	char c;
	float x, y = 2, z = 5;
	printf("Enter the operator sign: (+ - ! / ) : ");
	scanf("%c", &c);
	switch (c) {
		case '-': x = y - z;
			break;
		case '+': x = y + z;
			break;
		case '*': x = y * z;
			break;
		case '/': x = y / z;
			break;
		default: printf("Unknown operation.\n");
			x = 0;
	}
	printf("x = %f\n", x);
	return 0;
}