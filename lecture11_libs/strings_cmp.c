#include <stdio.h>
#include <string.h>

int main() {
	char s1[] = "Password";
	char s2[] = "pass";
	char s3[] = "pasport";
	char s4[] = "Password";
	printf("%d\t%d\t%d\n", strcmp(s1, s2), strcmp(s2, s3), strcmp(s1, s4));
	return 0;
}
