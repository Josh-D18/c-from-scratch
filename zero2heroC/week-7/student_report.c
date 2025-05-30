// Student Report
// Define a student with grades, ID, and name. Write a function that calculates GPA from their grades.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GRADES 10

struct Student
{
    int grades[10];
    int id;
    char name[60];
};

float calculate_gpa(int grades[]);


int main(){
    srand(time(NULL));

    struct Student student;
    int index = 0;

    student.id = 1001890123;
    strcpy(student.name,"John");
    
    while (index < NUM_GRADES)
    {
        student.grades[index] = rand() % 100;
        index++;
    }

    printf("Student GPA Is: %.2f", calculate_gpa(student.grades));
}

float calculate_gpa(int grades[]){
    int index = 0;
    float total = 0;

    while (index < NUM_GRADES)
    {
        if (grades[index] >= 86)
        {
            total += 4.0;
        } else if (grades[index] >= 81)
        {
            total += 3.7;
        } else if (grades[index] >= 70)
        {
            total += 3.3;
        } else if (grades[index] >= 61)
        {
            total += 2.3;
        
        } else if (grades[index] >= 51)
        {
            total += 1.3;
        } else
        {
            total += 0.5;
        }
        
        index++;  
    }

    total = total / 10;
    return total;
}