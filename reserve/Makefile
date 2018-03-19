NAME = wolf3d
PWD = $(shell pwd)


CC     = gcc
LD     = $(CC)
DEPEND = makedepend

SRC_DIR = ./srcs
OBJ_DIR = ./obj
INC_DIR = /includes
LIB_DIR = ./lib

SRC = $(wildcard $(SRC_DIR)/*.c)
_SRC = $(patsubst $(SRC_DIR)/%.c, %.c, $(SRC))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INC = $(INC_DIR)/*.h

LIBFT = $(LIB_DIR)/libft/libft.a
LIBFT_INC = $(LIB_DIR)/libft/includes/
LIBFT_FLAGS = -lft -L $(LIB_DIR)/libft/

MLX = $(LIB_DIR)/mlx/libmlx.a
MLX_INC = $(LIB_DIR)/mlx/
MLX_FLAGS = -lmlx -L $(LIB_DIR)/mlx/ -framework OpenGl -framework AppKit

#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g
HFLAGS = -I $(PWD)/$(INC_DIR) -I $(PWD)/$(LIBFT_INC) -I $(PWD)/$(MLX_INC)
LFLAGS = $(LIBFT_FLAGS) $(MLX_FLAGS)

all:
	make depend
	make -C $(LIB_DIR)/libft/
	make -C $(LIB_DIR)/mlx/
	make $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(LD) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIB_DIR)/libft/

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf $(OBJ_DIR)
	make fclean -C $(LIB_DIR)/libft/
	make clean -C $(LIB_DIR)/mlx/

re: fclean all

depend:
	@echo "make depend"
	@cd $(SRC_DIR); \
	$(DEPEND) -Y -f ../Makefile -p $(OBJ_DIR)/ -- $(HFLAGS) -- $(_SRC); \
	cd ..; \
	rm Makefile.bak

.PHONY: all clean fclean re depend
# DO NOT DELETE

./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/controllers.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/keys.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/controllers.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/mlx/mlx.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/env.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/errors.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/game.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/game.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/game.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/game.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/graphics.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/graphics.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/graphics.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/graphics.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/mlx/mlx.h
./obj/lines_to_2d_arr.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/libft.h
./obj/lines_to_2d_arr.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/get_next_line.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/controllers.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/libft.h
./obj/main.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/get_next_line.h
./obj/map.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/map.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/map.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/libft.h
./obj/map.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/get_next_line.h
./obj/map.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/map.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map_private.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/render_private.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/raycasting.h
./obj/match_tex.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/vect2.h
./obj/player.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/player_transform.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/player_transform.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/player_transform.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/player_transform.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/put_world_on_image_private.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/raycasting.h
./obj/put_world_on_image.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/vect2.h
./obj/raycasting.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/raycasting.h
./obj/raycasting.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/raycasting.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/vect2.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/render_private.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/libft.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/get_next_line.h
./obj/render.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/mlx/mlx.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/run_event_handler_loop.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/mlx/mlx.h
./obj/textures.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/textures.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/textures.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/textures.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/mlx/mlx.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/env.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/graphics.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/wolf3d_defines.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/game.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/map.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/player.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/errors.h
./obj/update.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/user_input.o: /Users/amelihov/Projects/wolf3d/new_variant/includes/user_input.h
./obj/user_input.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/libft.h
./obj/user_input.o: /Users/amelihov/Projects/wolf3d/new_variant/./lib/libft/includes/get_next_line.h
