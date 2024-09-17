NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SOURCES = ft_isalpha.c
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

%.o: %.c
	   cc $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all