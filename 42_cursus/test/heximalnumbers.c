int	print_hexadecimal(unsigned long nbr, char symbol)
{
	char	res[40];
	int		i;
  int count;

	count = 0;
  if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 35;
	res[i] = '\0';
	i--;
	while (nbr != 0)
	{
		if (symbol == 'x')
			res[i] = "0123456789abcdef"[nbr % 16];
		else
			res[i] = "0123456789ABCDEF"[nbr % 16];
		nbr /= 16;
		i--;
	}
	i++;
	while (res[i] != '\0')
	{
		count += write(1, &res[i], 1);
		i++;
	}
	return (count);
}

