/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:21 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 18:49:01 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_handle_error(NULL, ERR_MAIN_ARGV);
	game = ft_game_init(argv[1]);
	ft_render_map(game, game->map);
	mlx_hook(game->win, 2, 1L << 0, ft_key_input, game);
	mlx_hook(game->win, 17, 1L << 2, ft_close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
