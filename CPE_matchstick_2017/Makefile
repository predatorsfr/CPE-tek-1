##
## EPITECH PROJECT, 2018
## makefile
## File description:
## raphael.dubois@epitech.eu
##

SRC	=	main.c \
		src/lib.c \
		src/match.c \
		src/my_printf.c \
		src/loop.c \
		src/ai.c \
		src/norme.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(SRC) -o $(NAME)
clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f *~
		rm -f src/*~
		rm -f include/*~

re:		fclean all

.PHONY :	all clean fclean re
