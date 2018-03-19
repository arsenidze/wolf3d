NAME = map.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	is_valid.c\
	lines_to_2d_arr.c\
	map.c\

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

lines_to_2d_arr.o: ../../lib/libft/includes/libft.h
lines_to_2d_arr.o: ../../lib/libft/includes/get_next_line.h
lines_to_2d_arr.o: ../../lib/libft/includes/libft.h
map.o: map.h ../module_errors/errors.h ../../lib/libft/includes/libft.h
map.o: ../../lib/libft/includes/get_next_line.h
map.o: ../../lib/libft/includes/libft.h is_valid.h lines_to_2d_arr.h
