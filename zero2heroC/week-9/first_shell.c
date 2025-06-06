// Your First Shell
// Build a super basic shell that:
    // Reads a command from the user
    // Forks a child process
    // Executes the command using execvp()

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    while (1)
    {
        // Read command
        char buff[1000];
        char buff_two[1000];
        printf("$ ");
        fgets(buff, 1000, stdin);
        buff[strcspn(buff, "\n")] = '\0';
        strcpy(buff_two, buff);

        int index = 0;
        char *ptrToArgs = strtok(buff, " ");

        while (ptrToArgs != NULL)
        {
            ptrToArgs = strtok(NULL, " ");
            index++;
        }

        char *ptrToArgsTwo = strtok(buff_two, " ");

        char **args = malloc(((index + 1) * sizeof(char *)));
        index = 0;

        while (ptrToArgsTwo != NULL)
        {
            args[index] = ptrToArgsTwo;
            index++;
            ptrToArgsTwo = strtok(NULL, " ");
        }
        
        args[index] = NULL;
        
        if (strcmp(args[0], "exit") == 0)
        {
            return 0;            
        }
        // Fork a child process
        pid_t pid = fork();

        if (pid < 0)
        {
            printf("Forking failed!\n");
            exit(1);
        } else if (pid == 0)
        {
            // Execute command
            printf("Child has spawned!\n");

            if(args[0] == NULL){
                printf("Nothing was entered!\n");
            } else
            {
                if (execvp(args[0], args) == -1)
                {
                    perror("Error execvp has failed!\n");
                    exit(0);
                }
            }
        } else {
            wait(NULL);
            printf("Returned to the parent\n");
        }

        free(args);
    }
}