#include <stdlib.h>
#include <stdio.h>

void swap(int x, int y);
void swap1(int *x, int *y);

int main()
{
    int a = 10, b = 20;
    swap(a, b);
    printf("a = %d\tb = %d\n", a, b);
    swap1(&a, &b);
    printf("a = %d\tb = %d\n", a, b);

    return 0;
}

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    printf("x = %d\ty = %d\n", x, y);
}
void swap1(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("x = %d\ty = %d\n", *x, *y);
}
