/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** raphael.dubois@epitech.eu
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../my.h"

void linecheck(loop_stct *lp)
{
	initline(lp);
	while (lp->line2 <= 0 && lp->line2 != 3 ||
	       lp->line2 > lp->line || lp->w == 0) {
		lp->p = 0;
		lp->n = 0;
		lp->validate = 1;
		if (lp->z >= 1)
			my_printf("Error: this line is out of range\n");
		lp->z = 0;
		my_putstr("Line: ");
		lp->test = read(0, lp->rd, 250);
		lp->rd[250] = '\0';
		if (lp->test < 1) {
			lp->validate = 3;
			break;
		}
		loopline(lp);
		errorline(lp);
	}
}

void matches(loop_stct *lp)
{
	my_putstr("Matches: ");
	lp->test = read(0, lp->rd2, 250);
	lp->rd2[250] = '\0';
	lp->max = my_atoi(lp->rd2);
	matcheloop(lp);
	if (lp->max > lp->w && lp->validate != 0) {
		my_printf("Error: not enough matches on this line\n");
		lp->validate = 0;
	}
}

void deletechar(loop_stct *lp)
{
	for (lp->j = 0; lp->map[lp->line2][lp->j] != '\0'; lp->j++) {
		if (lp->map[lp->line2][lp->j] == '|' &&
		    lp->map[lp->line2][lp->j + 1] == ' ' ||
		    lp->map[lp->line2][lp->j] == '|' &&
		    lp->map[lp->line2][lp->j + 1] == '*')
			break;
	}
	for (lp->k = lp->max; lp->k != 0; --lp->k) {
		lp->map[lp->line2][lp->j] = ' ';
		lp->j--;
		if (lp->map[lp->line2][lp->j] == '*' ||
		    lp->map[lp->line2][lp->j] == ' ')
			break;
	}
}

void checkmatches(loop_stct *lp)
{
	for (lp->x = 0; lp->map[lp->r][2] != '*'; lp->x++) {
		if (lp->map[lp->r][lp->x] == '|')
			lp->m++;
		if (lp->map[lp->r][lp->x] == '*') {
			lp->r++;
			lp->x = 0;
		}
	}
}

void reinit(loop_stct *lp)
{
	lp->r = 1;
	lp->max = 0;
	lp->line2 = 0;
	lp->j = 0;
	lp->w = 0;
	lp->z = 0;
	lp->m = 0;
	printmap(lp);
}
