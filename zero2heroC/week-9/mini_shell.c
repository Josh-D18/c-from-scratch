// Mini Shell
    // Loop: read command, fork, exec. Handle “exit” to break

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){

    while (1)
    {
        char user_input[100];
        printf("mini_shell: ");
        int index = 0;
        fgets(user_input, 100, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        char *ptrToArgs = strtok(user_input, " ");
        char **args = NULL;

        while (ptrToArgs != NULL)
        {
            args = realloc(args, (2 + index) * sizeof(char *));
            args[index] = ptrToArgs;
            index++;
            ptrToArgs = strtok(NULL, " ");
        }
        args[index] = NULL;

        if (args[0] == NULL) continue;

        if (strcmp(args[0], "exit") == 0)
        {
            printf("Goodbye!");
            exit(0);
        }

        pid_t pid = fork();

        if (pid == -1)
        {
            perror("Failed to create fork!\n");
            free(args);
            exit(1);
        } else if (pid == 0)
        {
            if (execvp(args[0], args) == -1)
            {
                perror("Error execvp has failed!\n");
                free(args);
                exit(1);
            }
        } else
        {
            wait(NULL);
        }
        free(args);
    }
}