// ⚔️ Weekly Mission: Pointer-Powered Gradebook
// Build a program that:
//     Asks the user for number of students
//     Dynamically allocates an array of grades
//     Calculates average, highest, and lowest using pointer arithmetic
//     Frees memory at the end (we’ll cover malloc in Week 6)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int return_average(int *arr, int number_of_students);
int return_highest(int *arr, int number_of_students);
int return_lowest(int *arr, int number_of_students);

int main(){
    int number_of_students = 0;
    int highest = 0;
    int lowest = 0;
    int average = 0;

    printf("How many students do you have in your class? ");
    scanf("%d", &number_of_students);

    int *array = malloc(number_of_students * sizeof(int));
    
    srand(time(NULL));

    for (int i = 0; i < number_of_students; i++)
    {
        array[i] = rand() % 101;
        printf("%d.%d ", i+1, array[i]);
    }
    
    printf("\nAverage: %d\n", return_average(array, number_of_students));
    printf("Highest: %d\n", return_highest(array, number_of_students));
    printf("Lowest: %d\n", return_lowest(array, number_of_students));
    
    free(array);
}

int return_average(int *arr, int number_of_students){
    int result = 0;
    int index = 0;

    while (index < number_of_students)
    {
        result += *(arr + index);
        index++;
    }

    return result / number_of_students;
}

int return_highest(int *arr, int number_of_students){
    int result = *arr;
    int index = 0;

    while (index < number_of_students)
    {
        if (result < *(arr + index))
        {
            result = *(arr + index);
        }
        index++;
    }
    return result;
}

int return_lowest(int *arr, int number_of_students){
    int result = *arr;
    int index = 0;

    while (index < number_of_students)
    {
        if (result > *(arr + index))
        {
            result = *(arr + index);
        }
        index++;
    }
    return result;
}