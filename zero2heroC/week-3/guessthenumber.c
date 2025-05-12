// Guess the Number
// Use rand() to generate a random number (0–99), and let the user guess until they get it right.
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int upper_bound = 100;
    int lower_bound = 1;
    int user_input = 0;

    int random_num = rand() % (upper_bound - lower_bound + 1)
    + lower_bound;

    do
    {
        printf("Please pick a number from 1 - 100: ");
        scanf("%d", &user_input);
    } while (user_input != random_num);
    

    printf("You guessed correctly!");
    return 0;
}