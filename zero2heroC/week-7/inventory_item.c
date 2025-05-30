// Inventory Item
// Track stock of items with name, sku, quantity, price. Write a function that updates quantity.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Inventory
{
    char name[50];
    int sku;
    int quantity;
    float price;
};

void updateQuantity(struct Inventory *inventory);

int main(){
    struct Inventory *inventory = malloc(sizeof(struct Inventory));

    printf("-------Current Inventory------\n");

    strcpy(inventory->name, "Wrench");
    inventory->sku = 1001432132;
    inventory->price = 29.99;
    inventory->quantity = 5;

    printf("\nInventory Before\n");

    printf("Inventory Sku: %d\n", inventory->sku);
    printf("Inventory Name: %s\n", inventory->name);
    printf("Inventory Price: %f\n", inventory->price);
    printf("Inventory Quantity: %d\n", inventory->quantity);

    updateQuantity(inventory);

    printf("\nInventory After\n");

    printf("Inventory Sku: %d\n", inventory->sku);
    printf("Inventory Name: %s\n", inventory->name);
    printf("Inventory Price: %f\n", inventory->price);
    printf("Inventory Quantity: %d\n", inventory->quantity);
}

void updateQuantity(struct Inventory *inventory){
    int new_quantity = 0;
    printf("\nEnter a new quantity: ");
    scanf("%d", &new_quantity);
    inventory->quantity = new_quantity;
}