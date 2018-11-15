#include <stdlib.h>
#include <stdio.h>

int main() {    
    int i, j, lines, columns;

    printf("n = ");
    scanf("%d", &lines);
    printf("m = ");
    scanf("%d", &columns);

    int **matrix = (int **) malloc(sizeof(int*)*lines); 
    for (int i = 0; i < lines; ++i) {
        matrix[i] = (int*) malloc(sizeof(int) * columns);
    }
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}