.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

TARGET  = test


OBJ_DIR = ./SRCS/
OBJS_FILE= read_map.o \
		ft_queue.o \
		get_next_line.o \
		ft_string.o \
		utils.o \
		\
		mat_vector.o \
		mat_matrix_basic.o \
		mat_linear_transformation.o \
		mat_view.o \
		mat_debug.o \
		\
		fdf_outputmap.o \
		fdf_mlx.o \
		fdf_mlx_draw.o \
		fdf_main.o \
		event_keyboard.o \
		event_mouse.o

OBJS = $(addprefix $(OBJ_DIR), $(OBJS_FILE))

SRCS = $(OBJS.o=.c)

all : $(TARGET)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(TARGET) -lm

.c.o :
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g
