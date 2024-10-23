/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:05 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/23 20:19:15 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int print_hexadecimal(unsigned long nbr, char symbol)
{
  char res[40];
  int i;
  if (nbr == 0)
  {
    write(1, "0", 1);
    return(1);
  }
  i = 35;
  res[i] = '\0';
  i--;
  while (nbr!=0)
  {
    if (symbol == 'x')
      res[i] = "0123456789abcdef"[nbr % 16];
    else 
      res[i] = "0123456789ABCDEF"[nbr % 16];
    nbr /=16;
    i--;
  }
  i++;
  while (res[i]!= '\0')
  {
    write(1, &res[i], 1);
    i++;
  }
  return(1);
}

int	print_address(unsigned long nbr)
{
  write(1,"0",1);
  write(1,"x",1);
  return print_hexadecimal (nbr, 'x');
}

int	print_specifier(char symbol, va_list args)
{
	int	counter;

	counter = 0;
	if (symbol == 'c')
		counter += print_char(va_arg(args, int));
	else if (symbol == 's')
		counter += print_str(va_arg(args, char *));
	else if (symbol == 'i' || symbol == 'd')
		counter += print_nbr(va_arg(args, int));
	else if (symbol == 'u')
		counter += unsigned_print_nbr(va_arg(args, unsigned int));
 	else if (symbol == 'p')
		counter += print_address(va_arg(args, unsigned long)); 
	else if (symbol == 'x' || symbol == 'X')
		counter += print_hexadecimal(va_arg(args, unsigned long), symbol);
	else
		counter += write(1, &symbol, 1);
	return (counter);
}
