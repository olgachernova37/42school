/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:38:53 by emarko            #+#    #+#             */
/*   Updated: 2024/07/31 17:51:00 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_position(t_map *map)
{
	int	r;
	int	c;

	r = 0;
	while (map->map[r])
	{
		c = 0;
		while (map->map[r][c])
		{
			if (map->map[r][c] == 'P')
			{
				map->px = c;
				map->py = r;
			}
			c++;
		}
		r++;
	}
}

void	ft_parse_map(char *file_name, t_game *game)
{
	char	*line;
	char	*map_temp;
	int		fd;

	fd = ft_open_file(file_name, game);
	if (fd < 0)
		ft_handle_error(game, ERR_OPEN_FILE);
	map_temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line);
		free(line);
		game->map.rows++;
	}
	close(fd);
	game->map.map = ft_split(map_temp, '\n');
	game->map.allocated = 1;
	game->map.cols = ft_strlen(game->map.map[0]);
	ft_get_position(&game->map);
	ft_validate_map(map_temp, &game->map, game);
	free(map_temp);
}
