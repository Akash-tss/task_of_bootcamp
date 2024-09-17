#include <stdio.h>
#include "mylib.h"

int main() {
    int choice;
    int num1, num2;
    float result;
    int condn = 1; // This will control the while loop

    while (condn) {
        // Display menu
        printf("Select an option:\n");
        printf("1. Load Library\n");
        printf("2. Add\n");
        printf("3. Subtract\n");
        printf("4. Multiply\n");
        printf("5. Divide\n");
        printf("6. Unload Library\n");
        printf("7. Exit\n");

        // Get user's choice
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        // Check if the user wants to exit
        if (choice == 7) {
            condn = 0;
            printf("Exiting...\n");
            continue;
        }

        // Check if the user wants to load the library
        if (choice == 1) {
            loadLibrary();
            continue;
        }

        // Check if the user wants to unload the library
        if (choice == 6) {
            unloadLibrary();
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
            case 2:
                result = add(num1, num2);
                printf("Result: %d\n", (int)result);
                break;
            case 3:
                result = sub(num1, num2);
                printf("Result: %d\n", (int)result);
                break;
            case 4:
                result = multi(num1, num2);
                printf("Result: %d\n", (int)result);
                break;
            case 5:
                if (num2 == 0) {
                    printf("Error: Division by zero.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f\n", result);
                }
                break;
            default:
                printf("Invalid choice. Please select a number between 1 and 7.\n");
                break;
        }
    }

    // Ensure the library is unloaded before exiting
    unloadLibrary();

    return 0;
}
