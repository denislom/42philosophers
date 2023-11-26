/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:47:25 by dlom              #+#    #+#             */
/*   Updated: 2023/11/26 22:50:27 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
SOURCES:
https://suspectedoceano.notion.site/Philosophers-b1bf3c57eee6420cafa7d0900b3d3216
Oceano:
https://www.youtube.com/watch?v=zOpzGHwJ3MU&t=798s
https://medium.com/@jalal92/the-dining-philosophers-7157cc05315 
https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/
Threads CodeVault:
https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

./philo 5 800 200 200 [5]
./philo {number_of_philosophers} {time_to_die} {time_to_eat} {time_to_sleep} 
		[number_of_times_each_philosopher_must_eat]
*/

int	main(int argc, char **argv)
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		// errors checking, filling table
		parse_input(&table, argv);
		//creat the stuff
		//data_init(&table);
		//dinner_start(&table);
		//treat the leaks -> pilos full | 1 philo died
		//clean(&table);
	}
	else
		error_exit("Wrong input\n"
			G"Correct is ./philo 5 800 200 [5]"RST);
	return (0);
}

/* 
void	*routine()
{
	ft_printf("Test from threads\n");
	sleep(3);
	ft_printf("Ending thread.\n");	
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;


	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)  // to wait for the thread, as wait for process
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	return (0);
} 
*/
