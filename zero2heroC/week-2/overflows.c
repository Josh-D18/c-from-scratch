// Try assigning int x = 2147483647; and then add 1. What happens?
// -- A large negative number is returned. -2147483648
#include <stdio.h>
int main(){
    int x = 2147483647;
    x = x + 1;
    printf("%d", x);
    return 0;
}