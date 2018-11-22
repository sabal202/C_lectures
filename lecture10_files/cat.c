#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Expected 1 argument, got %d\n", argc - 1);
		exit(1);
	}
	FILE *in;
	if ((in = fopen(argv[1], "r")) == NULL) {
		printf("File not found\n");
		exit(1);
	}
	char ch;
	while (!feof(in)) {
		ch = getc(in);
		printf("%c", ch);
	}

	fclose(in);

	return 0;
}