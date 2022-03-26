NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
SRCS =	./push_swap.c \
		./utils.c \
		./error_handler.c \
		./libft/ft_split.c \
		./libft/ft_substr.c \
		./libft/ft_strdup.c \
		./libft/ft_strlcpy.c \
		./libft/ft_atoi.c \
		./libft/ft_strncmp.c \
		./doublylist_definition.c \
		./doublylist_manipulation.c \
		./pop.c \
		./push.c \
		./reverse_rotate.c \
		./rotate.c \
		./swap.c \
		./check_sort.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean:  clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
