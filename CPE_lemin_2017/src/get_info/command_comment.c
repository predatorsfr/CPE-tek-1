/*
** EPITECH PROJECT, 2018
** command_commend.c
** File description:
** check if line is command or comment
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>

int	get_command(char *str)
{
	if (my_strcmp(str, "##start\n") == 0)
		return (1);
	if (my_strcmp(str, "##end\n") == 0)
		return (2);
	return (0);
}

int	command_comment(char *str)
{
	if (str[1] == '#')
		return (get_command(str));
	return (0);
}
