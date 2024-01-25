/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:47:17 by dlom              #+#    #+#             */
/*   Updated: 2024/01/24 23:21:52 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <unistd.h>	// usleep, sleep
# include <sys/time.h>	// gettimeofday
# include <pthread.h>	//mutex: init-destroy-lock-unlock,
						//threads: create-join-detach
# include <stdbool.h>
# include <stdint.h>

# include <string.h>
# include <limits.h>	//INT_MAX
# include <errno.h>
# include <sys/wait.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200 
# endif

// enums

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}			t_philo_status;

typedef enum e_time_code
{
	SECONDS,
	MILISECONDS,
	MICROSECONDS,
}		t_time_code;


typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

// STRUCTURES

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int				id;
	bool			full;
	long			counter_eaten;
	long			last_time_ate;
	pthread_t		thread_id;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_mtx			mutex_philo;
	t_table			*table;
}				t_philo;

struct	s_table
{
	long				number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				times_philo_must_eat;
	long				start_simulation;
	bool				simulation_ended;
	bool				threads_are_ready;
	long				q_running_threads;
	pthread_t			monitor;
	t_fork				*forks;
	t_philo				*philos;
	t_mtx				table_mutex;
	t_mtx				write_mutex;
};

//function prototypes

// //safe_func.
void	safe_thread(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode opcode);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
void	*safe_malloc(size_t bytes);

// parse.c
void	parse_arguments(t_table *table, char **av);

// //init.c
void	initiate_data(t_table *table);

// //dine.c
void	start_dinner(t_table *table);
void	thinking(t_philo *philo, bool pre_simulation);

// //setandget.c
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
long	get_long(t_mtx *mutex, long *value);
void	set_long(t_mtx *mutex, long *dest, long value);
bool	simulation_finished(t_table *table);

// //time_utils.c
time_t	gettime(int time_code);
void	my_usleep(long usec, t_table *table);

// //error_handling.c
void	print_error(const char *error);

// //output.c
void	output_shell(t_philo_status status, t_philo *philo);

// //mon_and_synchro_utils.c
void	wait_threads(t_table *table);
void	increase_long(t_mtx *mutex, long *value);
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);
void	fairly_synchronize_philos(t_philo *philo);

// //death.c
void	*monitor_dinner(void *data);

//clean_table.c
void	clean(t_table *table);

#endif