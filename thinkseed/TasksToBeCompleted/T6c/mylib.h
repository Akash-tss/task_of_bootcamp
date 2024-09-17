#ifndef MYLIB_H
#define MYLIB_H

#include "mylib.h"

// Function prototypes for the library
int add(int a, int b);
int sub(int a, int b);
int multi(int a, int b);
float divide(float a, float b);

// Functions to dynamically load/unload the library
void loadLibrary();
void unloadLibrary();

#endif
