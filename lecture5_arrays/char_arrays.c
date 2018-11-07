#include <stdio.h>

int main()
{
	char s[] = "mars";
	s[2] = 'p';
	printf("%s\n", s);

	char* s1 = "mars";

	printf("%s\n", s1);

	int iArr[] = {1,2,3,4,5};
	int *iPtr = iArr;

	printf("end\n");


	return 0;
}