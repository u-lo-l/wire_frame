.SUFFIXES : .c .STACK_OBJS

TARGET = push_swap.out
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# STACK_DIR = ./circularArray/
# STACK_FILE = circular_array.o,\
# 				actions.o,\
# 				circular_array_check.o,\
# 				circular_array_function.o
# STACK_OBJS = $(addprefix $(STACK_DIR), $(STACK_FILE))

OBJS = ./circularArray/circular_array_check.o\
		./circularArray/circular_array.o\
		./circularArray/circular_array_function.o\
		./circularArray/actions.o\
		./args/arg_list.o\
		./args/arg_check.o\
		./args/utils.o\
		./push_swap.o\
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
