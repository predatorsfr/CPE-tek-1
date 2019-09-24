/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>

int	main(void)
{
	lemin_t	info;

	if ((read_file(&info)) == 84)
		return (84);
	return (0);
}
