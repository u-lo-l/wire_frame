.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

TARGET  = fdf

OBJ_M_DIR = ./SRCS/
OBJ_B_DIR = ./SRCS_B/
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
OBJS_B = $(addprefix $(OBJ_B_DIR), $(addsuffix _bonus.o, $(OBJS_FILE)))

SRCS_M = $(OBJS_M.o=.c)
SRCS_B = $(OBJS_B.o=.c)

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all : $(TARGET)

bonus :
		@make WITH_BONUS=1 all

clean :
	$(RM) $(OBJS_M) $(OBJS_B)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re bonus

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(TARGET)
.c.o :
	$(CC) $(CFLAGS) -Wall -Wextra -Werror -Imlx -c $< -o $@
