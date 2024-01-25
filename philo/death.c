/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:36:45 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:23:02 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philo_died(t_philo *philo)
{
	long	passed;
	long	t_to_die;

	if (get_bool(&philo->mutex_philo, &philo->full))
		return (false);
	passed = gettime(MILISECONDS) - get_long(&philo->mutex_philo,
			&philo->last_time_ate);
	t_to_die = philo->table->time_to_die / 1e3;
	if (passed > t_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int			i;
	t_table		*table;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex,
			&table->q_running_threads, table->number_of_philosophers))
		;
	while (!simulation_finished(table))
	{	
		i = -1;
		while (++i < table->number_of_philosophers && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->simulation_ended, true);
				output_shell(DIED, table->philos + i);
			}
		}
	}
	return (NULL);
}
