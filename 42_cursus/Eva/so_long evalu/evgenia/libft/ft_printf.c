/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:25 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:41:37 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parse_args(const char *str, int *i, t_flag flags, va_list args)
{
	int		count;

	count = 0;
	if (str[*i] == 's')
		count = ft_printstr(va_arg(args, char *), flags);
	else if (str[*i] == 'c')
		count = ft_printchar(va_arg(args, int), flags);
	else if (str[*i] == '%')
		count = ft_printc('%');
	else if (str[*i] == 'd' || str[*i] == 'i')
		count = ft_printdec(va_arg(args, int), flags);
	else if (str[*i] == 'x')
		count = ft_printhex(va_arg(args, int), flags, 0);
	else if (str[*i] == 'X')
		count = ft_printhex(va_arg(args, int), flags, 1);
	else if (str[*i] == 'p')
		count = ft_printptr((unsigned long int)va_arg(args, void *), flags);
	else if (str[*i] == 'u')
		count = ft_printuni(va_arg(args, unsigned int), flags);
	else
		return (0);
	return (count);
}

static void	ft_parse_width(const char *str, int *i, t_flag *flags, va_list args)
{
	if (str[(*i) - 1] == '.')
	{
		if (flags->asterisk)
			flags->prec_width = va_arg(args, int);
		else
		{
			while (ft_isdigit(str[*i]))
				flags->prec_width = flags->prec_width * 10
					+ (str[(*i)++] - '0');
			(*i)--;
		}
	}
	else
	{
		if (flags->asterisk)
			flags->width = va_arg(args, int);
		else
		{
			while (ft_isdigit(str[*i]))
				flags->width = flags->width * 10 + (str[(*i)++] - '0');
			(*i)--;
		}
	}
}

static void	ft_parse_flags(const char *str, int *i, t_flag *flags, va_list args)
{
	if (str[*i] == '-')
		ft_flagleft(flags);
	else if (str[*i] == '+')
		ft_flagplus(flags);
	else if (str[*i] == ' ' && !flags->plus)
		flags -> space = 1;
	else if (str[*i] == '.')
		flags -> precision = 1;
	else if (str[*i] == '0' && str[(*i) - 1] != '.' && !flags->left
		&& flags->width == 0)
		flags -> zero = 1;
	else if (str[*i] == '#' && !flags->precision)
		flags -> hash = 1;
	else if (str[*i] == '*')
	{
		flags -> asterisk = 1;
		ft_parse_width(str, i, flags, args);
	}
	else if (ft_isdigit(str[*i]))
		ft_parse_width(str, i, flags, args);
}

static int	ft_initparse(const char *str, int *i, va_list args)
{
	int		count;
	t_flag	flags;

	flags = ft_flag_init();
	count = 0;
	while (!ft_istype(str[*i]))
	{
		if (ft_isflag(str[*i]))
			ft_parse_flags(str, i, &flags, args);
		(*i)++;
	}
	count = ft_parse_args(str, i, flags, args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	const char	*ptr;
	va_list		args;
	int			count;
	int			i;

	ptr = format;
	if (!ptr)
		return (0);
	va_start(args, format);
	count = 0;
	i = -1;
	while (ptr[++i])
	{
		if (ptr[i] == '%' && ptr[i + 1] != '\0')
		{
			i++;
			count += ft_initparse(ptr, &i, args);
		}
		else
			count += ft_printc(ptr[i]);
	}
	va_end(args);
	return (count);
}
