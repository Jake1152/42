NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ./main.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re :
	make fclean
	make all

.PHONY : all clean fclean re
	
