/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:26:55 by mmravec           #+#    #+#             */
/*   Updated: 2024/08/22 11:42:21 by mmravec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_delimiter(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int		words;
	int		is_inside_word;

	words = 0;
	is_inside_word = 0;
	while (*str)
	{
		if (is_delimiter(*str, charset))
		{
			is_inside_word = 0;
		}
		else
		{
			if (!is_inside_word)
			{
				words++;
				is_inside_word = 1;
			}
		}
		str++;
	}
	return (words);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*alloc_copy_word(char *current_word, int word_length)
{
	char	*word;

	word = (char *)malloc((word_length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strncpy(word, current_word, word_length);
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*current_word;
	int		word_length;
	int		words;

	word_length = 0;
	words = 0;
	result = (char **) malloc((count_words(str, charset) + 1) * sizeof(char *));
	while (*str || word_length > 0)
	{
		if (is_delimiter(*str, charset) || *str == '\0')
		{
			if (word_length > 0)
				result[words++] = alloc_copy_word(current_word, word_length);
			word_length = 0;
		}
		else
			if (word_length++ == 0)
				current_word = str;
		str++;
	}
	result[words] = NULL;
	return (result);
}

/*#include <stdio.h>

int main(void)
{
	char	*string = ";;Hello, world... I love you!Nice;.a";
	char	*delimiters = ",;.!";
	char	**result;
	int		i;

	i = 0;
	printf("Word count: %d\n", count_words(string, delimiters));
	printf("Testing string was: %s\n", string);
	printf("Delimiters: %s\n", delimiters);
	result = ft_split(string, delimiters);
	while (i < count_words(string, delimiters))
	{
		printf("result[%d]: %s\n", i, result[i]);
		i++;
	}
}
*/
