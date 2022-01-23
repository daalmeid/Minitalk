# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 13:11:35 by daalmeid          #+#    #+#              #
#    Updated: 2022/01/19 13:51:54 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= client

NAME2	= server

SRCS_CLIENT	= client.c
	
SRCS_SERVER = server.c

RM = rm -f

LIBFTPRINTF = libftprintf.a

OBJS	= *.o

$(NAME1): $(LIBFTPRINTF) $(OBJS) $(NAME2)
	gcc -Werror -Wextra -Wall client.o -L. -lftprintf -o $(NAME1)

$(NAME2):
	gcc -Werror -Wextra -Wall server.o -L. -lftprintf -o $(NAME2)

$(LIBFTPRINTF):
	cd printf-main && make && mv libftprintf.a ../ && cp ft_printf.h libft/libft.h ../

$(OBJS):
	gcc -Wall -Wextra -Werror -c $(SRCS_CLIENT) $(SRCS_SERVER)

all:	$(NAME1)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME1) $(NAME2)

re:		fclean all

bonus: clean all
