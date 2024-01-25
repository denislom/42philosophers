/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:20:35 by dlom              #+#    #+#             */
/*   Updated: 2024/01/25 21:04:19 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	gettime(int time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error("Function gettimeofday failed");
	if (MILISECONDS == time_code)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (MICROSECONDS == time_code)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (SECONDS == time_code)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else
		print_error("Wrong input to the function gettime:"
			"use <MILISECONDS> <MICROSECONDS> <SECONDS>");
	return (42);
}

void	my_usleep(long usec, t_table *table)
{
	long	start;
	long	passed;
	long	remain;

	start = gettime(MICROSECONDS);
	while (gettime(MICROSECONDS) - start < usec)
	{
		if (simulation_finished(table))
			break ;
		passed = gettime(MICROSECONDS) - start;
		remain = usec - passed;
		if (remain > 1e3)
			usleep(remain / 2);
		else
			while (gettime(MICROSECONDS) - start < usec)
				;
	}
}
