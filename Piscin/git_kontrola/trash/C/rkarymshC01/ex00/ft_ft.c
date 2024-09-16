/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:27:53 by rkarymsh          #+#    #+#             */
/*   Updated: 2024/08/10 14:27:37 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int main(void)
{
	int numberToCheck;
	int *ptr;

	numberToCheck = 0;
	ptr = &numberToCheck;
	ft_ft(ptr);
}