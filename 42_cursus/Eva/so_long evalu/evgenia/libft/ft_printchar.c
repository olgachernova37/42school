/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:20 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:21 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printc(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printchar(int c, t_flag flags)
{
	size_t	count;

	count = 0;
	if (flags.width > 1)
	{
		if (!flags.left)
			count += ft_print_rflags((size_t)flags.width, 1, flags.zero);
		count += ft_printc(c);
		if (flags.left)
			count += ft_print_lflags(flags.width, 1);
	}
	else
		count += ft_printc(c);
	return (count);
}
