/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:17:25 by mmravec           #+#    #+#             */
/*   Updated: 2024/08/09 12:06:22 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <stdio.h>
int main() 
{
    int a;
    int b;

    a = 5;
    b = 999;
    printf("Puvodni hodnoty a: %d, b: %d\n", a, b);
    ft_swap(&a, &b);
    printf("Nove hodnoty a: %d, b: %d\n", a, b);
    return (0);
}
*/