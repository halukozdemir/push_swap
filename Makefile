# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 17:58:38 by halozdem          #+#    #+#              #
#    Updated: 2024/07/03 14:33:44 by halozdem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
BONUS		= checker
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror
SRCS		= optimiser.c adv_sort_utils.c parse_args.c \
			adv_sort_utils2.c push_swap.c actions.c check_args.c \
			helper_stack.c error.c check_sort.c utils.c

OBJS		:= $(SRCS:.c=.o)

AR_LIBFT	= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS) $(AR_LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BNS)
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -s -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean bonus re