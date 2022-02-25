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

SERVER = server
CLIENT = client
CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs
INCLUDES= ./process_communication.h
SRC_SERV = server.c			\
			process_utils.c	\
			error_handler.c	\
			utils.c			\
			ft_putnbr_fd.c

SRC_CLIENT = client.c		\
		process_utils.c	\
		error_handler.c	\
		utils.c			\
		ft_putnbr_fd.c

SRC_SERV_BONUS = server_bonus.c		\
			process_utils_bonus.c	\
			error_handler_bonus.c	\
			utils_bonus.c			\
			ft_putnbr_fd_bonus.c

SRC_CLIENT_BONUS = client_bonus.c	\
		process_utils_bonus.c		\
		error_handler_bonus.c		\
		utils_bonus.c				\
		ft_putnbr_fd_bonus.c

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

SERV_OBJS = $(SRC_SERV:.c=.o) 
CLIENT_OBJS = $(SRC_CLIENT:.c=.o)

SERV_OBJS_BONUS = $(SRC_SERV:.c=.o) 
CLIENT_OBJS_BONUS = $(SRC_CLIENT:.c=.o)

$(SERVER) = $(SERV_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(CLIENT) = $(CLIENT_OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(SERVER_BONUS) = $(SERV_OBJS_BONUS)
	$(AR) $(ARFLAGS) $@ $^

$(CLIENT_BONUS) = $(CLIENT_OBJS_BONUS)
	$(AR) $(ARFLAGS) $@ $^

all : $(SERVER) $(CLIENT)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony: all clean fclean re