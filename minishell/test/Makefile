NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
READLINE_DIR = $(shell brew --prefix readline)
READLINE_AR = $(READLINE_DIR)/lib
READLINE_INC = $(READLINE_DIR)/include
READLINE = -lreadline -L$(READLINE_AR) -I$(READLINE_INC)

RM = rm -rf
SRCS_DIR = srcs
SRCS =$(SRCS_DIR)/readline_test.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	#$(CC) $(CFLAGS) -I $(READLINE_INC) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	#$(CC) $(CFLAGS) $(READLINE) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean:  clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
