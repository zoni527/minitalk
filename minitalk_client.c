/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:52:51 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/07 09:53:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, int c);

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*str;

	if (argc != 3)
		return (write_error_return_int("Wrong number of arguments", EXIT_FAILURE));
	ft_printf("I am the client\n");
	server_pid = ft_atol(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_char(server_pid, *(str++));
		usleep(200);
	}
	// kill(ft_atol(argv[1]), SIGKILL);
	return (0);
}

void	send_char(pid_t pid, int c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c & (1 << (7 - i))) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
	}
}
