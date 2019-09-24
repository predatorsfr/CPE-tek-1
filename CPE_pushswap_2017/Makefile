##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/pa.c \
		src/libs.c \
		src/moove.c \
		main.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -Wall -Wextra -Werror

NAME	=	push_swap

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f *~
		rm -f src/*~
		rm -f lib/my/*~

re:		fclean all

.PHONY : 	all clean fclean re
