// Your First Shell
// Build a super basic shell that:
    // Reads a command from the user
    // Forks a child process
    // Executes the command using execvp()



#include <stdio.h>
#include <unistd.h>

int main(){
    // Read command
    int fd = open("myfile.txt", O_RDONLY);

    char buffer[128];
    int bytes_read = read(fd, buffer, 128);
    write(STDOUT_FILENO, buffer, bytes_read);

}