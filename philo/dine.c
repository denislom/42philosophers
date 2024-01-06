/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:03:09 by dlom              #+#    #+#             */
/*   Updated: 2024/01/06 15:29:24 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dining(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// wait_threads(philo->table);
}

void	start_dining(t_table *table)
{
	int	i;

	i = -1;
	if (0 == table->meals_limit)
		return (0);
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
}