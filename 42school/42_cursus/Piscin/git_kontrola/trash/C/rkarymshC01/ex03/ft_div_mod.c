/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:45:24 by rkarymsh          #+#    #+#             */
/*   Updated: 2024/08/10 14:40:02 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int first_number, int second_number, int *div, int *mod)
{
	*div = first_number / second_number;
	*mod = first_number % second_number;
}

int main(void)
{
	int	div;
	int	mod;
	int *ptr_div;
	int	*ptr_mod;

	div = 0;
	mod = 0;
	ptr_div = &div;
	ptr_mod = &mod;
	ft_div_mod(6, 4, ptr_div, ptr_mod);
}