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
        char c;
        while((c = fgetc(file)) != EOF)
        { 
            if (c == '\n')
            {
                counter++;
            }
        }
        printf("\nFile has %d lines\n", counter);
        fclose(file);
    }
}