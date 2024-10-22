/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 18:49:01 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_handle_error(game, ERR_MLX_INIT);
	game->win = mlx_new_window(game->mlx, game->map.cols * IMG_SIZE, \
	game->map.rows * IMG_SIZE, "so long");
	if (!game->win)
		ft_handle_error(game, ERR_WIN_INIT);
}

t_img	ft_new_sprite(t_game *game, char *path)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(game->mlx, path, \
	&sprite.x, &sprite.y);
	if (!sprite.xpm_ptr)
		ft_handle_error(game, ERR_SPRITE_INIT);
	return (sprite);
}

void	ft_sprites_init(t_game *game)
{
	game->floor = ft_new_sprite(game, FLOOR_XPM);
	game->wall = ft_new_sprite(game, WALL_XPM);
	game->wall_m1 = ft_new_sprite(game, WALL_M1_XPM);
	game->wall_m2 = ft_new_sprite(game, WALL_M2_XPM);
	game->coin = ft_new_sprite(game, COIN);
	game->exit_open = ft_new_sprite(game, EXIT_OPEN);
	game->exit_closed = ft_new_sprite(game, EXIT_CLOSED);
	game->hero_up = ft_new_sprite(game, HERO_UP_XPM);
	game->hero_down = ft_new_sprite(game, HERO_DOWN_XPM);
	game->hero_left = ft_new_sprite(game, HERO_LEFT_XPM);
	game->hero_right = ft_new_sprite(game, HERO_RIGHT_XPM);
	game->enemy1 = ft_new_sprite(game, ENEMY1_XPM);
	game->enemy2 = ft_new_sprite(game, ENEMY2_XPM);
}

void	ft_vars_init(t_game *game)
{
	game->exit_status = 0;
	game->moves = 0;
	game->map.exits = 0;
	game->map.coins = 0;
	game->map.players = 0;
	game->enemy_state = 0;
	game->frame_count = 0;
}

t_game	*ft_game_init(char *file_name)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_handle_error(game, ERR_MALLOC);
	ft_vars_init(game);
	ft_parse_map(file_name, game);
	ft_mlx_init(game);
	ft_sprites_init(game);
	return (game);
}
