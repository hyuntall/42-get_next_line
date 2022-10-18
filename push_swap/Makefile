# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:12:08 by hyuncpar          #+#    #+#              #
#    Updated: 2022/10/13 17:10:07 by hyuncpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
PRTFDIR	=	./ft_printf
PRTFFILE=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

SRCS	=	main.c \
			parse.c

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
	make -C $(PRTFDIR)
	cp $(PRTFDIR)/$(PRTFFILE) $(NAME)

bonus :

all : $(NAME)

clean :
	make -C $(PRTFDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(PRTFDIR) fclean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus