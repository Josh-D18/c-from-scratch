// Read a file and count how many lines it has.

#include <stdio.h>

int main(){
    FILE *file = NULL;
    int counter = 0;

    file = fopen("./count.txt","r");

    if (file == NULL)
    {
        printf("Cannot open file!\n");
    } else
    {
        
        // while(feof(file) != 1){
        //     if (fgetc(file) == '\n')
        //     {
        //         counter++;
        //     }
            
        //     file++;
        // }

        printf("File has %d lines", counter);
        fclose(file);
    }
}