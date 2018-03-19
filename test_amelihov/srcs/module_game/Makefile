NAME = game.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	game.c\
	update.c\

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

game.o: game.h ../module_graphics/graphics.h ../module_errors/errors.h
game.o: ../module_game/game.h ../../lib/mlx/mlx.h ../module_map/map.h
game.o: ../module_player/player.h ../module_userinput/userinput.h
update.o: game.h ../module_graphics/graphics.h ../module_errors/errors.h
update.o: ../module_game/game.h ../../lib/mlx/mlx.h ../module_map/map.h
update.o: ../module_player/player.h ../module_userinput/userinput.h
