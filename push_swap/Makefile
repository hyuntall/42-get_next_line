# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:12:08 by hyuncpar          #+#    #+#              #
#    Updated: 2022/10/21 20:20:34 by hyuncpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude
AR		=	ar rcs
RM		=	rm -f

SRCS	=	main.c parse.c list_utils.c utils.c push.c swap.c rotate.c reverse_rotate.c \
			stack_sort.c make_tri.c make_arr.c merge.c print_error.c ft_split.c ft_strdup.c \
			ft_strjoin.c ft_strlen.c

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus :

all : $(NAME)

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re :
	fclean
	all

.PHONY : all clean fclean re bonus