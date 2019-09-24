/*
** EPITECH PROJECT, 2018
** alphanum.c
** File description:
** check if char or str is alphanum
*/

#include "my.h"

int	char_alphanum(char c)
{
	if ((c < '0' || c > '9') && (c < 'A' || c > 'Z') &&
						(c < 'a' || c > 'z'))
		return (-1);
	return (0);
}

int	alphanum(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (char_alphanum(str[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
