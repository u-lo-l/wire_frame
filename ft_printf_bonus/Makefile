# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 22:35:00 by dkim2             #+#    #+#              #
#    Updated: 2021/12/19 01:29:38 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

RM = rm -f

LIBFT_DIR = ./libft/
LIBFT_FILE = libft.a
LIBS = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
# LIBS = ./libft/libft.a

OBJS = ft_printf.o ft_print_num.o ft_print_word.o ft_format.o
SRCS = $(OBJS.o=.c)

all : $(NAME)

bonus : all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

$(NAME) : $(OBJS) $(LIBS)
	mv $(LIBS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	
$(LIBS)	:
	cd ./libft ; make

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@