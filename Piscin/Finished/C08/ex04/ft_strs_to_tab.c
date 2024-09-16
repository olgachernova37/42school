/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:59:10 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/28 18:04:02 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s1;

	i = 0;
	s1 = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!s1)
		return (NULL);
	while (i < ac)
	{
		s1[i].size = ft_strlen(av[i]);
		s1[i].str = av[i];
		s1[i].copy = ft_strdup(av[i]);
		i++;
	}
	s1[i].str = NULL;
	return (s1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char				*strs[] = {""};
// 	int					size;
// 	struct s_stock_str	*result;

// 	// char *strs[] = {"hello", "world", "this", "is", "a", "test"};
// 	size = sizeof(strs) / sizeof(char *);
// 	result = ft_strs_to_tab(size, strs);
// 	if (result == NULL)
// 	{
// 		printf("Error: ft_strs_to_tab returned NULL\n");
// 		return (1);
// 	}
// 	// ft_show_tab(result);
// 	// Free the allocated memory
// 	for (int i = 0; i < size; i++)
// 	{
// 		free(result[i].copy);
// 	}
// 	free(result);
// 	return (0);
// }
