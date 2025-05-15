// Make a file mathlib.c with reusable functions:
    // int square(int x)
    // int factorial(int n)
    // int is_even(int x)
// Test them in main() with inputs from the user.

#include <stdio.h>

int square(int x);
int factorial(int n);
int is_even(int x);

int main(){
    int user_input = 0;
    int square_result = 0;
    int factorial_result = 0;
    int is_even_result = 0;

    printf("Please enter a number: ");
    scanf("%d", &user_input);
    printf("\n");

    square_result = square(user_input);

    printf("Square Result: %d", square_result);
    printf("\n");

    factorial_result = factorial(user_input);

    printf("Factorial Result: %d", factorial_result);
    printf("\n");

    is_even_result = is_even(user_input);

    printf("Is Even Result: %d", is_even_result);
    printf("\n");
}   

int square(int x){
    return x * x;
}

int factorial(int n){
    // Use a loop
    int result = 1;
    int num_tracker = n;

    if (n < 1)
    {
        return 1;
    }
    
    for (size_t i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int is_even(int x){
    if (x % 2 == 0)
    {
        return 0;
    } else
    {
        return 1;
    }
}