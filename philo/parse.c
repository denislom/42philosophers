/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:18:25 by dlom              #+#    #+#             */
/*   Updated: 2023/11/26 16:46:48 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
./philo 5 800 200 200 [5]

parse_input
- actual number, not INT_MAX,
-timestamps > 60 ms

valid_input
- check for negatives
- check if the number is valid
- check for INT_MAX, if len > 10 and then 2_147_483_647
- we return pointer to actual number

atol "alfa to long"
-

static - we use it only inside this source file
*/

static inline bool	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ')
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char *valid_input(const char	*str)
{
	int	len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Only positive values, please.");
	if (!is_digit(*str))
		error_exit("The input is not correct digit.");
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		error_exit("The value is too bigger than INT_MAX.")
	return (number);
}

static long	ft_atol(const char *str)
{
	long	nbr;

	nbr = 0;
	str = valid_input(str);
	while (is_digit(*str))
		nbr = (nbr * 10) + (*str++ - 48);
	if (nbr > INT_MAX)
		error_exit("The value is too bigger than INT_MAX.");
	return (nbr);
}

void	parse_input(t_table	*table, char **argv)
{

}
