#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

float sr(float);

int main(int argc, char *argv[], char * envp[]) {
	char cStr1[] = "Количество передаваемых аргументов:";
	char cStr2[] = "Имя программы и передаваемые аргументы:\n";
	char cStr3[] = "Переменные среды:\n";
	CharToOem(cStr3, cStr3);
	CharToOem(cStr2, cStr2);
	CharToOem(cStr1, cStr1);
	printf("%s %d\n", cStr1, argc);
	printf("%s\n", cStr2);
	while (*argv) 
		printf("%s\n", *argv++);
	printf("%s\n", cStr3);
	while (*envp)
		printf("%s\n", *envp++);
	return 0;
}