# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 16:48:15 by daalmeid          #+#    #+#              #
#    Updated: 2022/05/03 14:45:21 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################## Program #################

NAME1	= client

NAME2	= server

################## COLORS ##################

--GRN	=		\033[32m
--RED	=		\033[31m
--WHT	=		\033[39m

################## TERMINAL ################

RM		=		rm -f

################## COMPILER ################

CC		=		cc
CFLAGS	=		-Wall -Werror -Wextra

################## FILES ###################

SRC_CLT	=		srcs/client.c\
				srcs/minitalk_utils.c

SRC_SVR	=		srcs/server.c\
				srcs/minitalk_utils.c

OBJ_CLT	=		$(SRC_CLT:.c=.o)

OBJ_SVR	=		$(SRC_SVR:.c=.o)

LIB_DIR	= 		-L./ft_printf
LIBS	=		-lftprintf

################## RULES ###################

all: $(NAME1) $(NAME2)

$(NAME1): libftprintf $(OBJ_CLT)
	$(CC) $(CFLAGS) $(OBJ_CLT) -o $(NAME1) $(LIB_DIR) $(LIBS)

$(NAME2): libftprintf $(OBJ_SVR)
	$(CC) $(CFLAGS) $(OBJ_SVR) -o $(NAME2) $(LIB_DIR) $(LIBS)

libftprintf:
	cd ft_printf && make

################## CLEAN ###################

clean:
	cd ft_printf && make clean
	$(RM) $(OBJ_CLT) $(OBJ_SVR)

fclean: clean
	cd ft_printf && make fclean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re libftprintf