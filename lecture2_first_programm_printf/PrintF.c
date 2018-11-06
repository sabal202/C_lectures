#include <stdio.h>
#include <windows.h>

int main() {
	int iVar = 56;
	float fVar = 45.567f;
	char cStr[] = "������� �����!!!";
	CharToOem(cStr, cStr); // ���� �������� ���� � ��������� windows 1251
	printf("iVaf = %5d\tfVar = %5.2f\tfVar=%6e\n", iVar, fVar, fVar);
	printf("%25s\n", cStr);
	printf("%-25s\n", cStr);
	printf("%25.6s\n", cStr);
	printf("%-25.6s\n", cStr);
}

/*
iVaf =    56    fVar = 45.57    fVar=4.556700e+001
         ������� �����!!!
������� �����!!!
                   ������
������
*/