// Write a function void swap(int *a, int *b) that swaps two values.
#include <stdio.h>

void swap(int *a, int *b);

int main(){

    int a, b;

    printf("Please enter a value for a: ");
    scanf("%d", &a);

    printf("Please enter a value for b: ");
    scanf("%d", &b);

    printf("\nBefore: a: %d  b: %d", a, b);

    swap(&a, &b);

    printf("\nAfter: a: %d  b: %d", a, b);
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}