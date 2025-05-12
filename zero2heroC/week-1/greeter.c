// Create a CLI tool called greeter that takes a name and prints:
// "Good day, [name]. Welcome back to the code mines."
// Support both user input (scanf) and command-line input (argv).

#include <stdio.h>

int main(int argc, char *argv[]){

    char name[50];

    if(argc < 2){
        printf("What is your name? ");

        scanf("%s", name);
        printf("Good day, %s. Welcome back to the code mines.", name);
    } else {
        printf("Good day, %s. Welcome back to the code mines.", argv[1]);
    }
}