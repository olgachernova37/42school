# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhruby <mhruby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 19:00:46 by mhruby            #+#    #+#              #
#    Updated: 2024/10/25 12:21:11 by mhruby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER 		= ft_printf.h
SRC 		= ft_printf.c printf_char.c printf_string.c printf_ptr.c \
				printf_nbr.c printf_hex.c printf_uint.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_strlen.c
OBJS 		= $(SRC:.c=.o)

NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)

	ar -rcs $(NAME) $(OBJS)

%.o: %.c  $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@  


fclean: clean
	rm -rf $(NAME)	

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re