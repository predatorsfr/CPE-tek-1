/*
** EPITECH PROJECT, 2018
** room_info.c
** File description:
** store name/positions of room in struct
*/

#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>

static char	*get_name(char *str)
{
	int	i = 0;
	int	len = 0;
	char	*name = NULL;

	while (str[len] != ' ' && str[len] != '\0')
		len++;
	name = malloc(sizeof(char) * (len + 1));
	if (name == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		name[i] = str[i];
	name[i] = '\0';
	return (name);
}

void	get_pos(char *str, room_t **new, int flag)
{
	while (*str != ' ' && *str != '\n')
		str++;
	str++;
	(*new)->pos1 = my_getnbr(str);
	while (*str != ' ' && *str != '\n')
		str++;
	str++;
	(*new)->pos2 = my_getnbr(str);
	(*new)->type = flag != 0 ? flag : 0;
}

int	room_info(char *str, lemin_t *info, int flag)
{
	room_t	*new = malloc(sizeof(room_t));

	if (new == NULL)
		return (-1);
	new->name = get_name(str);
	get_pos(str, &new, flag);
	new->next = info->room;
	info->room = new;
	return (0);
}
