/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:13:01 by dlom              #+#    #+#             */
/*   Updated: 2023/01/29 20:13:01 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION: Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

PARAMETRES: n - the integer to convert.

RETURNs the string representing the integer.
NULL if the allocation fails.
*/
int	ft_n_len(int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		length++;
		num = num * (-1);
	}
	while (num > 0)
	{
		length++;
		num = num / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	m;

	len = ft_n_len(n);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	m = n;
	if (m < 0)
	{
		ptr[0] = '-';
		m = m * (-1);
	}
	ptr[len] = '\0';
	len--;
	if (m == 0)
		ptr[0] = '0';
	while (m)
	{
		ptr[len] = m % 10 + '0';
		m = m / 10;
		len--;
	}
	return (ptr);
}
