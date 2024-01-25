/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:17:37 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:28:57 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		print_error("Error with the malloc");
	return (ret);
}

/*
 *   HANDLING ERRORS
 *   If successful, all the mutex and thread functions 
 *   will return zero, otherwise an error number will
 *   be returned to indicate the error.
 *
 *💡 Basically i am recreating perror 💡
 *	 1) These functions don't set errno
 *	 2) We just cannot use perror
*/
static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		print_error("The value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		print_error("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		print_error("A deadlock would occur if the thread "
			"blocked waiting for mutex.");
	else if (EPERM == status)
		print_error("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		print_error("The process cannot allocate enough memory"
			" to create another mutex.");
	else if (EBUSY == status)
		print_error("Mutex is locked");
}

/*
 * THREADS errors
*/
static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		print_error("No resources to create another thread");
	else if (EPERM == status)
		print_error("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		print_error("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		print_error("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		print_error("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		print_error("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
}

/*
 * One function to handle safely
 * lock unlock init destroy
*/
void	safe_mutex(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		print_error("Wrong opcode for mutex_handle:"
			"use <LOCK> <UNLOCK> <INIT> <DESTROY>");
}

/*
 * One function to handle threads
 * create join detach
*/
void	safe_thread(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		print_error("Wrong opcode for thread_handle:"
			" use <CREATE> <JOIN> <DETACH>");
}
