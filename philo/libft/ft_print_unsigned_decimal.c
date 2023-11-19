/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:24:40 by dlom              #+#    #+#             */
/*   Updated: 2023/09/15 02:18:52 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int can hold values from -2^31 to -2^31-1 = 2.147.483.647
unsigned int can hold values from 0 t 2^32-1 = 4.294.967.295
*/
static int	unum_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*unsigned_itoa(unsigned int num)
{
	int		len;
	char	*number;

	len = unum_len(num);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (0);
	number[len] = '\0';
	while (num != 0)
	{
		number[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (number);
}

int	ft_print_unsigned_decimal(unsigned int num)
{
	int		printed_chars;
	char	*temp;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		temp = unsigned_itoa(num);
		printed_chars = ft_putstr(temp);
		free(temp);
	}
	return (printed_chars);
}
