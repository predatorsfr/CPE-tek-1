/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** raphael.dubois@epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>
#include "../my.h"

void first_last_line(match_stct *mt, char **map, int n)
{
	mt->j = 0;
	for (mt->k = (n * 2) + 1; mt->k != 0; mt->k--) {
		map[0][mt->j] = '*';
		map[mt->i][mt->j] = '*';
		mt->j++;
	}
}
void space_pipe(match_stct *mt, char **map)
{
	for (mt->k = 1; mt->k < mt->space; mt->k++) {
		map[mt->i][mt->j] = ' ';
		mt->j++;
	}
	mt->v = mt->k;
	for (mt->k = 1; mt->k <= mt->c; mt->k++) {
		map[mt->i][mt->j] = '|';
		mt->j++;
		if (mt->c > 1 && mt->count < mt->c) {
			map[mt->i][mt->j] = '|';
			mt->j++;
			mt->count++;
		}
	}
	for (mt->k = mt->v; mt->k != 0; mt->k--) {
		map[mt->i][mt->j] = ' ';
		mt->j++;
	}
}
void init_match(int n, match_stct *mt)
{
	mt->max = 0;
	mt->space = n;
	mt->count = 1;
	mt->i = 1;
	mt->j = 1;
}
int match(int n)
{
	match_stct *mt = malloc(sizeof(*mt));
	char **map = malloc(sizeof(char *) * 201);

	init_match(n, mt);
	map[mt->i] = malloc(sizeof(char) * 201);
	map[0] = malloc(sizeof(char) * 201);
	for (mt->c = 1; mt->c <= n; mt->c++) {
		map[mt->i][0] = '*';
		space_pipe(mt, map);
		map[mt->i][mt->j - 1] = '*';
		mt->j = 1;
		mt->i++;
		map[mt->i] = malloc(sizeof(char) * 201);
		mt->space--;
		mt->count = 1;
	}
	first_last_line(mt, map, n);
	map[mt->i][mt->j + 1] = '\0';
	return map;
}
