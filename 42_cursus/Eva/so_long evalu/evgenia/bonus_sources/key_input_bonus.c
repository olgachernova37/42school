/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:59:43 by emarko            #+#    #+#             */
/*   Updated: 2024/07/31 17:22:58 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_key_input(int keycode, t_game *game)
{
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_player_move(game, game->hero_down, game->map.px, game->map.py + 1);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_player_move(game, game->hero_right, game->map.px + 1, game->map.py);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_player_move(game, game->hero_left, game->map.px - 1, game->map.py);
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_player_move(game, game->hero_up, game->map.px, game->map.py - 1);
	if (keycode == KEY_ESC || keycode == 53)
		ft_close_game(game);
	return (0);
}

void	ft_player_move(t_game *game, t_img hero, int x, int y)
{
	if (game->map.map[y][x] == '1'
		|| (game->map.map[y][x] == 'E' && !game->exit_status))
		return ;
	if (game->map.map[y][x] == 'T')
		ft_lose_game(game);
	if (game->map.map[y][x] == 'C')
	{
		game->map.coins--;
		game->map.map[y][x] = '0';
	}
	if (game->map.coins == 0)
		game->exit_status = 1;
	game->moves++;
	ft_render_srite(game, hero, x, y);
	if (game->map.map[y][x] == 'E' && game->exit_status)
		ft_win_game(game);
}
