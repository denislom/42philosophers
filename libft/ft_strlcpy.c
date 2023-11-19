/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:43:02 by dlom              #+#    #+#             */
/*   Updated: 2023/01/12 13:43:02 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Copies a source string do the destination buffer with a maximum
number of characters that can be copied.
RETURNS the number of characters in the source string.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dest [i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size != 0)
// 	{
// 		while (src[i] != '\0' && i < size - 1)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (ft_strlen(src));
// }