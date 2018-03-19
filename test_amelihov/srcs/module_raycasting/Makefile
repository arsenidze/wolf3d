NAME = raycasting.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	raycasting.c\

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

raycasting.o: raycasting.h ../module_map/map.h ../module_errors/errors.h
