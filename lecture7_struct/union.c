#include <stdio.h>
#include <stdlib.h>

union u {
	int iVar;
	char cStr;
	long int lVar;
	double fVar;
};


int main() {
	union u alfa;
	union u *ptr = &alfa;
	ptr->iVar = 5;
	printf("d = %d\n", sizeof(alfa));
	printf("%p\tiVar = %d\n", &alfa.iVar, alfa.iVar);
	ptr->fVar = 5.6;
	printf("%p\tfVar = %f\n", &alfa.fVar, alfa.fVar);
	printf("%p\tiVar = %d\n", &alfa.iVar, alfa.iVar);
	return 0;
}
