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
	sigset_t			set;
	struct sigaction	act;

	pid = getpid();
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act = (struct sigaction){.sa_handler = &signal_handler};
	rval = sigaction(SIGUSR1, &act, NULL);
	while (1)
	{
		ft_printf("pid %d is waiting\n", pid);
		sleep(1);
	}
	return (0);
}

void	signal_handler(int signum)
{
	ft_printf("Message from the signal handler, signum is %d\n", signum);
}
