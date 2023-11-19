/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:15:09 by dlom              #+#    #+#             */
/*   Updated: 2023/09/15 02:18:41 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
uintptr_t is an unsigned integer type that is capable of holding a pointer
value, which means it can store the memory address of an object in the 
system's address space.
Necessary to include # include <stdint.h>

*/

static	int	hexa_pointer_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static char	*hexa_itoa_p(uintptr_t num)
{
	int					len;
	char				*ptr_num;
	int					nb;

	len = hexa_pointer_len(num);
	ptr_num = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr_num)
		return (0);
	ptr_num[len] = '\0';
	while (num != 0)
	{
		nb = num % 16;
		if (nb < 10)
			ptr_num[len - 1] = nb + '0';
		else
			ptr_num[len - 1] = nb + 87;
		num /= 16;
		len--;
	}
	return (ptr_num);
}

int	ft_print_pointer(uintptr_t num)
{
	int		printed_chars;
	char	*ptr;

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ptr = hexa_itoa_p(num);
	printed_chars = ft_putstr(ptr) + 2;
	free(ptr);
	return (printed_chars);
}
