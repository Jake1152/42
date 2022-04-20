NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
PHILO_DIR = philo
SRCS = srcs
INCLUDE = include
PHILO_SRCS = philo.c	\
			utils.c	\
			print.c
PHILO_OBJS = $(PHILO_SRCS:.c=.o)

%.o : ./$(PHILO_DIR)/$(SRCS)/%.c
	$(CC) $(CFLAGS) -I ./$(PHILO_DIR)/$(INCLUDE)/ -c $^ -o $@ 

$(PHILO_DIR)/$(NAME) : $(PHILO_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

all : $(NAME)

clean :
	$(RM) $(PHILO_OBJS)

fclean:  clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re