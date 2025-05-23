// Dynamic Matrix
// Create a 2D array (matrix) using int **matrix. Allocate each row manually.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int ROWS = 2;
    int COLUMNS = 5;
    int index = 0;

    int **matrix = malloc(ROWS * sizeof(int*));
    int *array_one = malloc(COLUMNS * sizeof(int));
    int *array_two = malloc(COLUMNS * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        array_one[i] = rand() % 300 + 1;
        array_two[i] = rand() % 500 + 1;
    };

    matrix[0] = array_one;
    matrix[1] = array_two;

    for (int i = 0; i < ROWS; i++)
    {
        while (index < COLUMNS)
        {
            printf("Printing Values From Column %d: %d \n", i + 1, matrix[i][index]);
            index++;
        }
        index = 0;
    }

    int new_index = 0;

    while (new_index < ROWS)
    {
        free(matrix[new_index]);
        new_index++;
    }
    
    free(matrix);
}