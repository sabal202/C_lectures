#include <stdio.h>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int iVar = 56;
	float fVar = 45.567f;
	char cStr[] = "������� �����!";
	// CharToOem(cStr, cStr); // to Windows 866
	printf("iVaf = %5d\tfVar = %5.2f\tfVar=%6e\n", iVar, fVar, fVar);
	printf("%25s\n", cStr);
	printf("%-25s\n", cStr);
	printf("%25.6s\n", cStr);
	printf("%-25.6s\n", cStr);
}