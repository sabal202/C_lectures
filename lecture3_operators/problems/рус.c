#include <stdio.h>

int main()
{
	printf("����\n");
	char cStr[] = "���᪨� ⥪��!!!"; // ࠡ�⠥� ⮫쪮 � OEM (Windows 866)
	printf("%25s\n", cStr);
	printf("%-25s\n", cStr);
	printf("%25.6s\n", cStr);
	printf("%-25.6s\n", cStr);
	return 0;
}