/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:03:09 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:24:16 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		output_shell(THINKING, philo);
	if (philo->table->number_of_philosophers % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	my_usleep(t_think * 0.42, philo->table);
}

void	*only_one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_threads(philo->table);
	set_long(&philo->mutex_philo, &philo->last_time_ate, gettime(MILISECONDS));
	increase_long(&philo->table->table_mutex,
		&philo->table->q_running_threads);
	output_shell(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->table))
		my_usleep(200, philo->table);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork, LOCK);
	output_shell(TAKE_FIRST_FORK, philo);
	safe_mutex(&philo->second_fork->fork, LOCK);
	output_shell(TAKE_SECOND_FORK, philo);
	set_long(&philo->mutex_philo, &philo->last_time_ate, gettime(MILISECONDS));
	philo->counter_eaten++;
	output_shell(EATING, philo);
	my_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->times_philo_must_eat > 0
		&& philo->counter_eaten == philo->table->number_of_philosophers)
		set_bool(&philo->mutex_philo, &philo->full, true);
	safe_mutex(&philo->first_fork->fork, UNLOCK);
	safe_mutex(&philo->second_fork->fork, UNLOCK);
}

static void	*dinner_simulation(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	set_long(&philo->mutex_philo, &philo->last_time_ate,
		gettime(MILISECONDS));
	increase_long(&philo->table->table_mutex,
		&philo->table->q_running_threads);
	fairly_synchronize_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->mutex_philo, &philo->full))
			break ;
		eat(philo);
		output_shell(SLEEPING, philo);
		my_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo, false);
	}
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int			i;

	i = -1;
	if (0 == table->times_philo_must_eat)
		return ;
	else if (1 == table->number_of_philosophers)
		safe_thread(&table->philos[0].thread_id, only_one_philo,
			&table->philos[0], CREATE);
	else
		while (++i < table->number_of_philosophers)
			safe_thread(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	safe_thread(&table->monitor, monitor_dinner, table, CREATE);
	table->start_simulation = gettime(MILISECONDS);
	set_bool(&table->table_mutex, &table->threads_are_ready, true);
	i = -1;
	while (++i < table->number_of_philosophers)
		safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->simulation_ended, true);
	safe_thread(&table->monitor, NULL, NULL, JOIN);
}
