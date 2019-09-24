/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** raphael.dubois@gepitech.eu
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"

int main(int ac, char **av)
{
	struct stat sb;
	int f;
	char *buff;
	int rd;

	stat(av[1], &sb);
	buff = malloc(sizeof(char) * sb.st_size);

	f = open(av[1], O_RDONLY);
	rd = read(f, buff, sb.st_size);

	if (rd <= 0 || ac < 2 || ac > 2 || f == -1) {
		write(2, "wrong arguments\n", 5);
		return (84);
	} else {
		parsing(buff);
	}
	free(buff);
}

int	parsing(char *buff)
{
	int column;
	int i = 0;
	int line;

	while (buff[i] != '\n') {
		i++;
		line = my_getnbr(buff);
	}
	column = i;
	while (buff[i + 1] != '\n') {
		i++;
		column++;
	}
	column--;
	tableaux(line, column, buff);
}

int tableaux(int line, int column, char *buff)
{
	int **tableau;

	tableau = malloc(sizeof(int *) * (line * column));
	for (int i = 0; i < line; i++) {
		tableau[line] = malloc(sizeof(char) * column);
		tableau[line][0] = 'X';
	}
		printf("%s\n", tableau[line]);
}
