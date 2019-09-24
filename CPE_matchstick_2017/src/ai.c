/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** raphael.dubois@epitech.eu
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../my.h"

void checklineia(loop_stct *lp)
{
	if (lp->line2 <= lp->line) {
		for (lp->j = 0;
		     lp->map[lp->line2][lp->j] != '\0';
		     lp->j++) {
			if (lp->map[lp->line2][lp->j] == '|')
				lp->w++;
		}
		lp->z++;
	}
}

void aiturn(loop_stct *lp)
{
	if (lp->m > 0) {
		ai(lp);
		checkmatches(lp);
	}
	if (lp->validate < 2) {
		if (lp->m == 0 && lp->victory != 2) {
			printmap(lp);
			my_printf("I lost... snif... but ");
			my_printf("I'll get you next time!!\n");
			lp->victory = 1;
		}
	}
}

void initia(loop_stct *lp)
{
	lp->line2 = 0;
	lp->z = 0;
	lp->w = 0;
	lp->max = 0;
	lp->m = 0;
	lp->r = 1;
}

void ai(loop_stct *lp)
{
	printmap(lp);
	my_printf("\nAI's turn...\n");
	initia(lp);
	while (lp->max <= 0) {
		while (lp->line2 <= 0 || lp->w == 0) {
			srandom(time(NULL));
			lp->line2 = 1 + random() % (lp->line + 1);
			checklineia(lp);
		}
		srandom(time(NULL));
		if (lp->w > lp->max_take)
			lp->max = 1 + random() % lp->max_take;
		else
			lp->max = 1 + random() % lp->w;
		if (lp->max == 0)
			lp->max++;
	}
	deletechar(lp);
	my_printf("AI removed %d match(es) from line %d\n", lp->max, lp->line2);
}
