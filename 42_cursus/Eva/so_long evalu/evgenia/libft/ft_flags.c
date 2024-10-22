/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:17 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:18 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flag	ft_flag_init(void)
{
	t_flag	flags;

	flags.conv = 0;
	flags.left = 0;
	flags.zero = 0;
	flags.precision = 0;
	flags.prec_width = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.width = 0;
	flags.asterisk = 0;
	return (flags);
}

void	ft_flagleft(t_flag *flags)
{
	flags -> left = 1;
	flags -> zero = 0;
	flags -> width = 0;
}

void	ft_flagplus(t_flag *flags)
{
	flags -> plus = 1;
	flags -> space = 0;
}
