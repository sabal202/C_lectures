#include <stdio.h>

int main()
{
	char c[] = {'m', 'a', 'p', '\0'};
	char c1[] = "map";
	printf("c = %d\tc1 = %d\n", sizeof(c), sizeof(c1));
	int i[] = {1, 2, 3, 4};
	int i1[] = {1};
	printf("i = %d\ti1 = %d\n", sizeof(i), sizeof(i1));
	return 0;
}