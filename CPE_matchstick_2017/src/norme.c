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

void initline(loop_stct *lp)
{
	lp->n = 0;
	lp->o = 0;
	lp->p = 0;
	lp->b = 0;
	lp->a = 0;
	lp->line2 = 0;
	lp->z = 0;
}

void loopline(loop_stct *lp)
{
	for (int i = 0; lp->rd[i] != 0; i++) {
		if (lp->rd[i] != '\n' && lp->p == 0) {
			if (lp->rd[i] < '0' || lp->rd[i] > '9')
				lp->n = 1;
		}
		if (lp->rd[i] == '\n' && lp->rd[i + 1] != 0)
			lp->p = 1;
	}
	if (lp->p == 1) {
		for (lp->a = 0; lp->rd[lp->a] != '\n'; lp->a++);
		lp->a++;
		lp->o = lp->a;
		for (lp->a; lp->rd[lp->a] != '\n'; lp->a++) {
			lp->rd2[lp->b] = lp->rd[lp->a];
			lp->b++;
		}
		lp->rd[lp->o] = 0;
	}
}

void errorline(loop_stct *lp)
{
	if (lp->n == 1)
		my_printf("Error: invalid input (positive number expected)\n");
	if (lp->n == 0) {
		lp->line2 = my_atoi(lp->rd);
		if (lp->line2 > lp->line)
			my_printf("Error: this line is out of range\n");
		if (lp->line2 <= lp->line) {
			for (lp->j = 0;
			     lp->map[lp->line2][lp->j] != '\0'; lp->j++) {
				if (lp->map[lp->line2][lp->j] == '|')
					lp->w++;
			}
			lp->z++;
		}
	}
}

void matcheloop(loop_stct *lp)
{
	for (int i = 0; lp->rd2[i] != 0; i++) {
		if (lp->rd2[i] == '\n')
			lp->rd2[i] = 0;
		if (lp->rd2[i] != 0) {
			if (lp->rd2[i] < '0' || lp->rd2[i] > '9') {
				my_printf("Error: invalid input");
				my_printf("(positive number expected)\n");
				lp->rd2[i] = 0;
				lp->validate = 0;
				break;
			} else if (lp->max == 0) {
				my_printf("Error: you have to remove");
				my_printf("at least one match\n");
				lp->validate = 0;
				break;
			}
		}
	}
}
