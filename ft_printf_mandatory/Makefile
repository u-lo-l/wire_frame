# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 22:35:00 by dkim2             #+#    #+#              #
#    Updated: 2021/12/17 15:43:03 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

LIBS = ./libft/libft.a
OBJS = ft_printf.o ft_print_num.o ft_print_word.o
SRCS = $(OBJS.o=.c)

TARGET = <- 링크 후에 생성될 실행 파일의 이름을 적는다.

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

$(NAME) : $(OBJS) $(LIBS)
	$(AR) $(ARFLAGS) $@ $(OBJS) $(LIBS)
$(LIBS)	:
	cd ./libft ; make re

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@
