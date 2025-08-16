##
## EPITECH PROJECT, 2021
## B-MUL-100-RUN-1-1-myhunter-guillyann.ferrere
## File description:
## Makefile
##

SRC = window.c \
	my_runner.c \
	animate_sprite.c \
	array_len.c \
	init.c \
	description.c \
	jump.c \
	manage_map.c \
	destroy_free.c \
	ennemy_clash.c \
	int_to_str.c \
	parallax.c

OBJ = $(SRC:.c=.o)

IFLAGS = -I./include

LFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS = -Werror -Wall -Wextra -W $(IFLAGS) $(LFLAGS) -g3

NAME = my_runner

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)


clean:
	rm -f *#
	rm -f ~*
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
