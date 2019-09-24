##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile exe
##

CC	=	gcc

CFLAGS	+=	-L./lib/my -lmy -I./include

SRC	=	src/main.c			\
		src/get_info/ant_nb.c		\
		src/get_info/read_file.c	\
		src/get_info/command_comment.c	\
		src/get_info/room_info.c	\
		src/errors/check_rooms.c	\
		src/get_info/tunnel_info.c	\
		src/get_info/rev_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my re
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		make -C ./lib/my clean
		rm -f $(OBJ)

fclean:		clean
		make -C ./lib/my fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
