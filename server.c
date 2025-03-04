/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:42:40 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/04 03:49:44 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	action(int signal, siginfo_t *info, void *ucontext)
{
	static char	c=0;
	static int	bit;

	(void)ucontext;
	(void)info;
	bit++;
	write(1, &c, 1);
	if (signal == SIGUSR1)
		c = c & 0x80;
	else
		c = c >> 1;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	else
		c = c >> 1;
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
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
