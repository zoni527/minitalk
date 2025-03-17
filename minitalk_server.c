/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:28:59 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/07 09:29:10 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum);

volatile int	sig;

int	main(void)
{
	pid_t				pid;
	int					rval;
	struct sigaction	act;
	sigset_t			set;
	int					bits_received;
	char				c;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	pid = getpid();
	act.sa_handler = &signal_handler;
	rval = sigaction(SIGUSR1, &act, NULL);
	rval = sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server pid: %d\n", pid);
	bits_received = 0;
	c = 0;
	sig = -1;
	while (1)
	{
		if (bits_received == 8)
		{
			bits_received = 0;
			ft_printf("%c", c);
			c = 0;
		}
		if (sig == 0)
		{
			bits_received++;
			c <<= 1;
			sig = -1;
		}
		else if (sig == 1)
		{
			bits_received++;
			c = (c << 1) | 1;
			sig = -1;
		}
		else
			usleep(500);
	}
	return (0);
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		sig = 0;
	if (signum == SIGUSR2)
		sig = 1;
}
