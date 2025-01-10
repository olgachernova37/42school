/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:40:50 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 15:03:40 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	ft_printf(CYAN"Movements: %d\n"GREY"GAME CLOSED\n"RESET, game->moves);
	exit (EXIT_SUCCESS);
}

int	ft_win_game(t_game *game)
{
	ft_free_game(game);
	ft_printf(CYAN"Movements: %d\n"GREEN"\n\
███████████████████████████████████\n\
██                               ██\n\
██  ███  ███  ██████  ██    ██   ██\n\
██   ██  ██  ██    ██ ██    ██   ██\n\
██    ████   █      █ ██    ██   ██\n\
██     ██    ██    ██ ██    ██   ██\n\
██     ██     ██████    ████     ██\n\
██                               ██\n\
██  ██      ██ ██ ██    ██   ██  ██\n\
██  ██      ██ ██ ███   ██   ██  ██\n\
██  ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██  ██ ████ ██ ██ ██  ████       ██\n\
██   ███  ███  ██ ██   ███   ██  ██\n\
██                               ██\n\
███████████████████████████████████\n\n\
"RESET, game->moves);
	exit (EXIT_SUCCESS);
}
