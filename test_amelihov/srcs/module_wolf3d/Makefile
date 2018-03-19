NAME = wolf3d.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	wolf3d.c\

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

wolf3d.o: wolf3d.h ../module_game/game.h ../module_graphics/graphics.h
wolf3d.o: ../module_errors/errors.h ../../lib/mlx/mlx.h ../module_map/map.h
wolf3d.o: ../module_player/player.h ../module_userinput/userinput.h
wolf3d.o: ../module_textures/textures.h
