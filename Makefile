NAME = wolf3d

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIB_DIR = ./lib/

SRC =	main.c \
	  	validation.c \
		create_map.c \
	  	env.c \
	  	game.c \
	 	hooks.c \
	  	draw.c \
		color.c \
		transform.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = $(INC_DIR)$(NAME).h $(INC_DIR)keys.h

LIBFT = $(LIB_DIR)libft/libft.a
LIBFT_INC = $(LIB_DIR)libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)libft/

MLX = $(LIB_DIR)mlx/libmlx.a
MLX_INC = $(LIB_DIR)mlx/
MLX_FLAGS = -lmlx -L $(LIB_DIR)mlx/ -framework OpenGl -framework AppKit

#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g
HFLAGS = -I $(INC_DIR) -I $(LIBFT_INC) -I $(MLX_INC)
LFLAGS = $(LIBFT_FLAGS) $(MLX_FLAGS)

CC = gcc

all:
	make -C $(LIB_DIR)libft/
	make -C $(LIB_DIR)mlx/
	make $(NAME)

$(NAME): $(OBJ) $(INC) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIB_DIR)libft/

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)libft/
	make clean -C $(LIB_DIR)mlx/

re: fclean all

.PHONY: all clean fclean re
