#include <stdio.h>


int main()
{
	int iVar1 = 8, iVar2;
	printf("8:\n");
	printf("Right %d\t%d\t%d\n", iVar1 >> 1, iVar1 >> 2, iVar1 >> 3);
	printf("Left %d\t%d\t%d\n", iVar1 << 1, iVar1 << 2, iVar1 << 3);
	iVar1 = -8;
	printf("-8:\n");
	printf("Right %d\t%d\t%d\n", iVar1 >> 1, iVar1 >> 2, iVar1 >> 3);
	printf("Left %d\t%d\t%d\n", iVar1 << 1, iVar1 << 2, iVar1 << 3);
	printf("Input iVar1, iVar2\t");
	scanf("%d%d", &iVar1, &iVar2);
	printf("iVar1 && iVar2=%d\n", iVar1 && iVar2);
	printf("iVar1 || iVar2=%d\n", iVar1 || iVar2);
	printf("!iVar1=%d\n", !iVar1);
	return 0;
}