NAME = heredoc_test
CC = cc -g
#CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -g
LDLIBS = -lreadline
RM = rm -f
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include
SRCS = $(addprefix , \
			heredoc_test.c \
	)

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -I ./$(INCLUDE)/ -c $^ -o $@ $(LDLIBS)

# $(CC) $(COMFILE_FLAGS) -I ./$(INCLUDE)/ -c $^ -o $@
# $(CC) $(CFLAGS) -I ./$(INCLUDE)/ -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(LINKING_FLAGS) $^ -o $@
	# $(CC) $^ -o $@ $(LDLIBS)
# $(CC) $(CFLAGS) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

 .PHONY : all clean fclean re
