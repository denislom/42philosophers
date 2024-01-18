/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:47:25 by dlom              #+#    #+#             */
/*   Updated: 2024/01/18 18:34:43 by dlom             ###   ########.fr       */
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

	if (argc == 5 || argc == 6)
	{
		parse_arguments(&table, argv);
		initiate_data(&table);
		// start_dinner(&table);
		// free_data(&table);
	}
	else
	{
		print_error("Wrong input.\nCorrect is ./philo 5 700 200 200 [5]\n");
	}
}