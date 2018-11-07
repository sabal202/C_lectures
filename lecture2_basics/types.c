#include <stdio.h>

int main() {
	char ch;
	unsigned char ch1;
	int iVar1 = 90;
	int iVar2 = 045;
	int iVar3 = 0x45;
	printf("iVar1 = %d, iVar2 = %d, iVar3 = %d\n", iVar1, iVar2, iVar3);
	printf("Input simbol:  ");
	scanf("%c", &ch);
	ch1 = ch;
	printf("Kod %c = %d %d.\n\n", ch, ch, ch1);

	printf("char = %d\n", sizeof(char));
	printf("short = %d\n", sizeof(short));
	printf("int = %d\n", sizeof(int));
	printf("long = %d\n", sizeof(long));
	printf("float = %d\n", sizeof(float));
	printf("double = %d\n", sizeof(double));
	printf("long double = %d\n\n", sizeof(long double));

	printf("dec = %d, oct = %o, hex = %x, char = %c\n", iVar1, iVar1, iVar1, iVar1);
	printf("Z = %c, 132 = %c, x5a = %c\n", 'ß', '\132', '\x5a');
	printf("'Z' = %c, '\\132' = %c, '\\x5a' = %c\n", 'Z', '\132', '\x5a');
	return 0;
}