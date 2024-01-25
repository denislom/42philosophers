/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:55:12 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:25:59 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	appoint_forks(t_philo *philo, t_fork *forks,
		int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->number_of_philosophers;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}	
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->number_of_philosophers)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->counter_eaten = 0;
		safe_mutex(&philo->mutex_philo, INIT);
		philo->table = table;
		appoint_forks(philo, table->forks, i);
	}
}

void	initiate_data(t_table *table)
{
	int		i;

	i = -1;
	table->simulation_ended = false;
	table->threads_are_ready = false;
	table->q_running_threads = 0;
	table->philos = safe_malloc(table->number_of_philosophers * sizeof(t_philo));
	table->forks = safe_malloc(table->number_of_philosophers * sizeof(t_fork));
	safe_mutex(&table->write_mutex, INIT);
	safe_mutex(&table->table_mutex, INIT);
	while (++i < table->number_of_philosophers)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}

