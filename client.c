/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:42:31 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/08 17:23:36 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_bit_received = 0;

void	acknowledge(int signal)
{
	if (signal == SIGUSR1)
		g_bit_received = 1;
	else
	{
		write(1, "Done!\n", 6);
		exit(0);
	}
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_bit_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while (!g_bit_received)
			pause();
	}
}

void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	signal(SIGUSR2, acknowledge);
	if (ac != 3)
		return (write(2, "Syntax: ./client PID \"string\"\n", 30), 1);
	pid = ft_atoi(av[1]);
	if (pid == -1 || kill(pid, 0) == -1)
		return (write(2, "Wrong PID", 9), 1);
	sa.sa_handler = acknowledge;
	sa.sa_flags = SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_string(pid, av[2]);
	return (0);
}
