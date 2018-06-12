##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## Makefile for my_sokoban.
##

SRC	=	src/main.c		\
		src/handle_map.c	\
		src/game_loop.c		\
		src/move.c		\
		src/test_map.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS+=	-I include

CFLAGS	+=	-Wall -Wextra

LDFLAGS	=	-lncurses -Llib -lmy

NAME	=	my_sokoban

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean	all

.PHONY	:	all clean fclean re
