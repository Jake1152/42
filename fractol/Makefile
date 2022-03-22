# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 20:43:19 by jim               #+#    #+#              #
#    Updated: 2022/03/22 22:32:23 by jim              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c fractol.c init.c draw.c event.c print.c utils.c error_handler.c
OBJS = main.o fractol.o init.o draw.o event.o print.o utils.o error_handler.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -o
RM = rm
RMFLAGS = -rf

%o : %c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(NAME)

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all
