/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:38:10 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/11 16:57:06 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	f;
	int	temp;
	int	sort;

	sort = 0;
	while (sort == 0)
	{
		sort = 1;
		f = 0;
		while (f < (size - 1))
		{
			if (tab[f] > tab[f + 1])
			{
				temp = tab[f];
				tab[f] = tab[f + 1];
				tab[f + 1] = temp;
				sort = 0;
			}
			f++;
		}
	}
}
