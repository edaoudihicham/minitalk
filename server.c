/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:42:40 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/18 19:28:19 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	bit;
	static int	client_pid;

	(void)ucontext;
	if (client_pid != info->si_pid)
	{
		c = 0;
		bit = 0;
		client_pid = info->si_pid;
	}
	c = c << 1;
	if (signal == SIGUSR1)
		c = c | 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(client_pid, SIGUSR2);
		bit = 0;
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (write(2, "Syntax: ./server\n", 17), 1);
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
