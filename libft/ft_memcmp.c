/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:54:00 by dlom              #+#    #+#             */
/*   Updated: 2023/01/25 16:54:00 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares a specified number of bztes of two memory areas
returns a negative vallue if the first vlock is
lexicographically less than second
returns 0 if two memory blocks are equal
returns a positive value if the first memory 
block is grater than second*/
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((p1[i] == p2[i]) && (i < n -1))
		i++;
	return (p1[i] - p2[i]);
}
