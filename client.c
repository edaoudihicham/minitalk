/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaoudi <hdaoudi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:42:31 by hdaoudi           #+#    #+#             */
/*   Updated: 2025/03/04 03:46:27 by hdaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sleep(1);
		i++;
	}
}
void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (write(2, "Syntax: ./client PID \"string\"\n", 30), 1);
	send_string(ft_atoi(av[1]), av[2]);
}
