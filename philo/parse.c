/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:18:25 by dlom              #+#    #+#             */
/*   Updated: 2023/11/23 01:20:27 by dlom             ###   ########.fr       */
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

static const char *valid_input(const char	*str)
{
	int	len;
	
}

static long	ft_atol(const char *str)
{
	long	nbr;

	nbr = 0;
	str = valid_input(str);
}

void	parse_input(t_table	*table, char **argv)
{

}
