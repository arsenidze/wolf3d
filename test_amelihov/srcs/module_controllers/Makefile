NAME = controllers.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	controllers.c\

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

controllers.o: ../module_wolf3d/wolf3d.h ../module_game/game.h
controllers.o: ../module_graphics/graphics.h ../module_errors/errors.h
controllers.o: ../../lib/mlx/mlx.h ../module_map/map.h
controllers.o: ../module_player/player.h ../module_userinput/userinput.h
controllers.o: ../module_textures/textures.h keys.h
