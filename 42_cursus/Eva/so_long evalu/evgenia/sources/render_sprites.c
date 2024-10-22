/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 18:49:01 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_sprites(t_game *game, t_map map, int r, int c);

void	ft_render_map(t_game *game, t_map map)
{
	int	r;
	int	c;

	r = 0;
	while (r < map.rows)
	{
		c = 0;
		while (c < map.cols)
		{
			ft_put_sprites(game, map, r, c);
			c++;
		}
		r++;
	}
}

void	ft_put_sprites(t_game *game, t_map map, int r, int c)
{
	if (map.map[r][c] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->wall.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
	else if (map.map[r][c] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->hero_down.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
	else if (map.map[r][c] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->exit_closed.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
	else if (map.map[r][c] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->coin.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->floor.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
}

void	ft_exit_open(t_game *game, t_map map)
{
	int	r;
	int	c;

	r = 0;
	while (r < map.rows)
	{
		c = 0;
		while (c < map.cols)
		{
			if (map.map[r][c] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->exit_open.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
			c++;
		}
		r++;
	}
}

void	ft_render_srite(t_game *game, t_img sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm_ptr, \
	game->map.px * IMG_SIZE, game->map.py * IMG_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm_ptr, \
	x * IMG_SIZE, y * IMG_SIZE);
	game->map.px = x;
	game->map.py = y;
	if (game->exit_status)
		ft_exit_open(game, game->map);
}
