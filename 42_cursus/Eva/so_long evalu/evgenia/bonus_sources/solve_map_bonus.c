/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:20:27 by emarko            #+#    #+#             */
/*   Updated: 2024/07/31 18:16:31 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_copy_map(t_game *game)
{
	int		i;
	char	**copy_map;

	copy_map = malloc(sizeof(char *) * (game->map.rows + 1));
	i = 0;
	while (i < game->map.rows)
	{
		copy_map[i] = ft_strdup(game->map.map[i]);
		if (!copy_map[i])
		{
			while (--i >= 0)
				free(copy_map[i]);
			free(copy_map);
			ft_handle_error(game, ERR_MALLOC);
		}
		i++;
	}
	copy_map[game->map.rows] = NULL;
	return (copy_map);
}

int	ft_set_current(char *current, t_map *map)
{
	if (*current == 'C')
		map->coins--;
	else if (*current == 'E')
		map->exits--;
	*current = 'V';
	return (1);
}

int	ft_solver(t_map *map, int row, int col)
{
	char	*current;

	current = &map->map[row][col];
	if (map->exits == 0 && map->coins == 0)
		return (1);
	if (current[0] != 'V' && current[0] != '1' && current[0] != 'T')
	{
		ft_set_current(current, map);
		if (ft_solver(map, row, col - 1))
			return (ft_set_current(current, map));
		if (ft_solver(map, row, col + 1))
			return (ft_set_current(current, map));
		if (ft_solver(map, row + 1, col))
			return (ft_set_current(current, map));
		if (ft_solver(map, row - 1, col))
			return (ft_set_current(current, map));
	}
	return (0);
}

void	ft_solve_map(t_game *game)
{
	int		row;
	int		col;
	char	**copy_map;
	t_map	copy;
	int		solved;

	copy_map = ft_copy_map(game);
	copy = game->map;
	copy.map = copy_map;
	row = copy.py;
	col = copy.px;
	solved = ft_solver(&copy, row, col);
	ft_free_map(copy.map, copy.rows);
	if (!solved)
	{
		if (copy.coins > 0)
			ft_validate_map_error(game, ERR_COLLECT);
		else
			ft_validate_map_error(game, ERR_EXIT);
	}
}
