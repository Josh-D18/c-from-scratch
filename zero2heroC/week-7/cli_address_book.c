// CLI Address Book 📖
// Build a program that:
    // Lets user add, view, delete contacts
    // Stores contacts in a dynamically allocated array
    // Uses a struct Contact with name, phone, email
    // Supports saving/loading to a file (we’ll go deep into files next week)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTBUFF 100

struct Contact{
    char name[INPUTBUFF];
    char phone[INPUTBUFF];
    char email[INPUTBUFF];
};

void menu();
void view_contacts_name(struct Contact **ContactList, int list_size);
void view_contacts_info(struct Contact **ContactList, int list_size);

int main(){
    printf("-----------Address Book-------------\n");
    int program = 0;
    int list_size = 0;
    FILE *file = NULL;
    struct Contact **ContactList = malloc(10 * sizeof(struct Contact*));

    while (program == 0)
    {
        printf("\n");

        menu();
        printf("\nSelect an option: ");
        
        int user_input = 0;
        scanf("%d", &user_input);
        getchar();


        switch (user_input)
        {
        case 1:
            struct Contact *contact = malloc(sizeof(struct Contact));
            char name[INPUTBUFF];
            char phone[INPUTBUFF];
            char email[INPUTBUFF];

            printf("Please enter a new name: ");
            fgets(name, INPUTBUFF, stdin);
            name[strcspn(name, "\n")] = 0;

            printf("Please enter a new phone number: ");
            fgets(phone, INPUTBUFF, stdin);
            phone[strcspn(phone, "\n")] = 0;

            printf("Please enter a new email: ");
            fgets(email, INPUTBUFF, stdin);
            email[strcspn(email, "\n")] = 0;

            strcpy(contact->name, name);
            strcpy(contact->phone, phone);
            strcpy(contact->email, email);

            ContactList[list_size] = contact;
            list_size++;

            file = fopen("./address_book.text", "w");
            if (file == NULL)
            {
                printf("\nCould not save to file!\n");
            } else {
                fprintf(file, name);
                fprintf(file, email);
                fprintf(file, phone);
            }

            file = fopen("./address_book.text", "r");
            char buffer[100];
            fgets(buffer, 100, file);

            printf("\nFile info %s\n", buffer);
            
            fclose(file);
            
            break;
        
        case 2:
            view_contacts_info(ContactList, list_size);
            break;

        case 3:
            printf("----Delete A Contact----\n");
            printf("Who do you want to delete?\n");

            int delete_index = 0;

            view_contacts_name(ContactList, list_size);

            printf("\nSelect A Contact To Delete: ");
            scanf("%d", &delete_index);
            getchar();

            if (list_size < delete_index || delete_index < 1)
            {
                printf("Error! You did not select a valid Contact\n");
            } else
            {
                free(ContactList[delete_index - 1]);

                for (int i = delete_index; i < list_size; i++) {
                    ContactList[i - 1] = ContactList[i];
                }

                list_size--;

                if (list_size == 0) {
                    free(ContactList);
                    ContactList = NULL;
                } else {
                    ContactList = realloc(ContactList, sizeof(struct Contact*) * list_size);
                }
            }
            break;
        
        case 4:
            // Edit
            printf("----Edit A Contact----\n");
            printf("Who do you want to edit?\n");
            char new_name[INPUTBUFF];
            char new_phone[INPUTBUFF];
            char new_email[INPUTBUFF];

            int edit_index = 0;

            view_contacts_name(ContactList, list_size);

            printf("\nSelect A Contact To Edit: ");
            scanf("%d", &edit_index);
            getchar();
            
            if (list_size < edit_index || edit_index < 1)
            {
                printf("Error! You did not select a valid Contact\n");
            } else
            {
                // Edit Contact
                int edit_contact_user_input = 0;

                printf("What do you want to edit about %s?\n", ContactList[edit_index - 1]->name);

                printf("1. Name\n");
                printf("2. Phone\n");
                printf("3. Email\n");
                
                scanf("%d", &edit_contact_user_input);

                while (edit_contact_user_input < 1 || edit_contact_user_input > 3)
                {
                    getchar();
                    printf("\nPlease enter a valid option!\n\n");
                    printf("1. Name\n");
                    printf("2. Phone\n");
                    printf("3. Email\n");
                    
                    scanf("%d", &edit_contact_user_input);
                }

                switch (edit_contact_user_input)
                {
                case 1:
                    printf("Enter in a new name: ");
                    fgets(new_name, INPUTBUFF, stdin);
                    new_name[strcspn(new_name, "\n")] = 0;
                    printf("\n");
                    strcpy(ContactList[edit_index - 1]->name, new_name);
                    printf("Contact Has Been Updated!\n\n");
                    break;
                
                case 2:
                    printf("Enter in a new phone number: ");
                    fgets(new_phone, INPUTBUFF, stdin);
                    new_phone[strcspn(new_phone, "\n")] = 0;
                    printf("\n");
                    strcpy(ContactList[edit_index - 1]->phone, new_phone);
                    printf("Contact Has Been Updated!\n\n");
                    break;

                
                case 3:
                    printf("Enter in a new email: ");
                    fgets(new_email, INPUTBUFF, stdin);
                    new_email[strcspn(new_email, "\n")] = 0;
                    printf("\n");
                    strcpy(ContactList[edit_index - 1]->email, new_email);
                    printf("Contact Has Been Updated!\n\n");
                    break;

                default:
                    printf("Please enter a valid option!\n\n");
                    break;
                }
                
            }
            break;

        case 5:
            program = 1;
            int exit_index = 0;

            while (exit_index < list_size)
            {
                free(ContactList[exit_index]);
                exit_index++;
            }
            free(ContactList);
            printf("Goodbye!");
            break;

        default:
            printf("Please enter a valid option!\n\n");
            break;
        }
    }
    return 0;
}




void view_contacts_name(struct Contact **ContactList, int list_size){
    int index = 0;

    if (list_size == 0)
    {
        printf("Contact List Is Empty!");
    } else
    {
        while (index < list_size)
        {
            printf("\n%d. Contact Name: %s", index + 1, ContactList[index]->name);
            index++;
        }
    }
}


void view_contacts_info(struct Contact **ContactList, int list_size){
    int index = 0;

    if (list_size == 0)
    {
        printf("Contact List Is Empty!\n");
    } else
    {
        while (index < list_size)
        {
            printf("\n");
            printf("%d. Contact Name: %s\n", index + 1, ContactList[index]->name);
            printf("%d. Contact Phone: %s\n", index + 1, ContactList[index]->phone);
            printf("%d. Contact Email: %s\n", index + 1, ContactList[index]->email);
            printf("============");
            printf("\n");
            index++;
        }
    }
    printf("\n");
}

void menu(){
    printf("1. Add\n");
    printf("2. View\n");
    printf("3. Delete\n");
    printf("4. Edit\n");
    printf("5. Exit\n");
};