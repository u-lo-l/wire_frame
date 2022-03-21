.SUFFIXES : .c .o

TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

OBJS =	\
		SRC/STACK/circular_array.o\
		SRC/STACK/circular_array_function.o\
		\
		SRC/ARGS/arg_list.o\
		SRC/ARGS/arg_check.o\
		\
		SRC/SORT/sort_mini.o\
		SRC/SORT/sort_big.o\
		SRC/SORT/count_rb.o\
		SRC/SORT/prepare_a2b.o \
		SRC/SORT/count_actions.o \
		\
		SRC/push_swap.o\
		SRC/utils.o\
		SRC/actions.o\
		\
		just_for_debug.o\
		
SRCS = $(OBJS.o=.c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.c.o :
	$(CC) $(CFALGS) -c $< -o $@
