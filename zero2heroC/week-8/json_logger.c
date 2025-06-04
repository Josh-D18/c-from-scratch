// Save a log of structs in a pseudo-JSON format
// {"event":"login", "timestamp":1689012345}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Actions
{
    int timestamp; // Using a random number. Not actual time;
    char action_type[100];
};

void menu();
void log_action(FILE *file, const char *action_type, int timestamp);

int main(){
    FILE *file = NULL;
    int program = 0;
    int upper_bound = 10000;
    int lower_bound = 500;

    srand(time(NULL));


    while (program == 0)
    {
        int user_input = 0;
        int random_num = rand() % (upper_bound - lower_bound + 1)
    + lower_bound;
        menu();

        printf("Please select an option: ");
        scanf("%d", &user_input);
        getchar();

        file = fopen("./logger.txt", "ab+");
        
        switch (user_input)
        {
        case 1:
            printf("Merging......\n");
            log_action(file, "Merge", random_num);
            printf("Done!\n\n");
            fclose(file);          
            break;
        
        case 2:
            printf("Splitting......\n");
            log_action(file, "Split", random_num);
            printf("Done!\n\n"); 
            fclose(file);
            break;

        case 3:
            printf("Saving......\n");
            log_action(file, "Save", random_num);
            printf("Done!\n\n"); 
            fclose(file);
            break;

        case 4:
            printf("Deleting......\n");
            log_action(file, "Delete", random_num);
            printf("Done!\n\n"); 
            fclose(file);
            break;
        
        case 5:
            fclose(file);
            program = 1;
            printf("Goodbye!!!");
            break;
        
        default:
            printf("Please enter a valid option!\n");
            break;
        }
    }
    
}

void menu(){
    printf("\n");
    printf("1. Merge\n");
    printf("2. Split\n");
    printf("3. Save\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
    printf("\n");
}

void log_action(FILE *file, const char *action_type, int timestamp){
    struct Actions action;
    strcpy(action.action_type, action_type);
    action.timestamp = timestamp;
    fprintf(file, "{\"event\": \"%s\", \"timestamp\": %d}\n", action.action_type, action.timestamp);
}