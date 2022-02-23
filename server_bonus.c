/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:18:20 by ytouate           #+#    #+#             */
/*   Updated: 2022/01/06 17:31:57 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	recieve(int sig)
{
	static int	i;
	static int	bit = 7;
	static char	text[MAX_CHAR];

	if (sig == SIGUSR1)
		text[i] &= ~(1 << bit);
	else
		text[i] |= (1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (text[i] == '\0')
		{
			write(1, text, i);
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid <= 0)
		exit(EXIT_FAILURE);
	ft_putstr("THE SERVER PID IS :\t");
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, recieve);
	signal(SIGUSR2, recieve);
	while (1)
	{
		pause();
	}
}
