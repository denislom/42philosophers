/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:47:25 by dlom              #+#    #+#             */
/*   Updated: 2023/11/20 00:17:06 by dlom             ###   ########.fr       */
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

*/

void *routine()
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
		return (1);
	pthread_join(t1, NULL); // to wait for the thread, as wait for process
	pthread_join(t2, NULL);
	return (0);
}
