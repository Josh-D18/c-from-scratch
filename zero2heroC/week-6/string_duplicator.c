// Write a function char *duplicate(const char *s) that returns a copy using malloc.
#include <stdio.h>
#include <stdlib.h>

char *duplicate(const char *s);

int main(){
    const char string[] = "hello";
    
    char *dup = duplicate(string);
    
    printf("%s", dup);
    
    free(dup);
    return 0;
}

char *duplicate(const char *s){
    int total = 0;
    int index = 0;
    const char *c = s;

    while (*c != '\0')
    {
        total += 1;
        c++;    
    }

    char *new_string = malloc(total * sizeof(char) + 1);
    
    const char *new_c = s;

    while (index <= total)
    {
        *(new_string + index) = *(new_c + index);
        index++;
    }
    
    return new_string;
}
