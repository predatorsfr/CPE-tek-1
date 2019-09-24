/*
** EPITECH PROJECT, 2018
** tunnel_info.c
** File description:
** get info of tunnels
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

static char	*get_name(char *str)
{
	int	i = 0;
	int	len = 0;
	char	*name = NULL;

	while (str[len] != '-' && str[len] != '\0')
		len++;
	name = malloc(sizeof(char) * (len + 1));
	if (name == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		name[i] = str[i];
	name[i] = '\0';
	return (name);
}

int	tunnel_info(char *str, lemin_t *info)
{
	tunnel_t	*new = malloc(sizeof(tunnel_t));

	if (new == NULL)
		return (84);
	new->room1 = get_name(str);
	while (*str != '-')
		str++;
	str++;
	new->room2 = get_name(str);
	new->next = info->tunnel;
	info->tunnel = new;
	return (0);
}
