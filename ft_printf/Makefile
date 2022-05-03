# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 18:12:17 by daalmeid          #+#    #+#              #
#    Updated: 2022/05/03 14:33:01 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_put_nbr_str_ptr.c ft_putnbr_un.c ft_putnbr_base.c ft_printf.c\
	

SRCS_BONUS	= ft_put_nbr_str_ptr.c ft_putnbr_un.c ft_putnbr_base.c\
		ft_printf_bonus.c ft_isalpha.c ft_putchar_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_atoi.c ft_bzero.c\
		ft_isdigit.c ft_substr.c

OBJS	= *.o

RM = rm -f

LIBFT = libft.a

$(NAME): $(LIBFT) $(OBJS)
	mv libft.a $(NAME) && ar rc $(NAME) $(OBJS)

$(OBJS):
	gcc -Wall -Wextra -Werror -c $(SRCS)

$(LIBFT):
	cd libft/ && make && mv libft.a ../
	
all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

bonus: clean
	gcc -Wall -Wextra -Werror -c $(SRCS_BONUS)
	ar rc $(NAME) $(OBJS)
