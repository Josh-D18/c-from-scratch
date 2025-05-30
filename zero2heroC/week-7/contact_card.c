// Contact Card
    // Build a struct Contact with name, phone, and email. Store multiple in an array.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact{
    char name[50];
    char phone[20];
    char email[60];
};

int main(){
    
    struct Contact **contact_array = malloc(5 * sizeof(struct Contact*));
    
    struct Contact *contact = malloc(sizeof(struct Contact));
    struct Contact *contact_two = malloc(sizeof(struct Contact));
    struct Contact *contact_three = malloc(sizeof(struct Contact));
    struct Contact *contact_four = malloc(sizeof(struct Contact));
    struct Contact *contact_five = malloc(sizeof(struct Contact));

    int index = 0;

    strcpy(contact->name , "Larry");
    strcpy(contact->email , "test@gmail.com");
    strcpy(contact->phone , "289-233-3589");

    
    strcpy(contact_two->name , "Bob");
    strcpy(contact_two->email , "test2@gmail.com");
    strcpy(contact_two->phone , "416-233-1111");

    
    strcpy(contact_three->name , "Pop");
    strcpy(contact_three->email , "test3@gmail.com");
    strcpy(contact_three->phone , "289-234-3552");

    
    strcpy(contact_four->name , "Carly");
    strcpy(contact_four->email , "test4@gmail.com");
    strcpy(contact_four->phone , "259-293-7589");

    
    strcpy(contact_five->name , "Bard");
    strcpy(contact_five->email , "test5@gmail.com");
    strcpy(contact_five->phone , "289-213-1589");

    contact_array[0] = contact;
    contact_array[1] = contact_two;
    contact_array[2] = contact_three;
    contact_array[3] = contact_four;
    contact_array[4] = contact_five;
    
    while (index < 5)
    {
        printf("Contact Name: %s, Contact Email: %s, Contact Phone: %s\n", contact_array[index]->name, contact_array[index]->email, contact_array[index]->phone);
        free(contact_array[index]);
        index++;
    }

    free(contact_array);
    return 0;
}