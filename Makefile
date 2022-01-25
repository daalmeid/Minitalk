# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 13:11:35 by daalmeid          #+#    #+#              #
#    Updated: 2022/01/25 14:10:46 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= client

NAME2	= server

SRCS	= client.c minitalk_utils.c server.c

RM = rm -f

LIBFTPRINTF = libftprintf.a

OBJS	= *.o

GCC		= gcc -Werror -Wextra -Wall

$(NAME1): $(LIBFTPRINTF) $(OBJS) $(NAME2)
	$(GCC) client.o minitalk_utils.o -L. -lftprintf -o $(NAME1)

$(NAME2):
	$(GCC) server.o minitalk_utils.o -L. -lftprintf -o $(NAME2)

$(LIBFTPRINTF):
	cd ft_printf && make && mv libftprintf.a ../ && cp ft_printf.h libft/libft.h ../

$(OBJS):
	$(GCC)  -c $(SRCS)

all:	$(NAME1)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME1) $(NAME2)

re:		fclean all

bonus: clean all
