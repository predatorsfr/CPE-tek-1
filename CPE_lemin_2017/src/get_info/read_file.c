/*
** EPITECH PROJECT, 2018
** read_file.c
** File description:
** read input file
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>

int	read_tunnel(lemin_t *info)
{
	int	read = 0;
	char	*buff = NULL;
	size_t	buffsize = 0;

	while ((read = getline(&buff, &buffsize, stdin)) != -1) {
		if (buff != NULL && buff[0] != '#')
			if (tunnel_info(buff, info) == 84)
				return (84);
	}
	return (0);
}

int print_rooms(lemin_t *info)
{
	write(1, "\n#rooms\n", 8);
	while (info->room != NULL) {
		if (info->room->type == 1)
			my_putstr("##start\n");
		if (info->room->type == 2)
			my_putstr("##end\n");
		my_putstr(info->room->name);
		write(1, " ", 1);
		my_put_nbr(info->room->pos1);
		write(1, " ", 1);
		my_put_nbr(info->room->pos2);
		write(1, "\n", 1);
		info->room = info->room->next;
	}
	return (0);
}

int	read_room(lemin_t *info)
{
	int	read = 0;
	int	flag = 0;
	char *buff = NULL;
	size_t	buffsize = 0;

	while (((read = getline(&buff, &buffsize, stdin)) != -1) &&
	       find_dash(buff) == 0) {
		if (buff[0] == '#') {
			flag = command_comment(buff);
			continue;
		}
		if (check_rooms(buff) != -1)
			if (room_info(buff, info, flag) == -1)
				return (84);
		flag = 0;
	}
	info->raph = my_strdup(buff);
	return (0);
}

int	read_file(lemin_t *info)
{
	room_t		*room = NULL;
	tunnel_t	*tunnel = NULL;

	info->room = room;
	info->tunnel = tunnel;
	if (ant_nb(info) == -1)
		return (84);
	if ((read_room(info)) == 84 || (read_tunnel(info)) == 84)
		return (84);
	rev_room(info);
	rev_tunnel(info);
	print_rooms(info);
	prt(info);
	return (0);
}
