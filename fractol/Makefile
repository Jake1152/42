NAME = fractol
SRCS = fractol.c
OBJS = fractol.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf

%o : %c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lminilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all
