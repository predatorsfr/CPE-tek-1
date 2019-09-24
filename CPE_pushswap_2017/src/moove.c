/*
** EPITECH PROJECT, 2017
** moove.c
** File description:
** raphael.dubois@epitech.eu
*/
#include	<stdlib.h>
#include	"../include/my.h"

void	push_b(void *list, int val)
{
	t_elem	*new;
	t_list	*lst;

	lst = (t_list *)list;
	new = ((t_elem *)malloc(sizeof(t_elem)));
		if (new == NULL)
			return;
	new->val = val;
	new->next = new;
	new->prev = new;
	if (lst->elems) {
		new->next = lst->elems;
		new->prev = lst->elems->prev;
		lst->elems->prev->next = new;
		lst->elems->prev = new;
	} else
		lst->elems = new;
}

void	push_f(void *list, int val)
{
	t_list	*lst;

	lst = (t_list *)list;
	push_b(list, val);
	lst->elems = lst->elems->prev;
}

void	pop(void *list)
{
	t_list	*lst;
	t_elem	*tmp;

	lst = (t_list *)list;
	if (!lst->elems)
		return;
	if (lst->elems == lst->elems->next) {
		free(lst->elems);
		lst->elems = NULL;
	} else {
		tmp = lst->elems;
		lst->elems->prev->next = lst->elems->next;
		lst->elems->next->prev = lst->elems->prev;
		lst->elems = lst->elems->next;
		free(tmp);
	}
}

void	ra(void *list)
{
	t_list	*lst;

	my_putstr("ra");
	lst = (t_list *)list;
	if (!lst->elems)
		return;
	lst->elems = lst->elems->next;
}

t_list	*create_list(void)
{
	t_list	*list;

	list = ((t_list *)malloc(sizeof(t_list)));
		if (list == NULL)
			return (NULL);
	list->push_back = &push_b;
	list->push_f = &push_f;
	list->pop = &pop;
	list->shift = &ra;
	list->elems = NULL;
	return (list);
}
