// Write a function char *duplicate(const char *s) that returns a copy using malloc.
#include <stdio.h>
#include <stdlib.h>

char *duplicate(const char *s);

int main(){
    int index = 0;
    int total = 0;

    const char string[] = "hello";
    
    char *dup = duplicate(string);
    
    // while (*dup != '\0')
    // {
    //     printf("%c", *dup);
    //     *dup++;
    // }
    
    // free(dup);
    return 0;
}

char *duplicate(const char *s){
    int total = 0;
    int index = 0;
    const char *c = s;

    while (*c != '\0')
    {
        total += 1;
        *c++;    
    }

    char *new_string = malloc(total * sizeof(char) + 1);
    
    const char *new_c = s;

    while (*new_c != '\0')
    {
        *new_string = *new_c;
        new_c++;
        
        // if(*new_c == '\0'){
        //     *new_string = *new_c;
        // }
    }
    
    printf("%c 2.%c\n", *new_c, *new_string);
    return new_string;
}
