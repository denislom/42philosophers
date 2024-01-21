/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:20:35 by dlom              #+#    #+#             */
/*   Updated: 2024/01/21 23:15:45 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	gettime(t_time time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error("C function gettimeofday failed");
	if (MILISECOND == time)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (MICROSECOND == time)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (SECOND == time)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else
		print_error("Wrong input to gettime:"
			"use <MILLISECOND> <MICROSECOND> <SECONDS>");
	return (42);
}

void	my_usleep(long usec, t_table *table)
{
	long	start;
	long	passed;
	long	remain;

	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < usec)
	{
		if (simulation_finished(table))
			break ;
		passed = gettime(MICROSECOND) - start;
		remain = usec - passed;
		if (remain > 1e3)
			usleep(remain / 2);
		else
			while (gettime(MICROSECOND) - start < usec)
				;
	}
}