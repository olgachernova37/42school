# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 17:06:51 by mmravec           #+#    #+#              #
#    Updated: 2024/08/21 17:06:54 by mmravec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ = $(SRC:.c=.o)
OBJ_FILES = $(addprefix $(SRCDIR)/,$(OBJ))

# Default rule, equivalent to "make all"
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ_FILES)
	@echo "Creating $(NAME)..."
	ar rcs $(NAME) $(OBJ_FILES)

# Rule to compile .c files to .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/ft.h
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Clean object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ_FILES)

# Clean object files and the library
fclean: clean
	@echo "Cleaning library $(NAME)..."
	rm -f $(NAME)

# Recompile everything
re: fclean all

# Special target to ensure 'clean', 'fclean', and 're' are not considered as file names
.PHONY: all clean fclean re
