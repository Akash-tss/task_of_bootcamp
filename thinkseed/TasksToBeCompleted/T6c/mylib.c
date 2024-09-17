#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mylib.h"

static void *handle = NULL;
static int (*add_func)(int, int) = NULL;
static int (*sub_func)(int, int) = NULL;
static int (*multi_func)(int, int) = NULL;
static float (*divide_func)(float, float) = NULL;

void loadLibrary() {
    if (handle) {
        printf("Library already loaded.\n");
        return;
    }

    handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    add_func = (int (*)(int, int))dlsym(handle, "add");
    sub_func = (int (*)(int, int))dlsym(handle, "sub");
    multi_func = (int (*)(int, int))dlsym(handle, "multi");
    divide_func = (float (*)(float, float))dlsym(handle, "divide");

    char *error;
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error finding symbols: %s\n", error);
        dlclose(handle);
        handle = NULL;
        exit(EXIT_FAILURE);
    }
}

void unloadLibrary() {
    if (handle) {
        dlclose(handle);
        handle = NULL;
        add_func = NULL;
        sub_func = NULL;
        multi_func = NULL;
        divide_func = NULL;
        printf("Library unloaded.\n");
    }
}

// Functions to forward the calls to the dynamically loaded library
int add(int a, int b) {
    if (add_func) return add_func(a, b);
    fprintf(stderr, "Library not loaded.\n");
    exit(EXIT_FAILURE);
}

int sub(int a, int b) {
    if (sub_func) return sub_func(a, b);
    fprintf(stderr, "Library not loaded.\n");
    exit(EXIT_FAILURE);
}

int multi(int a, int b) {
    if (multi_func) return multi_func(a, b);
    fprintf(stderr, "Library not loaded.\n");
    exit(EXIT_FAILURE);
}

float divide(float a, float b) {
    if (divide_func) return divide_func(a, b);
    fprintf(stderr, "Library not loaded.\n");
    exit(EXIT_FAILURE);
}
