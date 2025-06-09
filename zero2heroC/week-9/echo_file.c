// Echo File (System Style)
    // Open a file with open(), read contents, write to stdout using write().
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> 

int main (){
    int fd = open("./echo_file.txt", O_RDONLY);
    
    if (fd == -1)
    {
        perror("Read failed\n");
        return 1;
    } else
    {
        printf("\t-------File Opened-------\n");
        printf("\t-------Contents------- \n\n");
        
        char buffer[1000];
        int filebytes = read(fd, buffer, 1000);
        write(STDOUT_FILENO, buffer, filebytes);

    } 
    
    close(fd);
    return 0;
}