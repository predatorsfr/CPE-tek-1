/*
** EPITECH PROJECT, 2018
** prttunnels.c
** File description:
** print all info for the tunnels
*/

#include "my.h"
#include "lemin.h"

void prt(lemin_t *info)
{
	static int i = 0;
	while (info->tunnel != NULL) {
	if (i == 0) {
		my_putstr("#tunnels\n");
		my_putstr(info->raph);
	}
	my_putstr(info->tunnel->room1);
	my_putchar('-');
	my_putstr(info->tunnel->room2);
		i = 1;
	info->tunnel = info->tunnel->next;
	}
}
