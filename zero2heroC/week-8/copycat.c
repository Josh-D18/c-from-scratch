// Make a CLI tool that copies one text file to another.

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = NULL;
    FILE *copy_file = NULL;

    file = fopen("./count.txt", "r");

    if (file == NULL)
    {
        printf("Could not open file!");
        return 1;
    } 
    char c;

    copy_file = fopen("./copy_count.txt", "w");

    if (copy_file == NULL)
    {
        printf("Could not open second file!\n");
        fclose(file);
        return 1;
    } 
    while((c = fgetc(file)) != EOF)
    { 
        fputc(c, copy_file);
    }

    fclose(copy_file);
    fclose(file);
}