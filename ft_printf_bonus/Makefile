# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 22:35:00 by dkim2             #+#    #+#              #
#    Updated: 2022/01/23 00:33:33 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MACRO PART
.SUFFIXES : .c .o
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rcs

RM = rm -f

LIBFT_DIR = ./libft/
LIBFT_FILE = libft.a
LIBS = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

OBJS_M =ft_printf.o ft_print_num.o ft_print_word.o ft_format.o
SRRS_M = $(OBJS.o=.c)

OBJS_B = ft_printf_bonus.o ft_print_num_bonus.o ft_print_word_bonus.o ft_format_bonus.o
SRCS_B= $(OBJS_B.o=.c)

ifdef WITH_BONUS
	OBJS = $(OBJS_M) $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

#COMMAND PART
all : $(NAME)

bonus :
	@make WITH_BONUS=1 all

clean :
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

#DEPENDECY PART

$(NAME) : $(OBJS) $(LIBS)
	cp $(LIBS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBS)	:
	@make -C $(LIBFT_DIR) all

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@
