/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:47:17 by dlom              #+#    #+#             */
/*   Updated: 2024/01/17 20:51:25 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <sys/time.h>

/* 
The pthread library provides the following main features and functions:

Thread Creation and Termination:
    pthread_create: Creates a new thread.
    pthread_exit: Terminates the calling thread.

Thread Synchronization:
    pthread_join: Waits for a specific thread to finish.
    pthread_detach: Detaches a thread, allowing it to run independently.
    pthread_mutex_lock and pthread_mutex_unlock: Provides mutual exclusion 
	to shared resources.

Condition Variables:
    pthread_cond_wait and pthread_cond_signal: Allows threads to wait for 
	a condition to be met.

Thread-Specific Data:
    pthread_key_create and pthread_setspecific: Enables the creation and
	use of thread-specific data.

Thread Attributes:
    pthread_attr_init and pthread_attr_set: Specifies various attributes
	when creating threads.

Scheduling:
    pthread_yield: Yields the processor to other threads.

Mutex Types:
    pthread_mutex_init with different types: Provides various types of 
	mutexes, such as normal, error-checking, and recursive.
 */

/* 
ANSI Escape Sequences for bold text colors
-> to make printf cool
 */

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

#define DEBUG_MODE	0

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

//OPCODE: mutex and thread functions

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

//get_time
typedef enum e_time
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}	t_time;

/* 
./philo 5 800 200 200 [5]
./philo {number_of_philosophers} {time_to_die} {time_to_eat} {time_to_sleep} 
		[number_of_times_each_philosopher_must_eat]

number_of_philosophers: The number of philosophers and also the number
		of forks.

time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
		milliseconds since the beginning of their last meal or the beginning 
		of the simulation, they die.

time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
		During that time, they will need to hold two forks.

time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

number_of_times_each_philosopher_must_eat (optional argument): If all
		philosophers have eaten at least number_of_times_each_philosopher_must_eat
		times, the simulation stops. If not specified, the simulation stops when a
		philosopher dies.
*/

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_eaten;
	bool		estoy_lleno;
	long		last_meal_time;
	t_fork		*right_first_fork;
	t_fork		*left_second_fork;
	pthread_t	thread_id;
	t_table		*table;
	t_mtx		philo_mtx;
}	t_philo;

// ./philo 5 800 200 200 [5]
/* 
simulation_start:
simulation_end: a philo dies or all philos are llenos
*/

struct s_table
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	long	simulation_start;
	bool	simulation_end;
	bool	threads_ready;
	t_fork	*forks;
	t_philo	*philos;
	t_mtx	table_mutex;
	t_mtx	write_mutex;
};

//error_handling.c
void	error_exit(const char *error);

//parse.c
void	parse_input(t_table	*table, char **argv);

//init.c
void	data_init(t_table *table);

//safe_func.c
void	*safe_malloc(size_t bytes);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
void	safe_thread(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode opcode);

//dine.c
void	*dining(void *data);
void	start_dining(t_table *table);

//setandget.c
void	set_bool(t_mtx	*mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
long	get_long(t_mtx *mutex, long *value);
void	set_long(t_mtx *mutex, long *dest, long value);
bool	simulation_finished(t_table *table);

//mon_and_synchro_utils.c 
void	wait_threads(t_table *table);

//time_utils.c
long	gettime(t_time	time);
void	my_usleep(long	microsec, t_table	*table);

//output.c
void	output_shell(t_philo_status status, t_philo *philo, bool debug);

#endif