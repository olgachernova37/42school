/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:10:04 by rkarymsh          #+#    #+#             */
/*   Updated: 2024/08/10 14:39:56 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *ptr_first_number, int *ptr_second_number)
{
	int	tmp_div;

	tmp_div = *ptr_first_number / *ptr_second_number;
	*ptr_second_number = *ptr_first_number % *ptr_second_number;
	*ptr_first_number = tmp_div;
}

int	main(void)
{
	int first_number;
	int second_number;
	int* ptr_first_number;
	int* ptr_second_number;

	first_number = 10;
	second_number = 3;
	ptr_first_number = &first_number;
	ptr_second_number = &second_number;
	ft_ultimate_div_mod(ptr_first_number, ptr_second_number);
}