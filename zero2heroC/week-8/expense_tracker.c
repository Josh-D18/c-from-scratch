// Budget Tracker (Heap Edition)
// Build a CLI program that:
//     Lets the user add expenses (amount + label)
//     Dynamically grows the list using realloc
//     Calculates total spent
//     Frees all allocated memory on exit
// Bonus:
//     Use structs to store each expense 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Expenses
{
    float amount;
    char  label[100];
};

void menu();

int main(){
    int expense_tracker_amount = 0;
    int expense_quantity_tracker = 5;
    int program = 0;
    FILE *file = NULL;

    printf("-------------Budget Tracker-----------\n");

    while (program == 0)
    {
        int user_input = 0;
        int array_amount = 0;
        file = fopen("./expenses.txt","r");

        menu();
        
        printf("Select An Option: ");
        scanf("%d", &user_input);

        switch (user_input)
        {
        case 1:
            getchar();

            float expense_number = 0;
            char label[100]; 

            printf("Please enter the label of the expense: ");
            fgets(label, 100, stdin);
            label[strcspn(label, "\n")] = 0;

            printf("Please enter the amount of the expense: ");
            scanf("%f", &expense_number);
            getchar();

            file = fopen("./expenses.txt", "a");

            fprintf(file, "%s,%f\n", label, expense_number);
            break;
        
        case 2:{
            int index = 0;
            float total = 0;
            char c;
            char number[1000];

            while ((c = fgetc(file)) != EOF)
            {
                if (isdigit(c) || c == '.')
                {
                    number[index] = c;
                    index++;
                }
                
                if (c == '\n')
                {
                    total += atof(number);
                    number[0] = '\0';
                    index = 0;
                }
            }

            if (index > 0) {
                number[index] = '\0';
                total += atof(number);
            }


            printf("\nTotal Amount Of Expenses Is: %f\n", total);
            break;
        }

        case 3: {
            char buff[100];
            int index = 1;

            printf("\n");
            while (fgets(buff, 100, file) != NULL)
            {
                printf("%d. %s\n", index, buff);
                index++;
            }

            break;
        }

        case 4:
            int free_memory_index = 0;
            program = 1;

            fclose(file);
            printf("\nGoodBye!\n");
            break;

        default:
            printf("Please input a valid option");
            break;
        }
    }
    
    return 0;
}

void menu(){
    printf("\n");
    printf("1. Add An Expense\n");
    printf("2. Calculate Total Spent\n");
    printf("3. View Expenses\n");
    printf("4. Exit\n");
    printf("\n");
}