#include <stdio.h>

int main()
{
	int iVar1 = 2, iVar2 = 7, iVar3 = 3;
	if (iVar1 > iVar2) {
		if (iVar2 < iVar3)
			iVar3 = iVar2;
	} else iVar3 = iVar1;
	printf("iVar3 = %d\n", iVar3);

	iVar1 = 2, iVar2 = 7, iVar3 = 3;
	if (iVar1 > iVar2) 
		if (iVar2 < iVar3)
			iVar3 = iVar2;
	 	else iVar3 = iVar1;
	printf("iVar3 = %d\n", iVar3);
	return 0;
}