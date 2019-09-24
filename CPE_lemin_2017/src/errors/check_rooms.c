/*
** EPITECH PROJECT, 2018
** check_rooms.c
** File description:
** check if room line is ok
*/

#include "lemin.h"
#include "my.h"
#include <stdio.h>

int	spaces_rooms(char *str)
{
	int	i = 0;
	int	spaces = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces < 2)
		return (-1);
	return (0);
}

int	check_rooms(char *str)
{
	int i;

	if (spaces_rooms(str) == -1)
		return (-1);
		for (i = 0; str[i] != ' '; i++) {
			if (char_alphanum(str[i]) == -1)
				return (-1);
		}
	return (0);
}
