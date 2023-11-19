/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:20:08 by dlom              #+#    #+#             */
/*   Updated: 2023/10/03 17:11:04 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char	*str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
/*
locates the first occurence of a specific character in a strig
takes two argument: the string to search in and the character to search for
RETURNS a pointer to the first occurence of the character or NULL if
the character is not found.
*/

/*
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}
*/
// char	*ft_strchr(const char *s, int c)
// {
// 	const char	*ptr;
// 	int			i;

// 	if (s == NULL)
// 		return (NULL);
// 	i = 0;
// 	ptr = s;
// 	while (ptr[i])
// 	{
// 		if (ptr[i] == (char) c)
// 			return ((char *)&ptr[i]);
// 		i++;
// 	}
// 	if ((char) c == ptr[i])
// 		return ((char *)&ptr[i]);
// 	return (NULL);
// }

/*
RETURN VALUE: 
The new string.
NULL if the allocation fails.

PARAMETRES: 
s1: The prefix string.
s2: The suffix string.

DESCRIPTION:
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		len1;
// 	int		len2;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	str = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[i - len1])
// 	{
// 		str[i] = s2[i - len1];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	if (s1 == NULL)
// 	{
// 		s1 = (char *)malloc(sizeof(char));
// 		s1[i] = '\0';
// 	}
// 	if (s2 == NULL)
// 		return (NULL);
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[j] != '\0')
// 		str[i++] = s1[j++];
// 	free(s1);
// 	j = 0;
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	return (str);
// }
