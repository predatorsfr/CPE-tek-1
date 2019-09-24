/*
** EPITECH PROJECT, 2017
** lemin.h
** File description:
** lemin header
*/

#include <stdio.h>

#ifndef LEMIN_H_
#define LEMIN_H_

typedef struct lemin_s lemin_t;
typedef struct room_s room_t;
typedef struct tunnel_s tunnel_t;

struct room_s {
	char *name;
	int pos1;
	int pos2;
	int type;
	struct room_s *next;
};

struct tunnel_s {
	char *room1;
	char *room2;
	struct tunnel_s *next;
};

struct lemin_s {
	int ants;
	struct room_s *room;
	struct tunnel_s *tunnel;
	struct room_s start;
	struct room_s end;
	char *raph;
	int error;
};

FILE	*open_file(char *path);

int	ant_nb(lemin_t *info);
int	room_info(char *str, lemin_t *info, int flag);
int	check_rooms(char *str);
int	tunnel_info(char *str, lemin_t *info);
void	rev_room(lemin_t *info);
void	rev_tunnel(lemin_t *info);

int	read_file(lemin_t *info);
int	command_comment(char *str);

#endif
