/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:40:50 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 15:03:40 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_error(t_game *game, int error_code)
{
	if (error_code == ERR_MLX_INIT)
		ft_printf(RED"Error\n"GREY"Failed to initialize MLX.\n"RESET);
	if (error_code == ERR_WIN_INIT)
		ft_printf(RED"Error\n"GREY"Failed to initialize window.\n"RESET);
	if (error_code == ERR_SPRITE_INIT)
		ft_printf(RED"Error\n"GREY"Failed to initialize sprite.\n"RESET);
	if (error_code == ERR_MAIN_ARGV)
		ft_printf(RED"Error\n"GREY"Incorrect number of arguments.\n"RESET);
	if (error_code == ERR_MALLOC)
		ft_printf(RED"Error\n"GREY"Memory allocation failed.\n"RESET);
	if (error_code == ERR_OPEN_FILE)
		ft_printf(RED"Error\n"GREY"Could not open file.\n"RESET);
	if (error_code == ERR_FILL_MAP)
		ft_printf(RED"Error\n"GREY"Could not fill the map.\n"RESET);
	ft_error_close(game);
}

void	ft_validate_map_error(t_game *game, int error_code)
{
	if (error_code == ERR_MAP_NOT_RECTANGLE)
		ft_printf(RED"Error\n"GREY"Map is not rectangle.\n"RESET);
	if (error_code == ERR_ROWS)
		ft_printf(RED"Error\n"GREY"Not enough rows.\n"RESET);
	if (error_code == ERR_COLS)
		ft_printf(RED"Error\n"GREY"Not enough columns.\n"RESET);
	if (error_code == ERR_EDGE)
		ft_printf(RED"Error\n"GREY"Map is not closed with walls.\n"RESET);
	if (error_code == ERR_CHARS)
		ft_printf(RED"Error\n"GREY"Incorrect number of Exit, \
Position or Collectables.\n");
	if (error_code == ERR_EXIT)
		ft_printf(RED"Error\n"GREY"Can't reach exit.\n"RESET);
	if (error_code == ERR_COLLECT)
		ft_printf(RED"Error\n"GREY"Can't reach all collectables.\n"RESET);
	ft_error_close(game);
}

int	ft_error_close(t_game *game)
{
	ft_free_game(game);
	exit (EXIT_FAILURE);
}
