// Conversion chart
// Print a table converting Celsius to Fahrenheit using floats.
#include <stdio.h>
#include <math.h>

int main(){
    printf("Fahrenheit   ");
    printf("Celsius      ");

    for(int c = 0; c < 100; c++){
        printf("%d   ", c);
        printf("%.2f    \n", (c * 1.8) + 32);
    }
}