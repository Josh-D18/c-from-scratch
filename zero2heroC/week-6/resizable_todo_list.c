// Resizable To-Do List
// Let the user enter tasks one by one. Start with space for 5 tasks, use realloc() when they add more.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char **string_array = malloc(5 * sizeof(char*));
    int program = 0;
    int task_counter = 0;
    int user_input = 0;
    int capacity = 0;

    while (program == 0){
        printf("\nPlease select an option ");
        printf("\n1. Add a task\n");
        printf("2. Exit \n");
        scanf("%d", &user_input);

        if (task_counter >= 5)
        {
            char **new_string_array = realloc(string_array, (task_counter + 2) * sizeof(char*));
            if (new_string_array == NULL)
            {
                printf("Could not reallocate array!\n");
            } else {
                string_array = new_string_array;
            }
        }
        

        switch (user_input)
        {
        case 1:

            if (task_counter == 0)
            {
                printf("The list is currently empty!\n");
            } else
            {
                printf("---Current Task List---\n");
                for (int i = 0; i < task_counter; i++)
                {
                    printf("%d. %s\n", i + 1, string_array[i]);
                }    
            }
            
            getchar();

            char task[100];
            printf("Enter a task: ");
            fgets(task, 100, stdin);

            char *input = malloc(strlen(task) + 1);
            strcpy(input, task);
            string_array[task_counter] = input;
            printf("%s was added to the list\n", task);

            task_counter++;
            break;

        case 2:
            program = 1;
            for (int i = 0; i < task_counter; i++)
            {
                free(string_array[i]);
            }   
            free(string_array);
            printf("Goodbye!\n");
            break;

        default:
            printf("Please enter a valid input!\n");
            break;
        }
    }
}