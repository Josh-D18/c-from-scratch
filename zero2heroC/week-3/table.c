// Build a table.c that:
// Asks for a number n
// Prints the multiplication table from 1 to n using a loop
// If the input is invalid (e.g. < 1), show an error message
#include <stdio.h>

int main(){
    int user_input;

    printf("Please enter a number: ");
    scanf("%d", &user_input);

    if (user_input < 1)
    {
        printf("Error please provide a positive number!");
        return 1;
    }
    
    printf("\n");
    for (size_t i = 1; i < user_input; i++)
    {
        printf("%d ", i * user_input);
    }
    printf("\n"); 
}