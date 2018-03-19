NAME = wolf3d

CC = gcc
LD = $(CC)

LIB_DIR = ./lib
SRC_DIR = ./srcs

SRC_OUT = $(SRC_DIR)/src.out

LIBFT = $(LIB_DIR)/libft/libft.a
#LIBFT_INC = $(LIB_DIR)libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)/libft/

MLX = $(LIB_DIR)/mlx/libmlx.a
#MLX_INC = $(LIB_DIR)/mlx/
MLX_FLAGS = -lmlx -L $(LIB_DIR)/mlx/ \
			-framework OpenGl -framework AppKit

LIBS = $(LIBFT) $(MLX)

LFLAGS = $(LIBFT_FLAGS) $(MLX_FLAGS)

all:
	make -C $(LIB_DIR)/libft/
	make -C $(LIB_DIR)/mlx/
	make -C $(SRC_DIR)/
	make $(NAME)

$(NAME): $(SRC_OUT) $(LIBS)
	$(LD) $(SRC_OUT) $(LFLAGS) -o $@