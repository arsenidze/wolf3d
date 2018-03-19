NAME = textures.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	textures.c\

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

textures.o: textures.h ../module_errors/errors.h
textures.o: ../module_graphics/graphics.h ../module_game/game.h
textures.o: ../module_map/map.h ../module_player/player.h
textures.o: ../module_userinput/userinput.h ../../lib/mlx/mlx.h
