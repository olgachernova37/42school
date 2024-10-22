/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:40 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 16:12:35 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prints(char *str, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
		ft_printc(str[count++]);
	return (count);
}

int	ft_printstr(char *str, t_flag flags)
{
	size_t	count;
	size_t	len;

	count = 0;
	if (str == NULL)
	{
		if (flags.prec_width < 6 && flags.precision)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	if (flags.precision && (size_t)flags.prec_width < len)
		len = flags.prec_width;
	if ((size_t)flags.width > len)
	{
		if (!flags.left)
			count += ft_print_rflags((size_t)flags.width, len, flags.zero);
		count += ft_prints(str, len);
		if (flags.left)
			count += ft_print_lflags((size_t)flags.width, len);
	}
	else
		count += ft_prints(str, len);
	return (count);
}
