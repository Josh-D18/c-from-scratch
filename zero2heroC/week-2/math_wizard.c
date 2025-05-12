#include <stdio.h>

int main(int argc, char *argv[]){
    int num1;
    int num2;
    int option;
    int resultInt;
    float resultFloat;

    printf("Enter One Number: ");
    scanf("%d", &num1);
    printf("\n");
    printf("Enter A Second Number: ");
    scanf("%d", &num2);

    printf("\n1. Sum\n");
    printf("2. Difference\n");
    printf("3. Quotient\n");
    printf("4. Remainder\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        resultInt = num1 + num2;
        resultFloat = (float)resultInt;

        printf("\nInt result: %d", resultInt);
        printf("\nFloat result: %f", resultFloat);
        break;

    case 2:
        resultInt;

        if (num1 > num2)
        {
            resultInt = num1 - num2;
        } else{
            resultInt = num2 - num1;
        }
        
        resultFloat = (float)resultInt;

        printf("\nInt result: %d", resultInt);
        printf("\nFloat result: %f", resultFloat);
        break;

    case 3:
        resultInt = num1 * num2;
        resultFloat = (float)resultInt;

        printf("\nInt result: %d", resultInt);
        printf("\nFloat result: %f", resultFloat);
        break;

    case 4:
        resultInt = num1 / num2;
        resultFloat = (float)resultInt;

        printf("\nInt result: %d", resultInt);
        printf("\nFloat result: %f", resultFloat);
        break;

    default:
        return 0;
    }
}   

