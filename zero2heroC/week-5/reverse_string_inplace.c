// Use char * logic to reverse a C string (char str[]) without allocating new memory.
#include <stdio.h>

void reverse(char *str, int len);
void swap(char *a, char *b);

int main(){
    char str[6] = {'h','e','l','l','o', '\0'};
    reverse(str, 6);
}


void reverse(char *str, int len){
    int start = 0;
    int end = len - 2;
    

    while (start < end) {
        swap(str + start, str + end);
        start++;
        end--;
    }
    
    printf("%s", str);
}

void swap(char *a, char *b){
    char c = *a;
    *a = *b;
    *b = c;
}
