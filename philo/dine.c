/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:03:09 by dlom              #+#    #+#             */
/*   Updated: 2024/01/18 00:53:43 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
- Grab the forks
- Eat
- Release the forks 
*/

static void	eat_function(t_philo *philo)
{
	safe_mutex(&philo->right_first_fork->fork, LOCK);
	output_shell(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->left_second_fork->fork, LOCK);
	output_shell(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mtx, &philo->last_meal_time, gettime(MILISECOND));
	philo->meals_eaten = philo->meals_eaten + 1;
	output_shell(EATING, philo, DEBUG_MODE);
	my_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->meals_limit > 0 && philo->meals_eaten == philo->table->meals_limit)
		set_bool(&philo->philo_mtx, &philo->estoy_lleno, true);
	safe_mutex(&philo->right_first_fork->fork, UNLOCK);
	safe_mutex(&philo->left_second_fork->fork, UNLOCK);
}

static void	think_function(t_philo *philo)
{
	output_shell(THINKING, philo, DEBUG_MODE);
}


static void	*dining(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->estoy_lleno)
			break ;
		eat_function(philo);
		output_shell(SLEEPING, philo, DEBUG_MODE);
		my_usleep(philo->table->time_to_sleep, philo->table);
		think_function(philo);
	}
	return (NULL);
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