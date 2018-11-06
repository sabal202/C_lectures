#include<stdio.h>
#include<stdlib.h>

struct complex {
	double x;
	double y;
};

_Bool is_nul(struct complex z);

struct complex scalar(double lam, struct complex z);

struct complex sum(struct complex z1, struct complex z2);

struct complex sub(struct complex z1, struct complex z2);

struct complex mul(struct complex z1, struct complex z2);

struct complex division(struct complex z1, struct complex z2);

int main() {
	struct complex z1, z2;
	printf("z1 = ");
	scanf("%lf%lf", &z1.x, &z1.y);
	print(z1);
	do {
		printf("z2 = ");
		scanf("%lf%lf", &z2.x, &z2.y);
	} while(is_nul(z2));
	print(z2);

	printf("z1+z2 = ");
	print(sum(z1, z2));

	printf("z1-z2 = ");
	print(sub(z1, z2));

	printf("z1*z2 = ");
	print(mul(z1, z2));

	printf("z1/z2 = ");
	print(division(z1, z2));

	printf("2*z1-2*z2 = ");
	print(sub(scalar(2, z1), scalar(2, z2)));

	return 0;
}

void print(struct complex z) {
	double a = z.x, b = z.y;
	if (a != 0 && b != 0)
		printf("(%.2lf%+.2lfj)\n", a, b);
	else if (a == 0 && b == 0)
		printf("0\n");
	else if (b == 0) 
		printf("%.2lf\n", a);
	else if (a == 0)
		printf("%.2lfj\n", b);
	
}

struct complex sum(struct complex z1, struct complex z2) {
	struct complex za;
	za.x = z1.x + z2.x;
	za.y = z1.y + z2.y;
	return za; 
}

struct complex sub(struct complex z1, struct complex z2) {
	struct complex za;
	za.x = z1.x - z2.x;
	za.y = z1.y - z2.y;
	return za; 
}

struct complex mul(struct complex z1, struct complex z2) {
	struct complex za;
	za.x = z1.x * z2.x - z2.y * z1.y;
	za.y = z1.y * z2.x + z1.x * z2.y;
	return za; 
}

_Bool is_nul(struct complex z) {
	if (z.x == 0 && z.y == 0) {
		printf("Must be not 0\n");
		return 1;
	}
	return 0; 
}

struct complex scalar(double lam, struct complex z) {
	struct complex za;
	za.x = z.x * lam;
	za.y = z.y * lam;
	return za; 
}

struct complex division(struct complex z1, struct complex z2) {
	struct complex za;
	za.x = (z1.x * z2.x + z2.y * z1.y) / (z2.x*z2.x + z2.y*z2.y);
	za.y = (z1.y * z2.x - z1.x * z2.y) / (z2.x*z2.x + z2.y*z2.y);
	return za; 
}