#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(int argc, char *argv[]) {
	char B[] = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ 1234567890-!?(),.ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	// printf("Max length: ");
	// scanf("%d", &n);
	// fflush(stdin);
	printf("Enter line: ");
	char * line = (char*) calloc(2000, sizeof(char));
	// scanf("%s", line);
	gets(line);
	n = strlen(line);
	int command;
	printf("%s\n", line);
	while (1) {
		printf("Choose:\n1. Encode\n2. Decode\n3. Exit\n");
		scanf("%d", &command);
		int shift;
		switch (command) {
			case 1:
	   			printf("Enter shift: ");
	   			scanf("%d", &shift);
				for (int i = 0; i < n; ++i) {
					char * index = strchr(B, line[i]);
					if (index == NULL) {
			   			printf("Not found %c\n", line[i]);
			   		} else {
			   			line[i] = B[((index - B) + shift) % 136];
			   		}
				}
				printf("%s\n", line);
				break;
			case 2:
	   			printf("Enter shift: ");
	   			scanf("%d", &shift);
				for (int i = 0; i < n; ++i) {
					char * index = strchr(B, line[i]);
					if (index == NULL) {
						printf("Not found %c\n", line[i]);
					} else {
						line[i] = B[((index - B) - shift) % 136];
					}
				}
				printf("%s\n", line);
				break;
			case 3:
				exit(1);
			default:
			 printf("Error, %c\n", line[n - 1]);
			 exit(1);
			break;
		}
	}
	free(line);
	return 0;
}
