// Function Split
// Create a program with 3+ helper functions: input handler, logic calculator, result printer.
#include <stdio.h>

int input_handler();
void result_printer(int input);
int logic_calculator(int number);


int main(){
    int input = input_handler();
    int logic = logic_calculator(input);


    result_printer(logic);
    return 0;
}


int input_handler(){
    int user_input = 0;

    printf("Enter a number and wait for the magic: ");
    scanf("%d", &user_input);

    if (user_input < 1)
    {
        printf("Hey please enter a valid positive number!");
        return 1;
    };
    
    return user_input;
}

void result_printer(int input){
    printf("Lol we added 7 to your number: %d", input);
}

int logic_calculator(int number){
    return number + 7;
}

