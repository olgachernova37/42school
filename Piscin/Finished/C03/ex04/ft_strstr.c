/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:54:27 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/15 18:04:12 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	e;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			e = 0;
			while (to_find[e] != '\0' && str[i + e] == to_find[e])
			{
				e++;
			}
			if (to_find[e] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
