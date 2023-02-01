##
## EPITECH PROJECT, 2023
## Workshop_WindowsCSFML-SFML
## File description:
## Makefile
##

NAME	=	my_hunter

RM		= 	rm -f

CC		=	gcc

SRC		=	./main.c													\
			./src/create.c												\
			./src/destroy.c												\
			./src/fill.c												\
			./src/game.c												\
			./src/clock.c												\
			./src/display.c												\
			./src/cursor.c												\
			./src/click.c												\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
