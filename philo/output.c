/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:40:21 by dlom              #+#    #+#             */
/*   Updated: 2024/01/13 00:22:55 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	output_shell(t_philo_status, t_philo *philo)
{
	safe_mutex(&philo->table->write_mutex, LOCK);
	// 
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}