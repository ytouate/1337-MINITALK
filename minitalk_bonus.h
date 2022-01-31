/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:19:24 by ytouate           #+#    #+#             */
/*   Updated: 2022/01/31 13:21:42 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define MAX_CHAR 999999999999

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s)

#endif