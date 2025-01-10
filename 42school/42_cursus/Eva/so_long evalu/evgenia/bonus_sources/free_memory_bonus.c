/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:40:50 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 15:03:40 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_map(char **map, int rows)
{
	while (--rows >= 0)
		free(map[rows]);
	free(map);
}

void	*ft_destroy_sprit(void *mlx, t_img *sprite)
{
	if (sprite->xpm_ptr)
	{
		mlx_destroy_image(mlx, sprite->xpm_ptr);
		return (NULL);
	}
	return (sprite->xpm_ptr);
}

void	ft_destroy_imgs(t_game *game)
{
	game->hero_up.xpm_ptr = ft_destroy_sprit(game->mlx, &game->hero_up);
	game->hero_down.xpm_ptr = ft_destroy_sprit(game->mlx, &game->hero_down);
	game->hero_left.xpm_ptr = ft_destroy_sprit(game->mlx, &game->hero_left);
	game->hero_right.xpm_ptr = ft_destroy_sprit(game->mlx, &game->hero_right);
	game->floor.xpm_ptr = ft_destroy_sprit(game->mlx, &game->floor);
	game->wall.xpm_ptr = ft_destroy_sprit(game->mlx, &game->wall);
	game->wall_m1.xpm_ptr = ft_destroy_sprit(game->mlx, &game->wall_m1);
	game->wall_m2.xpm_ptr = ft_destroy_sprit(game->mlx, &game->wall_m2);
	game->coin.xpm_ptr = ft_destroy_sprit(game->mlx, &game->coin);
	game->exit_open.xpm_ptr = ft_destroy_sprit(game->mlx, &game->exit_open);
	game->exit_closed.xpm_ptr = ft_destroy_sprit(game->mlx, &game->exit_closed);
	game->enemy1.xpm_ptr = ft_destroy_sprit(game->mlx, &game->exit_closed);
	game->enemy2.xpm_ptr = ft_destroy_sprit(game->mlx, &game->exit_closed);
}

void	ft_free_game(t_game *game)
{
	if (game->map.allocated)
	{
		ft_free_map(game->map.map, game->map.rows);
		game->map.allocated = 0;
		game->map.map = NULL;
	}
	ft_destroy_imgs(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
	game = NULL;
}
