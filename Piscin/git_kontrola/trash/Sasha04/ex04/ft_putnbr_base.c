/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:22:24 by alisseye          #+#    #+#             */
/*   Updated: 2024/08/19 14:12:38 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len <= 1)
	{
		return (0);
	}
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_len;
	long int	n;

	n = nbr;
	base_len = ft_strlen(base);
	if (!ft_is_valid_base(base))
	{
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
	}
	write(1, &base[n % base_len], 1);
}

// int	main(void)
// {
// 	char *base = "01";

// 	ft_putnbr_base(20, base);
// }
