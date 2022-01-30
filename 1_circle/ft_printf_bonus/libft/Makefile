# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 15:17:54 by dkim2             #+#    #+#              #
#    Updated: 2022/01/23 00:05:19 by dkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MACRO PART
.SUFFIXES : .c .o
NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rsc

SRCS_M = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr.c ft_max.c ft_min.c
OBJS_M = $(SRCS_M:.c=.o)

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_B = $(SRCS_B:.c=.o)

ifdef LIBFT_BONUS
	OBJS = $(OBJS_M) $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

#COMMAND PART
all : $(NAME)

bonus :
	@make LIBFT_BONUS=1 all

clean :
	rm -rf $(OBJS_M) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

#DEPENDENCY PART
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@
