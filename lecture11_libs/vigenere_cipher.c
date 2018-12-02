#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

int main(int argc, char *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char B[] = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ 1234567890-!?(),.ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int alphlen = strlen(B);
	int len, keylen;
	printf("Enter line: ");
	char * line = (char*) calloc(2048, sizeof(char));
	gets(line);
	fflush(stdin);
	printf("%s\n", line);
	len = strlen(line);
	int command;
	printf("Enter key: ");
	char * key = (char*) calloc(2048, sizeof(char));
	gets(key);
	keylen = strlen(key);
	printf("alphlen(must be 136)=%d\n", alphlen);

	while (1) {
		printf("Choose:\n1. Encode\n2. Decode\n3. Exit\n");
		scanf("%d", &command);
		int shift;
		switch (command) {
			case 1:
				for (int i = 0; i < len; ++i) {
					char * index = strchr(B, line[i]);
					char * kind = strchr(B, key[i % keylen]);
					shift = kind - B;
			   		line[i] = B[(index - B + shift + alphlen) % alphlen];
				}
				printf("%s\n", line);
				break;
			case 2:
				for (int i = 0; i < len; ++i) {
					char * index = strchr(B, line[i]);
					char * kind = strchr(B, key[i % keylen]);
					shift = kind - B;
					line[i] = B[(index - B - shift + alphlen) % alphlen];
				}
				printf("%s\n", line);
				break;
			case 3:
				exit(1);
			default:
			 printf("Error, %c\n", line[len - 1]);
			 exit(1);
			break;
		}
	}
	free(line);
	return 0;
}