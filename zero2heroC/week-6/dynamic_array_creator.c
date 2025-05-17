// Dynamic Array Creator
// Build a program that:
//     Asks the user how many items they want to store
//     Allocates an array of ints dynamically
//     Lets the user fill the array
//     Prints the array
//     Frees the memory
#include <stdio.h>
#include <stdlib.h>

int main(){
    int items_stored;
    int index = 0;

    printf("How many items do you want to store? ");
    scanf("%d", &items_stored);

    int *array = malloc(items_stored * sizeof(int));

    printf("\nLet's fill the array!\n");
    
    while (index < items_stored)
    {
        int number_selected = 0;

        printf("\nEnter a number: ");
        scanf("%d", &number_selected);

        *(array + index) = number_selected; 
        index++;
    }
    
    printf("\nValues: ");

    for (int i = 0; i < items_stored; i++)
    {
        printf("%d ", array[i]);
    }
    
    free(array);
    printf("\nGoodbye!");
}