/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:03:09 by dlom              #+#    #+#             */
/*   Updated: 2024/01/21 23:39:11 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	think(t_philo *philo)
{
	output_shell(THINKING, philo);
}

// void	*lone_philo(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	wait_all_threads(philo->table);
// 	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
// 	increase_long(&philo->table->table_mutex,
// 		&philo->table->threads_running_nbr);
// 	output_shell(TAKE_FIRST_FORK, philo, DEBUG_MODE);
// 	while (!simulation_finished(philo->table))
// 		precise_usleep(200, philo->table);
// 	return (NULL);
// }

static void	eat(t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork, LOCK);
	output_shell(TAKE_FIRST_FORK, philo);
	safe_mutex(&philo->second_fork->fork, LOCK);
	output_shell(TAKE_SECOND_FORK, philo);
	set_long(&philo->mutex_philo, &philo->last_time_ate, gettime(MILISECOND));
	philo->counter_eaten++;
	output_shell(EATING, philo);
	my_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->times_philo_must_eat > 0
		&& philo->counter_eaten == philo->table->times_philo_must_eat)
		set_bool(&philo->mutex_philo, &philo->full, true);
	safe_mutex(&philo->first_fork->fork, UNLOCK);
	safe_mutex(&philo->second_fork->fork, UNLOCK);
}


static void	*dinner_simulation(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	// // set_long(&philo->philo_mutex, &philo->last_meal_time,
	// set_long(&philo->mutex_philo, &philo->last_time_ate,
	// 	gettime(MILISECOND));
	// increase_long(&philo->table->table_mutex,
	// 	&philo->table->q_running_threads);
	// de_synchronize_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->mutex_philo, &philo->full))
			break ;
		eat(philo);
		output_shell(SLEEPING, philo);
		my_usleep(philo->table->time_to_sleep, philo->table);
		think(philo);
	}
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (0 == table->times_philo_must_eat)
		return ;
	// else if (1 == table->number_of_philosophers)
	// 	safe_thread(&table->philos[0].thread_id, lone_philo,
	// 		&table->philos[0], CREATE);
	else
		while (++i < table->number_of_philosophers)
			safe_thread(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	// safe_thread(&table->monitor, monitor_dinner, table, CREATE);
	table->start_simulation = gettime(MILISECOND);
	set_bool(&table->table_mutex, &table->threads_are_ready, true);
	i = -1;
	while (++i < table->number_of_philosophers)
		safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	// set_bool(&table->table_mutex, &table->simulation_ended, true);
	// safe_thread(&table->monitor, NULL, NULL, JOIN);
}
