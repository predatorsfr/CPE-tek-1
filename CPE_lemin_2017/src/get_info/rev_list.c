/*
** EPITECH PROJECT, 2017
** rev_list.c
** File description:
** reverse given list
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

void	rev_room(lemin_t *info)
{
	room_t	*tmp = NULL;
	room_t	*current = info->room;
	room_t	*last;

	while (current != NULL) {
		last = current->next;
		current->next = tmp;
		tmp = current;
		current = last;
	}
	info->room = tmp;
}

void	rev_tunnel(lemin_t *info)
{
	tunnel_t	*tmp = NULL;
	tunnel_t	*current = info->tunnel;
	tunnel_t	*last;

	while (current != NULL) {
		last = current->next;
		current->next = tmp;
		tmp = current;
		current = last;
	}
	info->tunnel = tmp;
}
