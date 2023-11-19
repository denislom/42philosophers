/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:51:14 by dlom              #+#    #+#             */
/*   Updated: 2023/09/15 02:18:31 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexadecimal_len(unsigned int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		number = number / 16;
		len++;
	}
	return (len);
}

char	*hexa_itoa(unsigned int number, char format)
{
	int		len;
	char	*hexa_number;
	int		nb;

	len = hexadecimal_len(number);
	hexa_number = (char *)malloc((len + 1) * sizeof(char));
	if (!hexa_number)
		return (0);
	hexa_number[len] = '\0';
	while (number != 0)
	{
		nb = number % 16;
		if (nb < 10)
			hexa_number[len - 1] = nb + '0';
		else
			hexa_number[len - 1] = nb + format;
		number = number / 16;
		len--;
	}
	return (hexa_number);
}

int	ft_print_hexadecimal(unsigned int number, char format)
{
	int		len;
	char	*hexa_num;

	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (format == 'x')
		format = 87;
	else if (format == 'X')
		format = 55;
	hexa_num = hexa_itoa(number, format);
	len = ft_putstr(hexa_num);
	free(hexa_num);
	return (len);
}
