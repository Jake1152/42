NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
PHILO_DIR = philo
SRCS = srcs
INCLUDE = include
PHILO_SRCS = $(addprefix $(PHILO_DIR)/$(SRCS)/, \
	philo.c	\
	init.c	\
	philo_action.c	\
	monitor.c	\
	time.c	\
	free.c	\
	utils.c	\
	print.c	\
	error_handler.c \
)

PHILO_OBJS = $(PHILO_SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I ./$(PHILO_DIR)/$(INCLUDE)/ -c $^ -o $@

$(PHILO_DIR)/$(NAME) : $(PHILO_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all : $(PHILO_DIR)/$(NAME)

clean :
	$(RM) $(PHILO_OBJS)

fclean:  clean
	$(RM) $(PHILO_DIR)/$(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
