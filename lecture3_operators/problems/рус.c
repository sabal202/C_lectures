#include <stdio.h>

int main()
{
	printf("мама\n");
	char cStr[] = "Русский текст!!!"; // работает только в OEM (Windows 866)
	printf("%25s\n", cStr);
	printf("%-25s\n", cStr);
	printf("%25.6s\n", cStr);
	printf("%-25.6s\n", cStr);
	return 0;
}