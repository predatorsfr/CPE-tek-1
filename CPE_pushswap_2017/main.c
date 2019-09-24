/*
** EPITECH PROJECT, 2017
** pushswap.c
** File description:
** raphael.dubois@epitech.eu
*/
#include	<stdlib.h>
#include	"include/my.h"

void	free_l(t_list *list)
{
	int	flag;
	t_elem	*tmp;
	t_elem	*tmp2;

	flag = 0;
	if (list->elems) {
		tmp = list->elems->prev;
		while (tmp != list->elems) {
			if (!flag)
				tmp = list->elems;
			flag = 1;
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
	}
	free(list);
}
int  check(int *tab, int ac)
{
	int i;

	i = 0;
	while (i != ac) {
		if (tab[i] <= tab[i+1])
			i++;
		else
			return(84);
	}
	return(1);
}
int no_error(int ac, char **av)
{
	t_list	*l_a;
	t_list	*l_b;
	int i;

	i = 0;
	l_a = create_list();
	l_b = create_list();
	while (++i < ac)
		l_a->push_back(l_a, my_getnbr(av[i]));
	push_swap(l_a, l_b);
	free_l(l_a);
	free_l(l_b);
	return(0);
}

int	main(int ac, char **av)
{
	int	tab[ac - 1];
	int	i;
	int	j = 0;
	int	b = ac - 1;

	i = 0;
	while (i != ac) {
		tab[j] = my_getnbr(av[i]);
		i++;
		j++;
	}
	if (ac == 2 || ac > 2050) {
		my_putstr("\n");
		return 0;
	}
	if (check(tab, b) == 1) {
		my_putstr("\n");
		return 0;
	}
	no_error(ac, av);
	return 0;
}
