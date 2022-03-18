.SUFFIXES : .c .o

TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

OBJS = ./circularArray/circular_array_check.o\
		./circularArray/circular_array.o\
		./circularArray/circular_array_function.o\
		./circularArray/actions.o\
		./args/arg_list.o\
		./args/arg_check.o\
		./push_swap.o\
		./sort_mini.o\
		./sort_big.o\
		utils.o\
		just_for_debug.o\
		prepare_a2b.o \
		count_actions.o \
		main.o
		
SRCS = $(OBJS.o=.c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.c.o :
	$(CC) -c $< -o $@
