#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Есть ли связь между ростом(x) и весом(y)?
Если есть, то какая эта зависимость? (линейная\не линейная)
из файла считать рост и вес
185 60
190 75
нужно найти коэффициент корреляции
если он больше 0.5, то есть линейная зависимость
найдем уравнение прямой
экстраполируем

*/

FILE * open(char * name, char * mode) {
	FILE *in;
	if ((in = fopen(name, mode)) == NULL) {
		printf("File not found\n");
		exit(1);
	}
	return in;
}

double f(double x, double M2, double D2, double D1, double R, double M1) {
	return M2 + (D2 / D1) * R * (x - M1);
}

int main(int argc, char *argv[]) {
	// double M1 = () / 8.0;
	// double M2 = () / 8.0;

	if (argc != 2) {
		printf("Expected 1 argument, got %d\n", argc - 1);
		exit(1);
	}
	FILE *in = open(argv[1], "r");

	int n = 0;
	while (!feof(in)) {
		char ch = getc(in);
		if (ch == '\n') n++;
	}
	if (n == 0) {
		printf("file is empty\n");
		exit(1);
	}
	n++;

	int * X = (int *) calloc(n, sizeof(int));
	int * Y = (int *) calloc(n, sizeof(int));
	rewind(in);
	char ch;
	int j = 0;
	do {
		int x, y;
		fscanf(in,"%d %d", &x, &y);
		X[j] = x;
		Y[j] = y;
		j++;
		printf("%d %d\n", x, y);
	} while (!feof(in));

	double M1 = 0, M2 = 0;
	for (int i = 0; i < n; ++i) {
		M1 += X[i];
		M2 += Y[i];
	}
	M1 /= n; M2 /= n;
	double D1;
	for (int i = 0; i < n; ++i){
		D1 += (X[i] - M1) * (X[i] - M1);
	}
	D1 /= n;
	D1 = pow(D1, 0.5);
	double D2;
	for (int i = 0; i < n; ++i){
		D2 += (Y[i] - M2) * (Y[i] - M2);
	}
	D2 /= n;
	D2 = pow(D2, 0.5);
	double R;
	for (int i = 0; i < n; ++i){
		R += (X[i] - M1) * (Y[i] - M2);
	}
	R /= n;
	R /= D1;
	R /= D2;
	printf("%d\n", n);

	printf("y_r = %lf + (%lf / %lf) * %lf *(x - %lf)\n", M2, D2, D1, R, M1);
	for (int i = 100; i <= 250; i += 5)
	{
		printf("%d: %lf\n", i, f(i*1.0, M2, D2, D1, R, M1));
	}
	// printf("Enter height: ");
	// double h;
	// scanf("%lf", &h);
	// printf("Weight = %lf", f(h*1.0, M2, D2, D1, R, M1));
	fclose(in);

	return 0;
}