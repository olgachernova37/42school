/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:36:09 by emarko            #+#    #+#             */
/*   Updated: 2024/06/06 19:14:03 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	in_word;
	size_t	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*ft_find_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = start;
	while (i < end)
	{
		word[i - start] = s[i];
		i++;
	}
	word[i - start] = '\0';
	return (word);
}

static char	**ft_put_words(char **words_arr, char const *s, char c)
{
	size_t	i;
	int		start;
	size_t	j;

	start = -1;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start != -1)
		{
			if (s[i] == c)
				words_arr[j++] = ft_find_word(s, start, i);
			else
				words_arr[j++] = ft_find_word(s, start, i + 1);
			start = -1;
		}
		i++;
	}
	words_arr[j] = NULL;
	return (words_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**words_arr;
	int		words_count;

	if (!c && !s)
		return (NULL);
	words_count = ft_word_count(s, c);
	words_arr = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!words_arr)
		return (NULL);
	words_arr = ft_put_words(words_arr, s, c);
	return (words_arr);
}
