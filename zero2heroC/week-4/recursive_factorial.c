// Recursive Factorial
// Do the same factorial() but using recursion instead of a loop.

int factorial(int n);

int main() {
    int user_input = 0;
    printf("Please Enter A Number: ");
    scanf("%d", &user_input);

    printf("\nFactorial Result: %d", factorial(user_input))
}

int factorial(int n){
    if (n < 1)
    {
        return 1;
    }
    return n * factorial(n-1) * 1;
}
