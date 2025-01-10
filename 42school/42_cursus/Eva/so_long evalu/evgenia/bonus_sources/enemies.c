/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by emarko            #+#    #+#             */
/*   Updated: 2024/10/09 18:38:35 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_animate_enemy(t_game *game)
{
	if (game->frame_count >= FRAME_INTERVAL)
	{
		if (game->enemy_state == 0)
		{
			ft_render_enemies(game, game->map, game->enemy1);
			game->enemy_state = 1;
		}
		else
		{
			ft_render_enemies(game, game->map, game->enemy2);
			game->enemy_state = 0;
		}
		game->frame_count = 0;
	}
	game->frame_count++;
	return (0);
}

void	ft_render_enemies(t_game *game, t_map map, t_img enemy)
{
	int	r;
	int	c;

	r = 0;
	while (r < map.rows)
	{
		c = 0;
		while (c < map.cols)
		{
			if (map.map[r][c] == 'T')
				mlx_put_image_to_window(game->mlx, game->win, \
				enemy.xpm_ptr, c * IMG_SIZE, r * IMG_SIZE);
			c++;
		}
		r++;
	}
}
