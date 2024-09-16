/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksevciko <ksevciko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:58:12 by tchernen          #+#    #+#             */
/*   Updated: 2024/08/10 13:10:54 by ksevciko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	row_col(int row, int col, int x, int y)
{
	if ((row == 1 && col == 1) || (row == y && col == 1) || (row == 1
			&& col == x) || (row == y && col == x))
	{
		ft_putchar('o');
	}
	else if ((row == 1 || row == y))
	{
		ft_putchar('-');
	}
	else if ((col == 1 || col == x))
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			row_col(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
