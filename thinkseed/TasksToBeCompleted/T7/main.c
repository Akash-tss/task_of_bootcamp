#include <stdio.h>
#include "mylib.h"

int main() {
    int choice;
    int num1, num2;
    double result;
    int condn = 1; // This will control the while loop

    while (condn) {
        // Display menu
        printf("Select an option:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");

        // Get user's choice
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        // Check if the user wants to exit
        if (choice == 5) {
            condn = 0;
            printf("Exiting...\n");
            continue;
        }

        // For other options, get two numbers from the user
        printf("Enter two numbers: ");
        if (scanf("%d %d", &num1, &num2) != 2) {
            printf("Invalid input. Please enter two integers.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        // Perform the selected operation
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %d\n", (int)result);
                break;
            case 2:
                result = sub(num1, num2);
                printf("Result: %d\n", (int)result);
                break;
            case 3:
                result = multi(num1, num2);
                printf("Result: %d\n", (int)result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f\n", result);
                }
                break;
            default:
                printf("Invalid choice. Please select a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}
