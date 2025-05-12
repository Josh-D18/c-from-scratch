// CLI Menu System
// Build a text-based menu using switch:

#include <stdio.h>
void menu();

int main(){
    int user_input = 0;
    menu();

    scanf("%d", &user_input);

    switch (user_input)
    {
    case 1:
        printf("Starting game...");
        break;
    
    case 2:
        printf("Loading game...");
        break;

    case 3:
        printf("Quitting...");
        break;
    
    default:
        printf("Error!");
        break;
    }
}


void menu(){
    printf("1. Start Game\n");
    printf("2. Load Game\n");
    printf("3. Quit\n");
    printf("\n");
    printf("Please select an option: ");
}
