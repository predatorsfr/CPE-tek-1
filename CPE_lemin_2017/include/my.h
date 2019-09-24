/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** lib header
*/

#ifndef HEADER_H_
#define HEADER_H_
#include "lemin.h"
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

int char_num(char c);
int	char_alpha(char c);
void	my_putchar(char c);
int	char_alphanum(char c);
char	*my_revstr(char *str);
int	is_num(char const *str);
int	puterr(char const *str);
int	is_alpha(char const *str);
int	alphanum(char const *str);
int	find_dash(char const *str);
int	my_getnbr(char const *str);
int	my_strlen(char const *str);
int	my_putstr(char const *str);
char	*my_strdup(char const *src);
int	is_num_spaces(char const *str);
char	*my_strcat(char *dest, char const *src);
char	*my_strcpy(char *dest, char const *src);
int	my_strcmp(char const *s1, char const *s2);
int	my_strncmp(char const *s1, char const *s2, int n);
long my_put_nbr(long a);
void prt(lemin_t *info);
#endif
