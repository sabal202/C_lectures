#include <stdio.h>

int main() {
    int a, b, c, d, r, s;
    float g, f, h;
    char* pChar;
    int* pInt;
    a = b = 1;
    s = a + b++;
    printf("a = %d\tb = %d\ts = %d\n", a, b, s);
    c = d = 3;
    r = c+ ++d;
    printf("c = %d\td = %d\tr = %d\n", c, d, r);
    c = d = 3;
    r = c+++d;
    printf("c = %d\td = %d\tr = %d\n", c, d, r);
    c = d = 3;
    r = c+++d++;
    printf("c = %d\td = %d\tr = %d\n", c, d, r);
    c = d = 3;
    r = -c+d++;
    printf("c = %d\td = %d\tr = %d\n", c, d, r);
    g = 3.5;
    f = 4.2;
    h = ++g+-f;
	printf("g = %.1f\tf = %.1f\th = %.1f\n", g, f, h);
	char cChar = 'a';
	pChar = &cChar;
	printf("cChar = %c\tcChar = %p \n", cChar, &cChar);
    /* Дополнение */
    unsigned char cVar1 = 140, cVar2;
    cVar2 = ~cVar1;
    printf("cVar1 = %d\tcVar2 = %d \n", cVar1, cVar2);
    printf("cVar1 = %c\tcVar2 = %c \n", cVar1, cVar2);
    return 0;
}