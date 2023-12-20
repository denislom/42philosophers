/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:18:25 by dlom              #+#    #+#             */
/*   Updated: 2023/12/20 23:32:16 by dlom             ###   ########.fr       */
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
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
	static const char *valid_input(const char	*str);
	static: accessible only within this source file (internal linkage)
	RETURNs pointer to a constant character
	1) ignores the spaces in the begining (chars \t to \r)
	2) ignores + sign
	3) if is negatives -> error_exit
	4) checks if the string consists only of the digits
	5) checks if the len of str  <= 10 (INT_MAX)
*/

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
		error_exit("The value is too bigger than INT_MAX.");
	return (number);
}

/*
	static long	ft_atol(const char *str);
	static: accessible only within this source file (internal linkage)
	converts ASCII (string) to long
	checks if number is bigger than INT_MAX (for ex. if len of str is 10)
*/

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

/*
	void	parse_input(t_table	*table, char **argv);
	- Parses command-line arguments and puts those 
	  values in t_table structure.
	  
struct s_table
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	long	simulation_start;
	bool	simulation_end;
	t_fork	*forks;
	t_philo	*philos;
};
*/

void	parse_input(t_table	*table, char **argv)
{
	table->nbr_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 60e3
		|| table->time_to_eat < 60e3
		|| table->time_to_sleep < 60e3)
		error_exit("Timestamps must be major than 60ms.");
	if (argv[5])
		table->meals_limit = ft_atol(argv[5]);
	else
		table->meals_limit = -1;
}
