// Build a command-line BMI calculator.
#include <stdio.h>

int main(){
    float weight_kg;
    float height_m;

    printf("Enter weight (kg): ");
    scanf("%f", &weight_kg);
    printf("Enter height (m): ");
    scanf("%f", &height_m);

    float bmi = weight_kg / (height_m * height_m);


    if(bmi < 18.5){
        printf("Underweight");
    } else if(bmi >= 18.5 && bmi <= 24.9){
        printf("Normal Weight");
    } else if (bmi >= 18.5 && bmi <= 24.9)
    {
        printf("Normal Weight");
    } else if (bmi >= 25 && bmi <= 29.9)
    {
        printf("Overweight");
    } else if (bmi > 30)
    {
        printf("Obesity");
    } else
    {
        printf("Error!");
    }
}