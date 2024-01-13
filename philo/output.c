/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:40:21 by dlom              #+#    #+#             */
/*   Updated: 2024/01/13 21:34:39 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	debug_output(t_philo_status status, t_philo *philo,
		long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf(W"%6ld"RST" %d has taken the first fork"
			"\t\t\tn°"B"[🍴 %d 🍴]\n"RST, elapsed, philo->id,
			philo->right_first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf(W"%6ld"RST" %d has taken the second fork"
			"\t\t\tn°"B"[🍴 %d 🍴]\n"RST, elapsed, philo->id,
			philo->left_second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf(W"%6ld"C" %d is eating"
			"\t\t\t"Y"[🍝 %ld 🍝]\n"RST, elapsed, philo->id, philo->meals_eaten);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf(W"%6ld"RST" %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf(W"%6ld"RST" %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf(RED"\t\t💀💀💀 %6ld %d died   💀💀💀\n"RST, elapsed, philo->id);
}

void	output_shell(t_philo_status status, t_philo *philo, bool debug)
{
	long	passed;

	passed = gettime(MILISECOND);
	if (philo->estoy_lleno)
		return ;
	safe_mutex(&philo->table->write_mutex, LOCK);
	if (debug)
		debug_output(status, philo, passed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_FIRST_FORK == status)
			&& !simulation_finished(philo->table))
			printf("W%-6ld"RST" %d has taken a fork\n", passed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf(W"%-6ld"C" %d is eating\n"RST, passed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf(W"%-6ld"C" %d is thinking\n"RST, passed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf(W"%-6ld"C" %d is sleeping\n"RST, passed, philo->id);
		else if (DIED == status && !simulation_finished(philo->table))
			printf(RED"%-6ld"C" %d died\n"RST, passed, philo->id);
	}
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}