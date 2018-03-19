SRC_OUT = src.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -g

MODULES =\
	wolf3d\
	game\
	map\
	player\
	graphics\
	textures\
	controllers\
	userinput\
	errors\
	raycasting\

SRC =\
	main.c

OBJ = $(SRC:%.c=%.o)

_MODULES_DIRS = $(addprefix ./module_, $(MODULES))
MODULES_DIRS = $(addsuffix /, $(_MODULES_DIRS))
OUT_EXTENSION = $(addsuffix .out, $(MODULES))
OUT = $(join $(MODULES_DIRS), $(OUT_EXTENSION))

all: $(MODULES_DIRS)
	make $(SRC_OUT)

$(MODULES_DIRS):
	make -C $@

$(SRC_OUT): $(OUT) $(OBJ)
	$(LD) -r $(OUT) $(OBJ) -o $@

clean:


fclean: clean


re: fclean all

depend:
	$(DEPEND) -Y -- $(CFLAGS) -- $(SRC)
	rm Makefile.bak

.PHONY: all clean fclean re $(MODULES_DIRS)
# DO NOT DELETE

main.o: ../lib/libft/includes/libft.h ../lib/libft/includes/get_next_line.h
main.o: ../lib/libft/includes/libft.h ./module_wolf3d/wolf3d.h
main.o: ./module_game/game.h ./module_graphics/graphics.h
main.o: ./module_errors/errors.h ../../lib/mlx/mlx.h ./module_map/map.h
main.o: ./module_player/player.h ./module_userinput/userinput.h
main.o: ./module_textures/textures.h ./module_game/game.h
main.o: ./module_errors/errors.h ./module_controllers/controllers.h
main.o: ./module_wolf3d/wolf3d.h
