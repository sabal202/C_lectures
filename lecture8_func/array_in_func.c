#include <stdio.h>
#include <stdlib.h>

#define n 5

float Sum(float[]);

int main()
{
	float aVar[] = {1.5, 4.5, 5.0, 10.0, 15.5};
	float rez;
	rez = Sum(aVar) / (float) n;
	printf("Sum = %f\n", rez);
	
	system("pause");
	return 0;
}

float Sum(float aFVar[])
{
	float f = 0;
	for (int i = 0; i < n; i++)
		f += aFVar[i];
	return f;
}
