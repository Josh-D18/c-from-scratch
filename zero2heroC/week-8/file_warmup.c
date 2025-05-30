//Write a program that:
    // Prompts for a name and favorite number

    // Saves it to a file (one line)

    // Reads it back and prints it out

#include <stdio.h>

int main(){
    int number = 0;
    int r_number = 0;
    FILE *file = NULL;
    char buffer[100];

    printf("Enter your favorite number: ");
    scanf("%d", &number);

    file = fopen("./fav_number.txt", "w");

    if (file == NULL)
    {
        printf("\nERROR, Could not open file!\n");
    } else
    {
        fprintf(file, "%d", number);
    }
    
    fclose(file);
    
    file = fopen("./fav_number.txt", "r");
    fscanf(file,"%d", &r_number);
    printf("\nYour favorite number is: %d", r_number);
    fclose(file);
    
    return 0;
}