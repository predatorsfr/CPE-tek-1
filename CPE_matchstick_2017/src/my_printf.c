/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** raphael.dubois@epitech.eu
*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../my.h"

int flags1(int	i, char *str, va_list ap)
{
	if (str[i] == '%') {
		i++;
		switch (str[i]) {
		case 's':
			my_putstr(va_arg(ap, char*));
			break;
		case 'd':
			my_put_nbr(va_arg(ap, int));
			break;
		default:
			write(1, "%", sizeof(char));
			write(1, &str[i], sizeof(char));
		}
	}
}

void compile(va_list ap, int     i, char *str)
{
	while (str[i] != 0) {
		flags1(i, str, ap);
		if (str[i] == '%')
			i++;
		else
			write(1, &str[i], sizeof(char));
		i++;
	}
}

int my_printf(char *str, ...)
{
	int	i = 0;
	va_list	ap;

	va_start(ap, str);
	compile(ap, i, str);
	va_end(ap);
	return 0;
}
