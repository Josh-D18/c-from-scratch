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

    printf("-------------Budget Tracker-----------\n");
    struct Expenses **Budget = malloc(5 * sizeof(struct Expenses*));


    while (program == 0)
    {
        int user_input = 0;
        int array_amount = 0;
        
        menu();
        
        printf("Select An Option: ");
        scanf("%d", &user_input);

        if (expense_tracker_amount >= expense_quantity_tracker)
        {
            expense_quantity_tracker *= 2;
            Budget = realloc(Budget, expense_quantity_tracker * sizeof(struct Expenses*));
        }

        switch (user_input)
        {
        case 1:
            getchar();

            float expense_number = 0;
            char label[100]; 
            struct Expenses *expense_mem = malloc(sizeof(struct Expenses));

            printf("Please enter the label of the expense: ");
            fgets(label, 100, stdin);
            label[strcspn(label, "\n")] = 0;

            printf("Please enter the amount of the expense: ");
            scanf("%f", &expense_number);
            getchar();


            expense_mem->amount = expense_number;
            strcpy(expense_mem->label, label);

            Budget[expense_tracker_amount] = expense_mem;
            expense_tracker_amount++;

            break;
        
        case 2:{
            int budget_index = 0;
            float total = 0;

            while(budget_index < expense_tracker_amount){
                total = total + Budget[budget_index]->amount;
                budget_index++;
            }

            printf("\nTotal Amount Of Expenses Is: %f\n", total);
            break;
        }
        case 3: {
            int index = 0;

            while(index < expense_tracker_amount){
                printf("\nLabel: %s Amount: %f\n", Budget[index]->label, Budget[index]->amount);
                index++;
            }

            break;
        }
        case 4:
            int free_memory_index = 0;
            program = 1;
            if (Budget != NULL)
            {
                while(free_memory_index < expense_tracker_amount)
                {
                    free(Budget[free_memory_index]);
                    free_memory_index++;
                }

                free(Budget);
            }
    
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