/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:56:56 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/25 15:50:12 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{	
	
	// 
	
	ft_printf(" %X ", LONG_MAX);
	printf(" %lX ", LONG_MAX);
	
	// ft_printf("STR :%s, %s\n", "Hello", "World");
	// printf("STR :%s, %s\n", "Hello", "World");
	// int result = 0;
	// result = ft_printf("%p\n", (void *)&result);
	// printf("%p", (void *)&result);
	// printf("%u\n", -100);
	// ft_printf("%u\n", 100);
	// ft_printf("%x\n", 10);
	// ft_printf("The discount is 20%% off!\n");
	// ft_printf("%X", 100);
	// ft_printf("%s", "");
	// ft_printf("this is a %s", "test");
	// ft_printf("%s", "-24");
	// ft_printf("%s", "0x0000042");
	// ft_printf("some naugty tests: %s", "%000");
	// ft_printf("%s", "h");
	// ft_printf("t%st%s", "a", "u");
	// ft_printf("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");
}
