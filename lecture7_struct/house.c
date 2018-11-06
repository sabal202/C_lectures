#include<stdio.h>
#include<stdlib.h>

struct house {
	float ds;
	int rooms;
	int stories;
	char *address;
};

int main() {
	struct house fr = {25000, 6, 5, "Baker street"};
	struct house *sign;
	sign = &fr;
	printf("%d %d\n", fr.rooms, sign->stories);
	printf("%s\n", fr.address);
	printf("%c %c \n", sign->address[7], fr.address[10]);
	return 0;
}