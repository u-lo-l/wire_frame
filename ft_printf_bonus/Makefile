# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 22:35:00 by dkim2             #+#    #+#              #
#    Updated: 2022/01/22 17:34:41 by dkim2            ###   ########.fr        #
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

OBJS =ft_printf.o ft_print_num.o ft_print_word.o
SRRS = $(OBJS.o=.c)

OBJS_B = ft_printf_bonus.o ft_print_num_bonus.o ft_print_word_bonus.o ft_format_bonus.o
SRCS_B= $(OBJS_B.o=.c)

all : $(NAME)

bonus : $(OBJS_B) $(LIBS)
	cp $(LIBS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_B)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

$(NAME) : $(OBJS) $(LIBS)
	cp $(LIBS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBS)	:
	cd ./libft ; make

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@
