/*
** EPITECH PROJECT, 2018
** alpha.c
** File description:
** check if char or str is alpha
*/

#include "my.h"

int	char_alpha(char c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		return (-1);
	return (0);
}

int	is_alpha(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (char_alpha(str[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
