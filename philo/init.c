/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:55:12 by dlom              #+#    #+#             */
/*   Updated: 2023/12/20 22:56:33 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
typedef struct s_table	t_table;

struct s_table
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	long	simulation_start;
	bool	simulation_end;
	t_fork	*forks;
	t_philo	*philos;
};

typedef struct s_philo
{
	int			id;
	long		meals_eaten;
	bool		estoy_lleno;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;
*/

static void	philo_init(t_table *table)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nbr_philo)
	{
		philo = table->philos + i;
		philo->id = i + i;
	}
	
}

void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->simulation_end = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philo);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philo);
	while (++i < table->nbr_philo)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}