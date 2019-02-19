#include <stdio.h>


int main() {
	int iVar1 = 0x5f, iVar2 = 0xa9;
	int iResult;
	iResult = iVar1 & iVar2;
	printf("'&' iResult = %xh\n", iResult);
	iResult = iVar1 | iVar2;
	printf("'|' iResult = %xh\n", iResult);
	iResult = iVar1 ^ iVar2;
	printf("'^' iResult = %xh\n", iResult);
	int iVar3 = 0x25, iVar4 = 0xa4;
	iVar3 += iVar4;
	printf("iVar3 = %oo\tiVar3 = %dd\tiVar3 = %Xh\t\n", iVar3, iVar3, iVar3);
	return 0;
}