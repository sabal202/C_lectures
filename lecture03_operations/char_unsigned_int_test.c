#include <stdio.h>
int main() {
	int cInt = -29;
	unsigned int ucInt = -24;
	printf("%c %c\n", cChar, ucChar);
	ucInt--;
	printf("%d %d\n", cInt, ucInt);
	printf("%u %u\n", cInt, ucInt);
	cInt = cInt + ucInt;
	printf("%d\n", cInt);
	return 0;
}