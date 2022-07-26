# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 16:38:36 by jim               #+#    #+#              #
#    Updated: 2022/07/03 15:46:56 by jim              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRCS = srcs
PUSH_SWAP_SRCS = $(addprefix $(SRCS)/, \
					./push_swap_main.c \
					./push_swap.c \
					./doublylist_definition.c \
					./doublylist_manipulation.c \
					./pop.c \
					./push.c \
					./reverse_rotate.c \
					./rotate.c \
					./swap.c \
					./sort_greedy.c \
					./sort_for_indexing.c \
					./sort_brute_force.c \
					./sort_utils.c \
					./check_sort.c \
					./utils.c \
					./error_handler.c \
					./ft_split.c \
					./ft_strncmp.c \
					./ft_substr.c \
					./ft_strlcpy.c \
					./ft_strdup.c \
)

CHECKER_SRCS = $(addprefix $(SRCS)/, \
				./checker.c \
				./get_next_line.c \
				./get_next_line_utils.c \
				./push_swap.c \
				./doublylist_definition.c \
				./doublylist_manipulation.c \
				./pop.c \
				./push.c \
				./reverse_rotate.c \
				./rotate.c \
				./swap.c \
				./sort_greedy.c \
				./sort_for_indexing.c \
				./sort_brute_force.c \
				./sort_utils.c \
				./check_sort.c \
				./utils.c \
				./error_handler.c \
				./ft_split.c \
				./ft_strncmp.c \
				./ft_substr.c \
				./ft_strlcpy.c \
				./ft_strdup.c \
)

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHEKCER_OBJS = $(CHECKER_SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -I ./include/ -c $^ -o $@

$(PUSH_SWAP) : $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER) : $(CHEKCER_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all : $(PUSH_SWAP)

clean :
	$(RM) $(PUSH_SWAP_OBJS) $(CHEKCER_OBJS)

fclean:  clean
	$(RM) $(PUSH_SWAP) $(CHECKER)

re : fclean all

bonus : $(CHECKER)

.PHONY : all clean fclean re bonus
