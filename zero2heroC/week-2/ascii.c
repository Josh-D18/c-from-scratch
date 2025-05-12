#include <stdio.h>
// ASCII explorer
// Loop from char c = 32; c < 127; c++ and print each char + ASCII code.
int main(){
    for(char c = 32; c < 127; c++){
        printf("%c\n",c);
    }
    return 0;
}