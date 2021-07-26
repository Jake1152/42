# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 19:26:38 by jim               #+#    #+#              #
#    Updated: 2021/07/08 21:48:28 by jim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs
INCLUDES= ./libft.h
SRCS = ft_atoi.c		\
	   ft_bzero.c		\
	   ft_calloc.c		\
	   ft_isalnum.c		\
	   ft_isalpha.c		\
	   ft_isascii.c		\
	   ft_isdigit.c		\
	   ft_isprint.c		\
	   ft_memccpy.c		\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_memcpy.c		\
	   ft_memmove.c		\
	   ft_memset.c		\
	   ft_strchr.c		\
	   ft_strdup.c		\
	   ft_strlcat.c		\
	   ft_strlen.c		\
	   ft_strncmp.c		\
	   ft_strnstr.c		\
	   ft_strrchr.c		\
	   ft_tolower.c		\
	   ft_toupper.c

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
