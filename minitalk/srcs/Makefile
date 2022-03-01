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
	$(CC) $(CFLAGS) -c $^ -o $@

SERV_OBJS = $(SRC_SERV:.c=.o) 
CLIENT_OBJS = $(SRC_CLIENT:.c=.o)

SERV_OBJS_BONUS = $(SRC_SERV_BONUS:.c=.o) 
CLIENT_OBJS_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

ifdef BONUS
    SERV_OBJS = $(SERV_OBJS_BONUS)
    CLIENT_OBJS = $(CLIENT_OBJS_BONUS)
endif

all : $(SERVER) $(CLIENT)

clean :
	$(RM) $(SERV_OBJS) $(CLIENT_OBJS) $(SERV_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

bonus :
	make BONUS=1 all

$(SERVER) : $(SERV_OBJS)
	$(CC) $(CFLAG) -o $@ $^

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAG) -o $@ $^

.PHONY: all clean fclean re bonus