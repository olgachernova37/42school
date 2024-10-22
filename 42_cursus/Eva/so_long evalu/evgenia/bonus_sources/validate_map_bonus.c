/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:40 by emarko            #+#    #+#             */
/*   Updated: 2024/07/31 17:50:23 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_null_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_validate_map_error(game, ERR_MAP_NOT_RECTANGLE);
		}
		i++;
	}
}

void	ft_check_edges(t_map *map, t_game *game)
{
	int	cl;
	int	rw;

	cl = 0;
	while (cl < map->cols)
	{
		if (map->map[0][cl] != '1' || map->map[map->rows - 1][cl] != '1')
			break ;
		cl++;
	}
	rw = 0;
	while (rw < map->rows)
	{
		if (map->map[rw][0] != '1' || map->map[rw][map->cols - 1] != '1')
			break ;
		rw++;
	}
	if (cl != map->cols || rw != map->rows)
		ft_validate_map_error(game, ERR_EDGE);
}

void	ft_check_chars(t_map *map, char *map_temp, t_game *game)
{
	char	*ptr;

	ptr = map_temp;
	while (*ptr)
	{
		if (*ptr == 'E')
			map->exits++;
		if (*ptr == 'C')
			map->coins++;
		if (*ptr == 'P')
			map->players++;
		ptr++;
	}
	if (map->exits != 1 || map->coins < 1 || map->players != 1)
	{
		free(map_temp);
		ft_validate_map_error(game, ERR_CHARS);
	}
}

void	ft_validate_map(char *map_temp, t_map *map, t_game *game)
{
	ft_check_null_line(map_temp, game);
	ft_check_edges(map, game);
	ft_check_chars(map, map_temp, game);
	ft_solve_map(game);
}
