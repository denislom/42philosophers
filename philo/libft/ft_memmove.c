/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:06 by dlom              #+#    #+#             */
/*   Updated: 2023/01/21 14:11:36 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*t_dest;
	const char	*t_src;

	t_dest = dest;
	t_src = src;
	if (t_dest == t_src)
		return (dest);
	else if (t_dest < t_src)
	{
		while (n--)
		{
			*t_dest++ = *t_src++;
		}
	}
	else
	{
		while (n--)
		{
			t_dest[n] = t_src[n];
		}
	}
	return (dest);
}
