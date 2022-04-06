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
		mat_vector2.o \
		mat_matrix_basic.o \
		mat_linear_transformation.o \
		mat_isometric_view.o \
		mat_parrallel_view.o \
		\
		fdf_outputmap.o \
		fdf_mlx.o \
		fdf_mlx_draw.o \
		fdf_main.o \
		fdf_mlx_event.o \
		fdf_mlx_color.o

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
	# $(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib \
	# -Imlx_linux -lXext -lX11 -lm -lz -o $(TARGET) -lm
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(TARGET)
.c.o :
	# $(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g
	$(CC) $(CFLAGS) -Wall -Wextra -Werror -Imlx -c $< -o $@
