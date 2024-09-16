/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:35:54 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/11 16:59:33 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	l;
	int	temp;
	int	f;

	f = 0;
	l = size - 1;
	while (f < l)
	{
		temp = tab[f];
		tab[f] = tab[l];
		tab[l] = temp;
		f++;
		l--;
	}
}
