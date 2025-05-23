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
    char  label[20];
};

struct BudgetTracker
{
    struct Expenses expenses;
    float total;
};

void menu();

int main(){
    int expense_tracker_amount = 0;
    int program = 0;

    printf("-------------Budget Tracker-----------\n");
    struct Expense **BudgetTracker = malloc(5 * sizeof(struct BudgetTracker*));


    while (program == 0)
    {
        int user_input = 0;
        menu();
        
        printf("Select An Option: ");
        scanf("%d", &user_input);


        switch (user_input)
        {
        case 1:
            float expense_number = 0;
            char label[20]; 
            struct Expenses expense;

            printf("Please enter the label of the expense: ");
            fgets(label, 20, stdin);
            getchar();

            printf("Please enter the label of the expense: ");
            scanf("%f", &expense_number);
            getchar();

            expense.amount = expense_number;
            expense.label = label;
            
            struct Expenses *expense_mem = malloc(sizeof(struct Expenses));
            expense_mem = &expense;

            BudgetTracker[expense_tracker_amount] = expense_mem;
            break;
        
        case 2:
            /* code */
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}

void menu(){
    printf("1. Add An Expense\n");
    printf("2. Calculate Total Spent\n");
    printf("3. Exit\n");
}