# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 19:26:38 by jim               #+#    #+#              #
#    Updated: 2021/09/13 21:37:58 by jim              ###   ########seoul.kr   #
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
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_memcpy.c		\
	   ft_memmove.c		\
	   ft_memset.c		\
	   ft_strchr.c		\
	   ft_strdup.c		\
	   ft_strlcat.c		\
	   ft_strlcpy.c		\
	   ft_strlen.c		\
	   ft_strncmp.c		\
	   ft_strnstr.c		\
	   ft_strrchr.c		\
	   ft_tolower.c		\
	   ft_toupper.c		\
	   ft_putchar_fd.c	\
       ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\
	   ft_putstr_fd.c	\
	   ft_substr.c		\
	   ft_strjoin.c		\
	   ft_split.c		\
	   ft_itoa.c		\
	   ft_strtrim.c		\
	   ft_strmapi.c		\
	   ft_striteri.c

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
