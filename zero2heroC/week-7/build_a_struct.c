// Build-a-Struct Workshop
// Make and test:
    // struct Book { char title[100]; int pages; float price; }
    // Print fields using dot . and arrow ->
    // Pass to a function that prints its info
    // Try passing by value vs by pointer — spot the difference

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    char title[100];
    int pages;
    float price;
};


int main(){

    struct Book book;
    struct Book *book_two = malloc(sizeof(struct Book));

    book.pages = 10;
    book.price = 12.99;
    strcpy(book.title , "The New Book");

    book_two->pages = 6;
    book_two->price = 12.99;
    strcpy(book_two->title, "The Second New Book");

    printf("Book One - Price: %f, Pages: %d, Title: %s \n", book.price, book.pages, book.title);
    printf("Book Two - Price: %f, Pages: %d, Title: %s \n", book_two->price, book_two->pages, book_two->title);

    return 0;
}

