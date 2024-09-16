/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:58:12 by tchernen          #+#    #+#             */
/*   Updated: 2024/08/10 16:01:38 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	row_col(int row, int col, int x, int y)
{
	if (row == 1 && col == 1)
	{
		ft_putchar('A');
	}
	else if ((row == 1 && col == x) || (row == y && col == 1))
	{
		ft_putchar('C');
	}
	else if (row == y && col == x)
	{
		ft_putchar('A');
	}
	else if (row == 1 || row == y || col == 1 || col == x)
	{
		ft_putchar('B');
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
