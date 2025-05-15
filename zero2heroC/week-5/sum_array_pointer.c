// Write int sum(int *arr, int len) that sums the elements of an array via pointer iteration.
#include <stdio.h>
int sum(int *arr, int len);

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int result = sum(arr, 5);

    printf("Sum of array: %d", result);
}


int sum(int *arr, int len){
    int result = 0;
    int index = 0;
    
    while (index < len)
    {
        result = result + *(arr + index);
        index += 1;
    }
    return result;
}