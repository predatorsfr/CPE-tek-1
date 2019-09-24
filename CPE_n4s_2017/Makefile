##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of the My_world project.
##

CC	= gcc

SRC	=	src/main.c	\
		src/wordtab.c	\

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	= -I./include

CFLAGS = -Wall -Wextra

LDFLAGS	=	-lm

NAME	=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
