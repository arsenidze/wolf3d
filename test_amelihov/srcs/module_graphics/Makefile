NAME = graphics.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	draw_minimap.c\
	draw_player_info.c\
	draw_world.c\
	graphics.c\
	render.c\

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) -r $(OBJ) -o $@

clean:
	rm $(OBJ) $(NAME) *.bak

depend:
	$(DEPEND) -Y -- $(CFLAGS) -- $(SRC)
	rm Makefile.bak
# DO NOT DELETE

draw_world.o: ../module_game/game.h ../module_graphics/graphics.h
draw_world.o: ../module_errors/errors.h ../../lib/mlx/mlx.h
draw_world.o: ../module_map/map.h ../module_player/player.h
draw_world.o: ../module_userinput/userinput.h
draw_world.o: ../module_raycasting/raycasting.h ../module_wolf3d/wolf3d.h
draw_world.o: ../module_textures/textures.h
graphics.o: graphics.h ../module_errors/errors.h ../module_game/game.h
graphics.o: ../module_graphics/graphics.h ../../lib/mlx/mlx.h
graphics.o: ../module_map/map.h ../module_player/player.h
graphics.o: ../module_userinput/userinput.h ../module_wolf3d/wolf3d.h
graphics.o: ../module_textures/textures.h
render.o: ../module_game/game.h ../module_graphics/graphics.h
render.o: ../module_errors/errors.h ../../lib/mlx/mlx.h ../module_map/map.h
render.o: ../module_player/player.h ../module_userinput/userinput.h drawing.h
render.o: graphics.h
