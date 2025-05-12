#include <stdio.h>
#include <stdbool.h>

void menu();

int main(){
    int balance = 1000;
    int user_input = 0;
    bool bank_sim = true;

    while (bank_sim)
    {
        menu();
        printf("Select an option: ");
        scanf("%d", &user_input);

        switch (user_input)
        {
        case 1:
            printf("You have a balance of: $%d", balance);
            break;
        
        case 2:
            int deposited_money = 0;
            printf("How much would you like to deposit: ");
            scanf("%d", &deposited_money);
            if (deposited_money < 1)
            {
                printf("Please enter a valid amount to deposit!");
            } else {
                balance = balance + deposited_money;
                printf("You have deposited $%d", deposited_money);
            }
            break;

        case 3:
            int withdrawn_money = 0;
            printf("How much would you like to deposit: ");
            scanf("%d", &withdrawn_money);
            if (withdrawn_money > balance)
            {
                printf("You do not have enough to withdraw!");
            } else
            {
                balance = balance - withdrawn_money;
                printf("You have deposited $%d dollars", withdrawn_money);
            }
            break;

        case 4:
            printf("Thank you for banking with us!");
            bank_sim = false;
            break;
        
        default:
            bank_sim = false;
            printf("Good Bye!\n");
            break;
        }
    }

    return 0;
}


void menu(){
    printf("\n");

    printf("1. Check Balance \n");
    printf("2. Deposit \n");
    printf("3. Withdraw \n");
    printf("4. Exit \n");

    printf("\n");
}