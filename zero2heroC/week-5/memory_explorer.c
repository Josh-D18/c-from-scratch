// 🧪 Playground Lab: Memory Explorer
// Build a program that:
    // Declares an int, a char, and a float
    // Creates pointers to each
    // Prints the value, address, and size using sizeof and printf
#include <stdio.h>
int main(){
    int num = 10;
    char ltr = 'a';
    float fnum = 5.0;

    int *pnum = &num;
    char *pltr = &ltr;
    float *pfloat = &fnum;

    printf("Integer Value: %d, Integer Address: %p, Integer Size: %lu\n", *pnum, &pnum, sizeof(*pnum));
    printf("Character Value: %c, Character Address: %p, Character Size: %lu\n", *pltr, &pltr, sizeof(*pltr));
    printf("Float Value: %f, Float Address: %p, Float Size: %lu\n", *pfloat, &pfloat, sizeof(*pfloat));
}