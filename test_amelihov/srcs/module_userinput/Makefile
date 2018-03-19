NAME = userinput.out

CC		= gcc
LD		= ld
DEPEND 	= makedepend

CFLAGS = -Wall -g

SRC =\
	userinput.c\

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

userinput.o: userinput.h ../../lib/libft/includes/libft.h
userinput.o: ../../lib/libft/includes/get_next_line.h
userinput.o: ../../lib/libft/includes/libft.h
