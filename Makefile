# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 12:49:29 by ftome-ve          #+#    #+#              #
#    Updated: 2024/06/05 13:15:26 by ftome-ve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
LIBC	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

NAME	= push_swap
BONUS_NAME	= checker
SRCS	= main.c error_mode.c find.c initialize.c movements.c push.c swap.c \
		put_in_order.c rev_rotate.c split_atoi.c split_utils.c rotate.c \
		list_utils.c others.c get_next_line.c get_next_line_utils.c

BONUS_SRCS = get_next_line.c get_next_line_utils.c main_bonus.c error_mode.c \
		find.c initialize.c movements.c push.c swap.c \
		put_in_order.c rev_rotate.c split_atoi.c split_utils.c rotate.c \
		list_utils.c others.c


OBJS	= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@
	@echo "Executable $(NAME) created."

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@chmod +x $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@chmod +x $(BONUS_NAME)

bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@chmod +x $(BONUS_NAME)
	
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "Executable $(NAME) cleaned."

re: fclean all

.PHONY: all .c.o clean fclean re bonus