#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100
typedef struct {
    int id;           
    float price;      
    char name[50];    
} Product;
void sortProducts(Product products[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (products[j].price < products[j + 1].price ||
                (products[j].price == products[j + 1].price && products[j].id > products[j + 1].id)) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}
void displayProducts(const Product products[], int n) {
    printf("\nProduct Details (Sorted by Price in Descending Order):\n");
    printf("ID\tName\t\t\tPrice\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-20s$%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts;
    int validInput = 0;
    while (!validInput) {
        printf("Enter the number of products (max %d): ", MAX_PRODUCTS);
        if (scanf("%d", &numProducts) != 1 || numProducts <= 0 || numProducts > MAX_PRODUCTS) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_PRODUCTS);
            while (getchar() != '\n'); 
        } else {
            validInput = 1;
        }
    }
     for (int i = 0; i < numProducts; i++) {
        printf("\nEnter details for product %d:\n", i + 1);
        validInput = 0;
        while (!validInput) {
            printf("ID: ");
            if (scanf("%d", &products[i].id) != 1) {
                printf("Invalid ID. Please enter an integer value.\n");
                while (getchar() != '\n'); 
            } else {
                validInput = 1;
            }
        }
         printf("Name: ");
        scanf(" %[^\n]s", products[i].name); 
        validInput = 0;
        while (!validInput) {
            printf("Price: $");
            if (scanf("%f", &products[i].price) != 1 || products[i].price < 0) {
                printf("Invalid price. Please enter a positive numeric value.\n");
                while (getchar() != '\n'); 
            } else {
                validInput = 1;
            }
        }
    }
    sortProducts(products, numProducts);
    displayProducts(products, numProducts);

    return 0;
}