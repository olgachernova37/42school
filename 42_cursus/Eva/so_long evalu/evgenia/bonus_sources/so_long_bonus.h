/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:43 by emarko            #+#    #+#             */
/*   Updated: 2024/10/09 18:47:45 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include <mlx.h>
# define IMG_SIZE				64
# define FRAME_INTERVAL			40000

# define ERR_MAP_NOT_RECTANGLE	1
# define ERR_MAIN_ARGV			2
# define ERR_MALLOC				3
# define ERR_OPEN_FILE			4
# define ERR_FILL_MAP			5
# define ERR_ROWS				6
# define ERR_COLS				7
# define ERR_EDGE				8
# define ERR_CHARS				9
# define ERR_EXIT				10
# define ERR_COLLECT			11
# define ERR_MLX_INIT			12
# define ERR_WIN_INIT			13
# define ERR_SPRITE_INIT		14

# define GREEN					"\033[0;32m"
# define RED 					"\033[1;31m"
# define GREY 					"\033[0;90m"
# define CYAN					"\033[1;96m"
# define RESET 					"\033[0m"

# define KEY_ESC				65307

# define KEY_W					119
# define KEY_S					115
# define KEY_A					97
# define KEY_D					100

# define KEY_UP  				65362
# define KEY_LEFT  				65361
# define KEY_RIGHT 				65363
# define KEY_DOWN  				65364

# define FLOOR_XPM				"graphic/floor.xpm"
# define WALL_XPM				"graphic/wall.xpm"
# define WALL_M1_XPM			"graphic/wall_m1.xpm"
# define WALL_M2_XPM			"graphic/wall_m2.xpm"
# define COIN					"graphic/coin.xpm"
# define EXIT_OPEN				"graphic/exit_open.xpm"
# define EXIT_CLOSED			"graphic/exit_closed.xpm"
# define HERO_UP_XPM			"graphic/hero_up.xpm"
# define HERO_LEFT_XPM			"graphic/hero_left.xpm"
# define HERO_RIGHT_XPM			"graphic/hero_right.xpm"
# define HERO_DOWN_XPM			"graphic/hero_down.xpm"
# define ENEMY1_XPM				"graphic/enemy1.xpm"
# define ENEMY2_XPM				"graphic/enemy2.xpm"

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		allocated;
	int		rows;
	int		cols;
	int		players;
	int		coins;
	int		exits;
	int		px;
	int		py;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		exit_status;
	int		moves;
	int		enemy_state;
	int		frame_count;
	t_img	hero_up;
	t_img	hero_down;
	t_img	hero_left;
	t_img	hero_right;
	t_img	floor;
	t_img	wall;
	t_img	coin;
	t_img	exit_open;
	t_img	exit_closed;
	t_img	enemy1;
	t_img	enemy2;
	t_img	wall_m1;
	t_img	wall_m2;
}	t_game;

int		ft_error_close(t_game *game);
void	ft_handle_error(t_game *game, int error_code);
void	ft_validate_map_error(t_game *game, int error_code);
void	ft_free_map(char **map, int rows);
void	ft_destroy_imgs(t_game *game);
void	ft_free_game(t_game *game);
int		ft_close_game(t_game *game);
int		ft_win_game(t_game *game);
void	ft_mlx_init(t_game *game);
void	ft_parse_map(char *file_name, t_game *game);
void	ft_check_null_line(char *map, t_game *game);
void	ft_check_edges(t_map *map, t_game *game);
void	ft_check_chars(t_map *map, char *map_temp, t_game *game);
void	ft_validate_map(char *map_temp, t_map *map, t_game *game);
void	**ft_malloc_map(int rows, int cols, int el_size, t_game *game);
void	ft_get_position(t_map *map);
void	ft_solve_map(t_game *game);
char	*ft_strappend(char **s1, const char *s2);
int		ft_open_file(char *file_name, t_game *game);
t_game	*ft_game_init(char *file_name);
int		ft_key_input(int keycode, t_game *game);
void	ft_render_map(t_game *game, t_map map);
void	ft_render_srite(t_game *game, t_img sprite, int x, int y);
void	ft_put_sprites(t_game *game, t_map map, int r, int c);
void	ft_player_move(t_game *game, t_img hero, int x, int y);
void	ft_print_movements(t_game *game);
int		ft_animate_enemy(t_game *game);
void	ft_render_enemies(t_game *game, t_map map, t_img enemy);
void	ft_lose_game(t_game *game);

#endif