/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:20:48 by dlom              #+#    #+#             */
/*   Updated: 2023/02/05 13:36:36 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*RETURN VALUE: The substring.
NULL if the allocation fails

PARAMETRES: 
s: The string from which to create the substring.
start: The start index of the substring in the
string ’s’.
len: The maximum length of the substring

DESCRIPTION:
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned int		i;

	if ((size_t)start + len > (size_t)ft_strlen(s))
		len = ft_strlen(s) - (size_t)start;
	if ((size_t)start >= (size_t)ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < (unsigned int) len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
