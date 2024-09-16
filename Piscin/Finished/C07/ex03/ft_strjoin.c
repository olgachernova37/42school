/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:22:26 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/28 15:25:31 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)

{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

int	count_length_of_strings(char **strs, int sep_len, int size)
{
	int	i;
	int	total_length;

	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += (size - 1) * sep_len;
	return (total_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		result_length;
	int		i;

	if (size == 0)
	{
		result = (char *)malloc(1 * sizeof(char));
		if (result != NULL)
			result[0] = '\0';
		return (result);
	}
	result_length = count_length_of_strings(strs, ft_strlen(sep), size) + 1;
	result = (char *)malloc(result_length * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		i++;
		if (i < size)
			result = ft_strcat(result, sep);
	}
	return (result);
}

/*#include <stdio.h>
int	main(void)
{
	char	*strings[] = {""};
	char	*separator;
	char	*result;

	// char *strings[] = {"Hello", "world", "from", "C", NULL};
	separator = "****";
	result = ft_strjoin(1, strings, separator);
	if (result != NULL)
	{
		printf("Result: %s\n", result);
		free(result);  // Remember to free the allocated memory
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
*/