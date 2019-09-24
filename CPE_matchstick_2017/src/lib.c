/*
** EPITECH PROJECT, 2018
** lib
** File description:
**
*/

#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

void    my_putchar(char c)
{
	write(1, &c, 1);
}
int my_put_nbr(int nbr)
{
	if (nbr > 2147483647 || nbr == -2147483648) {
		write(1, "-2147483648", 11);
		return 0;
	}
	if (nbr > 9)
		my_put_nbr(nbr / 10);
	my_putchar((nbr % 10) + 48);
	return 0;
}

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return i;
}

int     my_putstr(char const *str)
{
	if (str == NULL) {
		write(1, "(null)", 6);
		return 0;
	}
	write(1, str, my_strlen(str));
	return 0;
}
int	my_atoi(char *nbr)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9') {
		res = res * 10 + nbr[i] - 48;
		i = i + 1;
	}
	if (nbr[0] == '-')
		res = res * -1;
	return (res);
}
