/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:45:56 by rkarymsh          #+#    #+#             */
/*   Updated: 2024/08/10 17:20:44 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *first_ptr, int *second_ptr)
{
	int	tmp_value;

	tmp_value = *first_ptr;
	*first_ptr = *second_ptr;
	*second_ptr = tmp_value;
}

int main(void)
{
	int	first_number;
	int	second_number;
	int *first_n_ptr;
	int *second_n_ptr;

	first_number = 1;
	second_number = 2;
	first_n_ptr = &first_number;
	second_n_ptr = &second_number;

	ft_swap(1, 2);
}