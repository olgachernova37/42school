/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:08:29 by onosul            #+#    #+#             */
/*   Updated: 2024/08/15 15:19:00 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(int *board)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || (i - col) == (board[i] - row) || (i
				- col) == (row - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}
