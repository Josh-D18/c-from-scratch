// Prompt the user for their name and greet them
#include <stdio.h>

int main(){
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hey %s, welcome to C!\n", name);

    return 0;
}