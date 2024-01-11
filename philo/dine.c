/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:03:09 by dlom              #+#    #+#             */
/*   Updated: 2024/01/11 20:30:17 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dining(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->estoy_lleno)
			break;
		// eat(philo);
		// my_sleep(philo);
		// think(philo);
	}
	
}

void	start_dining(t_table *table)
{
	int	i;

	i = -1;
	if (0 == table->meals_limit)
		return ;
	else if (1 == table->nbr_philo)
	{
		/* code */
	}
	else
	{
		while (i++ < table->nbr_philo)
		{
			safe_thread(&table->philos[i].thread_id, dining,
				&table->philos[i], CREATE);
		}
	}
	table->simulation_start = gettime(MILISECOND);
	set_bool(&table->table_mutex, &table->threads_ready, true);
	i = -1;
	while (++i < table->nbr_philo)
		safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	
}