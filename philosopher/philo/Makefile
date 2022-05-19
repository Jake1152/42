NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = srcs
INCLUDE = include
PHILO_SRCS =$(addprefix $(SRCS)/, \
	main.c	\
	philo.c	\
	init.c	\
	philo_action.c	\
	monitor.c	\
	time.c	\
	free.c	\
	utils.c	\
	print.c	\
)

PHILO_OBJS = $(PHILO_SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I ./$(INCLUDE)/ -c $^ -o $@

$(NAME) : $(PHILO_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(PHILO_OBJS)

fclean:  clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
