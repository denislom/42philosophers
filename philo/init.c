/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:55:12 by dlom              #+#    #+#             */
/*   Updated: 2024/01/06 15:33:13 by dlom             ###   ########.fr       */
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

static void	appoint_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
	int	philo_number;

	philo_number = philo->table->nbr_philo;
	philo->right_first_fork = &forks[(philo_pos + 1) % philo_number];
	philo->left_second_fork = &forks[philo_pos];
	if (philo->id % 2)
	{
		philo->right_first_fork = &forks[philo_pos];
		philo->left_second_fork = &forks[(philo_pos + 1) % philo_number];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nbr_philo)
	{
		philo = table->philos + i;
		philo->id = i + i;
		philo->table = table;
		philo->estoy_lleno = false;
		philo->meals_eaten = 0;
		appoint_forks(philo, table->forks, i);
	}
}

void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->simulation_end = false;
	table->threads_ready = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philo);
	safe_mutex(&table->table_mutex, INIT);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philo);
	while (++i < table->nbr_philo)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}
