#include "utils.h"
#include <stdio.h>

void menu(){
    printf("\n");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Divide");
    printf("\n5. Power");
    printf("\n6. Exit")
    printf("\n");
}

int return_user_input(){
    int user_input = 0;
    printf("\nPlease select an option: ");
    scanf("%d", &user_input);

    return user_input;
}

void add(int a, int b){
    printf("\n Addition result: %d", a + b);
};

void subtraction(int a, int b){
    if (a < b)
    {
        printf("\n Subtraction result: %d", b - a);
    } else{
        printf("\n Subtraction result: %d", a - b);
    }
}

void multiplication(int a, int b){
    printf("\n Multiplication result: %d", a * b);
}

void divide(int a, int b){
    if (b == 0)
    {
        printf("Cannot divide by zero");
    } else
    {
        printf("\n Division result: %d", a / b);
    }
}

void power(int base, int exp){
    int result = 1;

    for (size_t i = 0; i < exp; i++)
    {
        result = base * result;
    };

    printf("\n Power result: %d", result);
}


void program(){
    int is_program = 0;

    while (is_program == 0)
    {
        menu();
        int input = return_user_input();
        
        switch (input)
        {
        case 1:
            int a = 0;
            int b = 0;

            printf("Please enter in a number: ");
            scanf("%d", &a);

            printf("Please enter in the second number: ");
            scanf("%d", &b);

            add(a, b);
            break;
        
        case 2:
            int c = 0;
            int d = 0;

            printf("Please enter in a number: ");
            scanf("%d", &c);

            printf("Please enter in the second number: ");
            scanf("%d", &d);

            subtraction(c,d);
            break;
        
        case 3:
            int e = 0;
            int f = 0;

            printf("Please enter in a number: ");
            scanf("%d", &e);

            printf("Please enter in the second number: ");
            scanf("%d", &f);

            multiplication(e, f);
            break;
        
        case 4:
            int g = 0;
            int h = 0;

            printf("Please enter in a number: ");
            scanf("%d", &g);

            printf("Please enter in the second number: ");
            scanf("%d", &h);

            divide(g, h);
            break;
        
        case 5:
            int i = 0;
            int j = 0;

            printf("Please enter in a number: ");
            scanf("%d", &i);

            printf("Please enter in the second number: ");
            scanf("%d", &j);

            power(i, j);
            break;

        default:
            printf("Goodbye!");
            is_program = 1;
            break;
        }
    }
}