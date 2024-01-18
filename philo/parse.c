/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:18:25 by dlom              #+#    #+#             */
/*   Updated: 2024/01/18 18:24:41 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error("Only positive values are possible.");
	if (!is_digit(*str))
		print_error("The input is not a correct digit");
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		print_error("INT_MAX is the limit");
	return (number);
}


static long	ft_atol(const char *str)
{
	long	number;

	number = 0;
	str = valid_input(str);
	while (is_digit(*str))
		number = (number * 10) + (*str++ - '0');
	if (number > INT_MAX)
		print_error("INT_MAX is the limit.");
	return (number);
}

void	parse_arguments(t_table *table, char **argv)
{
	table->number_of_philosophers = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	printf("table->number_of_philosophers: %ld\n", table->number_of_philosophers);
	printf("table->time_to_die: %ld\n", table->time_to_die);
	printf("table->time_to_eat: %ld\n", table->time_to_eat);
	printf("table->time_to_sleep: %ld\n", table->time_to_sleep);
	if (table->time_to_die < 60000
		|| table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		print_error("2nd, 3rd and 4th argument must be > 60.");
	if (argv[5])
		table->times_philo_must_eat = ft_atol(argv[5]);
	else
		table->times_philo_must_eat = -42;
	printf("table->times_philo_must_eat %ld\n", table->times_philo_must_eat);
}