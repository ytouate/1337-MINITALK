/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:05:59 by ytouate           #+#    #+#             */
/*   Updated: 2022/01/31 13:23:46 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(50);
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		send_char(pid, *msg);
		msg++;
	}
	if (*msg == '\0')
		send_char(pid, '\0');
}

int	check_arg(char *s)
{
	while (*s)
	{
		if (!(*s <= '9' && *s >= '0'))
			return (0);
		s++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*msg;
	int		pid;

	if (ac == 3)
	{
		msg = av[2];
		if (check_arg(av[1]))
		{
			pid = ft_atoi(av[1]);
			send_msg(pid, msg);
		}
		else
		{
			ft_putstr("INVALID PID\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr("INVALID ARGUMENTS");
		exit(EXIT_FAILURE);
	}
}
