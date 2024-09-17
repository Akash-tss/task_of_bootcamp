#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mylib.h"

int main() {
    void *handle;
    int (*add)(int, int);
    int (*sub)(int, int);
    int (*multi)(int, int);
    double (*divide)(double, double);
    int choice;
    int num1, num2;
    double result;
    int condn = 1; // This will control the while loop

    // Load the shared library at runtime
    handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    // Reset errors
    dlerror();

    // Get function pointers from the shared library
    add = (int (*)(int, int))dlsym(handle, "add");
    sub = (int (*)(int, int))dlsym(handle, "sub");
    multi = (int (*)(int, int))dlsym(handle, "multi");
    divide = (double (*)(double, double))dlsym(handle, "divide");

    // Check for any errors
    char *error;
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error finding symbols: %s\n", error);
        dlclose(handle);
        exit(EXIT_FAILURE);
    }

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

    // Close the shared library
    dlclose(handle);
    return 0;
}
