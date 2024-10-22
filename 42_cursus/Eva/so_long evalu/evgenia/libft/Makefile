NAME			=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	$(wildcard *.c)

OBJ_DIR			=	obj
OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all: 				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJ)
		 			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all
