// FizzBuzz (Classic Dev Test)
// Print numbers 1–100, but:
// If divisible by 3 → print “Fizz”
// If divisible by 5 → “Buzz”
// If both → “FizzBuzz”
#include <stdio.h>

int main(){
    int count = 100;
    for (size_t i = 1; i < count; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBuzz\n");
        } 
        
        if (i % 5 == 0)
        {
            printf("Buzz\n");
        } 
        
        if (i % 3 == 0)
        {
            printf("Fizz\n");
        }
    }
}