/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:04:12 by dlom              #+#    #+#             */
/*   Updated: 2023/01/28 18:13:40 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
RETURN VALUE: The trimmed string.
NULL if the allocation fails.

PARAMETRES: s1: The string to be trimmed.
set: The reference set of characters to trim.

DESCRIPTION: Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		len;

	len = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (len > start && ft_strchr(set, s1[len - 1]))
		len--;
	str = malloc(sizeof(char) * (len - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len > start)
		str[i++] = s1 [start++];
	str[i] = '\0';
	return (str);
}
