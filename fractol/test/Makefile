NAME = mlx_image_02
SRCS = mlx_image_02.c
OBJS = mlx_image_02.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf

%o : %c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all
