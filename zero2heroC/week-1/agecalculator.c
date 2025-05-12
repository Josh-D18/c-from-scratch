// Ask for birth year and calculate their age
#include <stdio.h>

int main(){
    int age;
    int currentYear = 2024;

    printf("Enter your birth year: ");
    scanf("%d", &age);

    int result = currentYear - age; 

    printf("%d", result);

    return 0;
}

