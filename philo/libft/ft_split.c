/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:06:18 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 21:36:13 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
RETURNs The array of new strings resulting from the split.
NULL if the allocation fails.

PARAMETRES: s: The string to be split.
c: The delimiter character.

DESCRIPTION:
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

/*
First we count the number of words in s
Then we allocate memory for an array of strings
to hold the resulting split words

Then we iterate through the s, copy each character (except of c),
we add a null character (\0) at the of each word

At the end we assign NULL pointer to last index of the result array.

And we free the allocated memory to avoid memory leaks.
*/

/* static int	ft_count_words(char const *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

static int	ft_word_size(char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] != c && s[size])
	{
		size++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

static char	**ft_fill(char **new, const char *str, char c, int count)
{
	int	words;
	int	len;
	int	i;

	i = 0;
	words = 0;
	while (words < count)
	{
		while (str[i] == c)
			i++;
		len = ft_word_size(&str[i], c);
		new[words] = ft_substr(str, i, len);
		if (!new[words])
		{
			ft_free(new, words);
			return (NULL);
		}
		while (str[i] && str[i] != c)
			i++;
		words++;
	}
	new[words] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**new;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	new = malloc((count + 1) * sizeof(char **));
	if (!new)
		return (NULL);
	return (ft_fill(new, s, c, count));
} */

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator)
			str++;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *s, char c)
{
	char	**vector_strings;
	int		words_number;
	int		i;

	i = 0;
	words_number = count_words(s, c);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (vector_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (vector_strings[i] == NULL)
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(s, c);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
