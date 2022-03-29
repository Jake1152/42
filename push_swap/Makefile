NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
SRCS =	./push_swap.c \
		./doublylist_definition.c \
		./doublylist_manipulation.c \
		./pop.c \
		./push.c \
		./reverse_rotate.c \
		./rotate.c \
		./swap.c \
		./sort_greedy.c \
		./sort_for_indexing.c \
		./sort_utils.c \
		./check_sort.c \
		./utils.c \
		./error_handler.c \
		./ft_split.c \
		./ft_substr.c \
		./ft_strdup.c \
		./ft_strlcpy.c \
		./ft_strncmp.c
		


OBJS = $(SRCS:.c=.o)

%.o : ./srcs/%.c
	$(CC) $(FLAGS) -I ./include/ -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean:  clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
