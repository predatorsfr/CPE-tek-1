/*
** EPITECH PROJECT, 2018
** alpha.c
** File description:
** check if char or str is alpha
*/

#include "my.h"

int	char_num(char c)
{
	if (c < '0' || c > '9')
		return (-1);
	return (0);
}

int	is_num(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (char_num(str[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
