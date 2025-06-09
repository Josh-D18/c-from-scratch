// Process Tree
    // Fork twice and print which process you are (parent, child, grandchild).

    #include <stdio.h>
    #include <unistd.h>
    #include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if (pid == -1)
    {
        printf("Failed to open a new process!");
    } else if (pid == 0)
    {
        printf("I am the child!\n");
        pid_t pid_child = fork();

        if (pid_child == -1)
        {
            printf("Failed to open new child process!\n");
        } else if (pid_child == 0)
        {
            printf("I am the grandchild\n");
        } else if (pid_child > 0)
        {
            printf("I am still the child (now parent to the grandchild)\n");
            wait(NULL);
        } else
        {
            printf("Error!\n");
        }
    } else if (pid > 0)
    {
        printf("I am the grandparent!\n");
        wait(NULL);
    } else
    {
        printf("Error!\n");
    }
    
    return 0;
}