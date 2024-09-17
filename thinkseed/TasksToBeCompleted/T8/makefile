C = gcc                # Change to gcc for C
CFLAGS = -Wall          # Keep the same flags for warnings
LIB = mylibrary

static: mylib.c mylib.h main.c
	$(CC) -c mylib.c $(CFLAGS)        # Compile mylib.c
	ar rcs lib$(LIB).a mylib.o        # Create static library
	$(CC) -o myapp main.c -L. -l$(LIB)  # Link and create executable

shared: mylib.c mylib.h main.c
	$(CC) -fPIC -c mylib.c $(CFLAGS)  # Compile position-independent code for shared library
	$(CC) -shared -o lib$(LIB).so mylib.o  # Create shared library
	$(CC) -o myapp main.c -L. -l$(LIB)    # Link and create executable

clean:
	rm -f *.o lib$(LIB).a lib$(LIB).so myapp  # Clean all build files
