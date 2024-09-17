#!/bin/bash

# Check if a library type argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 {static|shared}"
    exit 1
fi

LIB_TYPE=$1
SRC_FILES="*.c"  # Change this to your actual C source files
OUTPUT="mylibrary"

# Create static library
if [ "$LIB_TYPE" == "static" ]; then
    echo "Building static library..."
    gcc -c $SRC_FILES               # Compile source files into object files
    ar rcs lib$OUTPUT.a *.o         # Create static library
    gcc -o myapp main.c -L. -l$OUTPUT   # Link the application with the static library

# Create shared library
elif [ "$LIB_TYPE" == "shared" ]; then
    echo "Building shared library..."
    gcc -fPIC -c $SRC_FILES         # Compile source files as position-independent code (for shared libs)
    gcc -shared -o lib$OUTPUT.so *.o # Create shared library
    gcc -o myapp main.c -L. -l$OUTPUT   # Link the application with the shared library

# Handle invalid input
else
    echo "Invalid argument: $LIB_TYPE"
    echo "Usage: $0 {static|shared}"
    exit 1
fi

# Clean up object files after compilation
rm -f *.o

echo "Build complete."