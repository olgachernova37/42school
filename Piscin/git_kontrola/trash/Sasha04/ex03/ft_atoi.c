/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:32:55 by alisseye          #+#    #+#             */
/*   Updated: 2024/08/17 21:20:06 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>

int	ft_mul_ten(int n, int t)
{
	while (t > 1)
	{
		n *= 10;
		t--;
	}
	return (n);
}

int	ft_strlen_int(char *str)
{
	int	len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
	{
		len++;
	}
	return (len);
}

int	ft_lstrip_idx(char *str, int i)
{
	while (str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_posneg(char *str, int *i)
{
	int	minuses;

	minuses = 0;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			minuses++;
		}
		*i += 1;
	}
	if (minuses % 2)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int	ft_atoi(char *str)
{
	int	res;
	int	len;
	int	i;
	int	p;

	i = ft_lstrip_idx(str, 0);
	p = ft_posneg(str, &i);
	res = 0;
	len = ft_strlen_int(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += ((int)(str[i] - '0')) * ft_mul_ten(1, len);
		i++;
		len--;
	}
	res *= p;
	return (res);
}

// int main(void)
// {
// 	char	*snbr = "-4567adasds";

// 	printf("%d\n", atoi(snbr));
// 	printf("%d\n", ft_atoi(snbr));
// 	return (0);
// }
