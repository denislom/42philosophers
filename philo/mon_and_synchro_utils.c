/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon_and_synchro_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:47:32 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:27:02 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	increase_long(t_mtx *mutex, long *value)
{	
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}

void	wait_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->threads_are_ready))
		;
}

void	fairly_synchronize_philos(t_philo *philo)
{
	if (philo->table->number_of_philosophers % 2 == 0)
	{
		if (philo->id % 2 == 0)
			my_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}	

bool	all_threads_running(t_mtx *mutex, long *threads,
		long philo_nbr)
{
	bool	ret;

	ret = false;
	safe_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	safe_mutex(mutex, UNLOCK);
	return (ret);
}
