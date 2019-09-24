/*
** EPITECH PROJECT, 2018
** putnbr
** File description:
** putnbr
*/

#include "my.h"

long my_put_nbr(long a)
{
	long b;

	if (a == -2147483648)
		my_putstr("-2147483648");
	if (a < 0) {
		my_putchar('-');
		a *= (-1);
	}
	if (a > 0) {
		if (a >= 10) {
			b = (a % 10);
			a = (a - b) / 10;
			my_put_nbr(a);
			my_putchar(48 + b);
		} else
			my_putchar(48 + a);
	}
	if (a == 0)
		my_putchar('0');
	return (0);
}
