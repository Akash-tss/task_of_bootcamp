cmake_minimum_required(VERSION 3.10)

# Define the project as a C-only project
project(MyProject VERSION 1.0 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Optionally, you can add a configuration option to choose between static and shared libraries
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Add the library
add_library(mylib src/mylib.c)

# Specify the include directory
target_include_directories(mylib PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Add the executable
add_executable(main src/main.c)

# Link the executable to the library
target_link_libraries(main PRIVATE mylib)
