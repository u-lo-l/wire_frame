.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

TARGET  = fdf

OBJ_M_DIR = ./SRCS/
OBJS_FILE= read_map \
		ft_queue \
		get_next_line \
		ft_string\
		utils\
		\
		mat_vector\
		mat_vector2\
		mat_matrix_basic\
		mat_linear_transformation\
		mat_isometric_view\
		mat_parallel_view\
		\
		fdf_outputmap\
		fdf_mlx\
		fdf_mlx_draw\
		fdf_main\
		fdf_mlx_event\
		fdf_mlx_color

OBJS_M = $(addprefix $(OBJ_M_DIR), $(addsuffix .o, $(OBJS_FILE)))

SRCS_M = $(OBJS_M.o=.c)

LIBMLX = ./mlx/libmlx.a

all : $(TARGET)

clean :
	$(RM) $(OBJS_M)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

$(TARGET) : $(OBJS_M)
	${CC} ${OBJS_M} -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -o ${TARGET}

.c.o :
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${LIBMLX} :
	@make -C ./mlx all
