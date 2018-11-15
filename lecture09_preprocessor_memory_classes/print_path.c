#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[], char * envp[]) {
	while (*envp) {
		if ((*envp)[0] == 'P' && (*envp)[1] == 'a' && (*envp)[2] == 't' && (*envp)[3] == 'h') {
			char * cp = *envp;
			envp++;
			int index = 0;
			while (*envp - cp > 0) {
				printf("%c", *cp);
				if (*cp == ';') 
					printf("\n");
				if (*cp == '=' && index == 1)
					break;
				if (*cp == '=' && index == 0) {
					index++;
					printf("\n");
				}
				cp++;
			}
		}
		envp++;
	}
	return 0;
}
