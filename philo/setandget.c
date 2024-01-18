/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setandget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:14:52 by dlom              #+#    #+#             */
/*   Updated: 2024/01/19 00:16:33 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_bool(t_mtx	*mutex, bool *dest, bool value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	result;

	safe_mutex_handle(mutex, LOCK);
	result = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (result);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	result;

	safe_mutex_handle(mutex, LOCK);
	result = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (result);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->simulation_ended));
}