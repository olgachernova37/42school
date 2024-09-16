#!/bin/bash

# Define the name of the library
LIBRARY_NAME="libft.a"

# List of source files to compile
SRC_FILES="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"

# Compile each source file into an object file (.o)
cc -Wall -Wextra -Werror -c $SRC_FILES

# Create the static library from the object files
ar rcs $LIBRARY_NAME *.o

# Clean up the object files after creating the library
rm -f *.o

# Notify the user
# echo "Library $LIBRARY_NAME created successfully!"

