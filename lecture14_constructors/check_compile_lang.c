#include <stdio.h>

int main() {
	printf("%s", (sizeof('a') == sizeof(char)) ? "C++" : "C");
	return 0;
}