# F.Y.-EEL-6
1. Research
This section describes the problem the program addresses and the rationale behind its design.
Objective: The program is created to handle a list of products for scenarios like inventory or retail management.
Sorting Criteria: Products are sorted primarily by price (in descending order). If two products have the same price, they are sorted by ID (in ascending order).
Key Operations: Sorting, input validation, and output formatting.
Relevance: Sorting products by value can help prioritize higher-priced items for marketing, restocking, or analysis.

2. Analysis
This section analyzes the structure and functionality of the program.
Data Representation:The program uses a Product structure containing three fields:
•	id: An integer representing the product's unique identifier.
•	price: A floating-point value for the product price.
•	name: A string storing the product name.
o	Sorting Logic:The program uses a bubble sort algorithm to compare and swap products based on the sorting 
o	criteria:Descending price order.
3. Ideate

This section highlights the planning and key design choices for the program:
•	Struct Design: Encapsulation of product details in a struct to manage data efficiently.

•	Modularity: Functions (sortProducts and displayProducts) make the program modular and easy to maintain.

•	Error Handling: Ensures invalid inputs (e.g., negative prices or non-integer IDs) are handled gracefully.

4. Build
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

5. Test

6. Implementation

This section summarizes the implementation and its effectiveness:

Success:
The program meets the requirements by sorting and displaying products accurately.

Modular Design:
Functions like sortProducts and displayProducts simplify enhancements and debugging.

User Experience:
Clear prompts and error messages make the program user-friendly.

Scalability:
The program can be easily modified to add more features, such as saving the output to a file or integrating with a database.





The document concludes that the program is functional, robust, and ready for real-world applications in product management. It also provides the complete code for reference, with proper formatting for clarity.


