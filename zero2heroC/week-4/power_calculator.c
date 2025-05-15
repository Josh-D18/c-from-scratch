// Power Calculator
// Write a function int power(int base, int exp) that returns base^exp.
#include <stddef.h>
#include <stdio.h>

int power(int base, int exp);

int main(){
    int base;
    int exp;

    printf("Please enter the base number: ");
    scanf("%d", &base);

    printf("Please enter the exponential number: ");
    scanf("%d", &exp);

    int result = power(base, exp);

    printf("\nPower Result: %d", result);
}

int power(int base, int exp){
    int result = 1;

    for (size_t i = 0; i < exp; i++)
    {
        result = base * result;
    };

    return result;
}