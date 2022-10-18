# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:07:01 by hyuncpar          #+#    #+#              #
#    Updated: 2022/08/25 14:09:42 by hyuncpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFTDIR	=	./Libft
LIBFTFILE	=	libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_printf.c \
			ft_parse_option.c\
			ft_print_string.c \
			ft_processing_num.c \
			ft_print_num.c \

OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $@ $?

bonus :

all : $(NAME)

clean :
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus