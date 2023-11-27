/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:17:37 by dlom              #+#    #+#             */
/*   Updated: 2023/11/27 23:48:53 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (NULL == result)
		error_exit("Malloc error.");
	return (result);
}

void	safe_mutex(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		pthread_mutex_lock(mutex);
}