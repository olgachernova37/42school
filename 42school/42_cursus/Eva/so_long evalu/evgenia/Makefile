NAME            =   so_long
NAME_BONUS      =   so_long_bonus

CC              =   gcc
CFLAGS          =   -Wall -Wextra -Werror

SRCS_DIR        =   ./sources
BONUS_DIR       =   ./bonus_sources
OBJ_DIR         =   $(SRCS_DIR)/obj
OBJ_BONUS_DIR   =   $(BONUS_DIR)/obj

SRCS            =   $(wildcard $(SRCS_DIR)/*.c)
SRCS_BONUS      =   $(wildcard $(BONUS_DIR)/*.c)

OBJS            =   $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS      =   $(SRCS_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

LIBFT_PATH      =   ./libft
LIBFT           =   $(LIBFT_PATH)/libft.a
LIBFT_FLAG      =   -L$(LIBFT_PATH) -lft

MLX_DIR         =   ./mlx
MLX_LIB         =   $(MLX_DIR)/libmlx_$(UNAME).a

INCLUDES        =   -I/usr/include -Imlx -O3
MLX_FLAGS       =   -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

all:            $(NAME)

$(LIBFT):
				make -C $(LIBFT_PATH) all

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
				@mkdir -p $(OBJ_BONUS_DIR)
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME):        $(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAG) $(MLX_FLAGS)

bonus:          $(NAME_BONUS)

$(NAME_BONUS):  $(LIBFT) $(OBJS_BONUS)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_FLAG) $(MLX_FLAGS)

clean:
				make -C $(LIBFT_PATH) clean
				rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean:         clean
				make -C $(LIBFT_PATH) fclean
				rm -f $(NAME) $(NAME_BONUS)

re:             fclean all

rebonus:        fclean bonus

run:            $(NAME)
				./$(NAME) maps/map5.ber

run_bonus:      $(NAME_BONUS)
				./$(NAME_BONUS) maps/bonus/map5.ber

.PHONY:         all clean fclean re rebonus run run_bonus
