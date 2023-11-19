/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:59:57 by dlom              #+#    #+#             */
/*   Updated: 2023/10/03 17:09:42 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[i] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
