/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:47:14 by dlom              #+#    #+#             */
/*   Updated: 2023/01/22 22:47:14 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
locates the first occurence of a specific character in a strig
takes two argument: the string to search in and the character to search for
RETURNS a pointer to the first occurence of the character or NULL if
the character is not found.
*/
char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = s;
	while (ptr[i])
	{
		if (ptr[i] == (char) c)
			return ((char *)&ptr[i]);
		i++;
	}
	if ((char) c == ptr[i])
		return ((char *)&ptr[i]);
	return (NULL);
}
