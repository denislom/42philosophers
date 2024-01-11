/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:20:35 by dlom              #+#    #+#             */
/*   Updated: 2024/01/11 22:30:28 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Retrieves the current time in seconds, milliseconds or microseconds)
*/

long	gettime(t_time	time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Function gettimeof day failed.");
	if (SECOND == time)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILISECOND == time)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == time)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("Gettime got wrong input.");
	return (42);
}

void	my_usleep(long	microsec, t_table	*table)
{
	long	start;
	long	passed;
	long	remain;

	start = gettime(MICROSECOND);
	while (gettime(MICROSECOND) - start < microsec)
	{
		if (simulation_finished(table))
			break ;
		passed = gettime(MICROSECOND) - start;
		remain = microsec - passed;
		if (remain > 1e3)
			usleep(microsec / 2);
		else
		{
			while (gettime(MICROSECOND) - start < microsec)
				;
		}
	}
}
