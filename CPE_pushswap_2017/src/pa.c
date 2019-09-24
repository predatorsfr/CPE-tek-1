/*
** EPITECH PROJECT, 2017
** pa.c
** File description:
** raphael.dubois@epitech.eu
*/
#include "../include/my.h"

int	get_min(t_list *list)
{
	t_elem	*tmp;
	int	min;

	if (!list->elems)
		return (84);
	min = list->elems->val;
	tmp = list->elems->next;
	while (tmp != list->elems) {
		if (min > tmp->val)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

int	is_sort(t_list *list)
{
	int	flag;
	int	prev;
	t_elem	*tmp;

	if (!list->elems)
		return (84);
	flag = 0;
	tmp = list->elems->prev;
	prev = list->elems->val;
	while (tmp != list->elems) {
		if (!flag)
			tmp = list->elems;
		flag = 1;
		if (tmp->val < prev)
			return (0);
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (0);
}
void	p_a(t_list *l_a, t_list *l_b)
{
	while (l_b->elems) {
		my_putstr(" pa");
		l_a->push_f(l_a, l_b->elems->val);
		l_b->pop(l_b);
	}
	my_putstr("\n");
}

void	push_swap(t_list *l_a, t_list *l_b)
{
	int		flag;
	int		min;
	t_elem	*tmp;

	min = get_min(l_a);
	flag = 0;
	while (l_a->elems && !is_sort(l_a)) {
		if (flag)
			my_putstr(" ");
		flag = 1;
		tmp = l_a->elems;
		if (tmp->val == min) {
			my_putstr("pb");
			l_b->push_f(l_b, tmp->val);
			l_a->pop(l_a);
			min = get_min(l_a);
		} else
			l_a->shift(l_a);
	}
	p_a(l_a, l_b);
}
