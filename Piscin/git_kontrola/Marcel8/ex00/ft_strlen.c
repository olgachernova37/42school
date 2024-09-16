/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:11:19 by mmravec           #+#    #+#             */
/*   Updated: 2024/08/09 12:05:22 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/*
#include <stdio.h>

int main(void)
{
    char* my_string;
    int length;

    my_string = "Hello world.\nNice day isn't it?\n";
    length = ft_strlen(my_string);
    printf("Length of my string: %s\nis %d characters.", my_string, length);
    return 0;
}
*/