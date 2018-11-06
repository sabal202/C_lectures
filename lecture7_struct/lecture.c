#include<stdio.h>
#include<stdlib.h>

struct student {
	char[30] name;
	char group;

} z;

int main() {
	
	struct student *p;
	p = &z;

	return 0;
}