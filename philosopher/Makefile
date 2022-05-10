NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
PHILO_DIR = philo
SRCS = srcs
INCLUDE = include
PHILO_SRCS = philo.c	\
			init.c	\
			philo_action.c	\
			time.c	\
			free.c	\
			utils.c	\
			print.c
PHILO_OBJS = $(PHILO_SRCS:.c=.o)

%.o : ./$(PHILO_DIR)/$(SRCS)/%.c
	$(CC) $(CFLAGS) -I ./$(PHILO_DIR)/$(INCLUDE)/ -c $^ -o $@

$(PHILO_DIR)/$(NAME) : $(PHILO_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

all : $(PHILO_DIR)/$(NAME)

clean :
	$(RM) $(PHILO_OBJS)

fclean:  clean
	$(RM) $(PHILO_DIR)/$(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
