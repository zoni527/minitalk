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

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (write_error_return_int("Wrong number of arguments", EXIT_FAILURE));
	ft_printf("I am the client\n");
	kill(ft_atol(argv[1]), SIGKILL);
	return (0);
}
