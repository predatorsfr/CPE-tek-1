/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** raphael.dubois@epitech.eu
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int player(loop_stct *lp)
{
	my_putstr("\nYour turn :\n");
	while (lp->validate != 1) {
		linecheck(lp);
		if (lp->validate == 3)
			return 0;
		matches(lp);
	}
	deletechar(lp);
	my_printf("Player removed %d match(es) from line %d\n"
		  , lp->max, lp->line2);
	checkmatches(lp);
	if (lp->m == 0) {
		printmap(lp);
		my_printf("You lost, too bad...\n");
		lp->victory = 2;
	}
}

int loop(loop_stct *lp, char *av)
{
	lp->max_take = my_atoi(av);
	lp->map = match(lp->line);
	printmap(lp);
	while (lp->match1 != 1) {
		player(lp);
		aiturn(lp);
		if (lp->victory != 0 || lp->validate == 3)
			return 0;
		reinit(lp);
	}
}

void printmap(loop_stct *lp)
{
	for (int i = 0; lp->map[i] != 0; i++)
		my_printf("%s\n", lp->map[i]);
	lp->validate = 0;
}

int check(int ac, char **env, char *av1, char *av2)
{
	if (ac != 3 || env[0] == NULL)
		return 84;
	if (*av1 < 48 || *av1 > 57 || *av2 < 48 || *av2 > 57)
		return 84;
}

int main(int ac, char **av, char **env)
{
	loop_stct *lp = malloc(sizeof(*lp));

	lp->m = 0;
	lp->r = 1;
	lp->z = 0;
	lp->w = 0;
	if (check(ac, env, av[1], av[2]) == 84) {
		write(2, "bad arguments\n", 15);
		return 84;
	}
	lp->line = my_atoi(av[1]);
	if (lp->line < 2 || lp->line > 99) {
		write(2, "n must be between 1<n<100\n", 27);
		return 84;
	}
	loop(lp, av[2]);
	if (lp->victory == 1)
		return 1;
	if (lp->victory == 2)
		return 2;
}
