##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile lib
##

SRC	=	my_putstr.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_strlen.c		\
		my_strcat.c		\
		my_getnbr.c		\
		my_putchar.c		\
		my_revstr.c		\
		my_strncmp.c		\
		puterr.c		\
		is_num.c		\
		alphanum.c		\
		is_alpha.c		\
		find_dash.c		\
		prttunnels.c	\
		my_put_nbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	+=	-I ../../include/ -W -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		rm *.o

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
