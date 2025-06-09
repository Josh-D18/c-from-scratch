// SysCall Task Manager
    // Build a CLI program that:
        // Lists running processes using system("ps") or parse /proc
        // Lets the user kill a process by PID using kill(pid, SIGTERM)
        // Use fork() to run background jobs (like sleep or ping)
    // Bonus:
        // Add “record a log of child exit statuses”
        // Implement a simple scheduler that limits concurrent children

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main(){

    while (1)
    {
        
        int user_input = 0;
        printf("\n");
        printf("1. Kill a process\n");
        printf("2. Sleep\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &user_input);
        getchar();

        switch (user_input)
        {
        case 1:
            int processes = system("ps");
            char kill_process_input[100];

            if (processes == 0)
            {

                printf("Select a process to kill: ");
                fgets(kill_process_input, 100, stdin);
                kill_process_input[strcspn(kill_process_input, "\n")] = '\0';
                pid_t pid_number = strtoul(kill_process_input, NULL, 10);
                int kill_process = kill(pid_number, SIGTERM);

                if (kill_process == -1) {
                    perror("Kill failed");
                } else if (kill_process == 0)
                {
                    printf("Process Has Been Killed!\n");
                } else
                {
                    printf("Error!\n");
                }
            } else
            {
                printf("Could not list processes! Try again later!\n");
            }
            break;
        
        case 2:{
            pid_t pid = fork();
            if (pid == -1)
            {
                perror("Error creating new process!\n\n");
            } else if (pid == 0)
            {
                printf("Before sleep...\n");
                sleep(10);
                printf("After sleep...\n");
                exit(0);
            }else 
            {
                wait(NULL);
            }
            break;
        }

        case 3:
            printf("Goodbye!");
            exit(0);
            break;

        default:
            printf("Please enter a valid option!\n\n");
            break;
        }
    }
}