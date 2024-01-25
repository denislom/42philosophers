/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:40:21 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:27:31 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	output_shell(t_philo_status status, t_philo *philo)
{
	long	passed;

	passed = gettime(MILISECONDS) - philo->table->start_simulation;
	if (get_bool(&philo->mutex_philo, &philo->full))
		return ;
	safe_mutex(&philo->table->write_mutex, LOCK);
	if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
		&& !simulation_finished(philo->table))
		printf("%-6ld %d has taken a fork\n", passed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is eating\n", passed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is sleeping\n", passed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld %d is thinking\n", passed, philo->id);
	else if (DIED == status)
		printf("%-6ld %d died\n", passed, philo->id);
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}
