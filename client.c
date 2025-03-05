/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:42:31 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/05 17:12:21 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	message(int pid)
{
	(void)pid;
	write(1, "Done!", 5);
	exit(0);
}
void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, *str);
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, message);
	pid = ft_atoi(av[1]);
	if (pid == -1)
		return (write(2, "Wrong PID", 9), 1);
	if (ac != 3)
		return (write(2, "Syntax: ./client PID \"string\"\n", 30), 1);
	send_string(pid, av[2]);
}
