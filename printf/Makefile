# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jim <jim@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 19:26:38 by jim               #+#    #+#              #
#    Updated: 2022/01/06 18:06:32 by jim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs
INCLUDES= ./printf.h
SRCS = ft_printf.c		\
		ft_printf_utils.c	\
		ft_print_c.c		\
		ft_print_s.c		\
		ft_print_d.c		\
		ft_print_u.c		\
		ft_print_x.c		\
		ft_print_p.c		\
		ft_print_u.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.phony: all clean fclean re