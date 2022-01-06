# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 15:59:20 by ytouate           #+#    #+#              #
#    Updated: 2022/01/06 18:51:53 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror

AR := ar -rc

RM = rm -f

FILES = ft_atoi.c ft_putchar.c ft_putstr.c ft_putnbr.c

OBJS = $(FILES:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -c $(FILES)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) client.c $(NAME) -o client
	@$(CC) $(CFLAGS) server.c $(NAME) -o server

bonus:
	@$(CC) $(CFLAGS) -c $(FILES)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) client_bonus.c $(NAME) -o client_bonus
	@$(CC) $(CFLAGS) server_bonus.c $(NAME) -o server_bonus

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM)  $(NAME) client server client_bonus server_bonus

re : fclean all