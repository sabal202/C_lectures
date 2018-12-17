/* Чтение и запись в файл с функцией  feof()*/

#include <stdio.h >
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
	
int main()
{
	FILE *in, *out;
	long num = 10L;
	/* #include<locale.h> */
	setlocale(LC_ALL, "rus");
//	setlocale(0, "");
	/*#include <windows.h>*/
	// SetConsoleOutputCP(1251); 
	// SetConsoleCP(1251); 
	printf("Читаем на русском языке!\n");

	if ((in = fopen("test.txt", "r")) == NULL) {
		printf("Не открыть файл \n");
	} else {
		out = fopen("data1.txt", "w");
		//fseek(in, num, 0);
		do { 
			fprintf(out, "%c", getc(in));
		} while (!feof(in));
		fflush(out);
		fclose(in);
		fclose(out);
	}
	// system("pause");
	return 0;
}
