/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:34:15 by ytouate           #+#    #+#             */
/*   Updated: 2022/02/23 10:34:57 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchar (str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)

{
	long	i;

	i = nb;
	if (i < 0)
	{
		ft_putchar ('-');
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr (i / 10);
		ft_putnbr (i % 10);
	}
	if (i >= 0 && i <= 9)
	{
		ft_putchar (i + '0');
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 9223372036854775807)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		result = (10 * result) + str[i++] - '0';
	}
	return ((((int)result) * sign));
}