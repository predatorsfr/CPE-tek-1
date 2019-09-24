/*
** EPITECH PROJECT, 2018
** ant_nb
** File description:
** get nb of ants
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>

int	ant_nb(lemin_t *info)
{
	char	*buff = NULL;
	size_t	buffsize = 0;

	getline(&buff, &buffsize, stdin);
	for (int i = 0; buff[i] != '\n'; i++) {
		if (char_num(buff[i]) == -1) {
			puterr("Invalid number for ants number.\n");
			info->error = -1;
			return (-1);
		}
	}
	info->ants = my_getnbr(buff);
	my_putstr("#number_of_ants\n");
	my_put_nbr(info->ants);
	return (0);
}
