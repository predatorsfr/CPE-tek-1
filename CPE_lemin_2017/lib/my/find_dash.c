/*
** EPITECH PROJECT, 2018
** find_dash.c
** File description:
** find if theres a - int str
*/

#include "my.h"

int	find_dash(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
