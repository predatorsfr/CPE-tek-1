/*
** EPITECH PROJECT, 2017
** libs.c
** File description:
** raphael.dubois@epitech.eu
*/
#include	<unistd.h>

int	my_strlen(const char *str)
{
	int     i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
void	my_putchar(char c)
{
	write(1, &c, 1);
}
void	my_putstr(const char *str)
{
	write(1, str, my_strlen(str));
}

void	my_put_nbr(int nbr)
{
	if (nbr < 0) {
		nbr = -nbr;
		my_putchar('-');
	}
	if (nbr > 9)
		my_put_nbr(nbr / 10);
	my_putchar((nbr % 10) + 48);
}

int	my_getnbr(char const *str)
{
	int	nb;
	int	isneg;
	int	i;

	isneg = 1;
	nb = 0;
	i = 0;
	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			isneg = isneg * -1;
		i = i + 1;
	}
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i = i + 1;
		} else
			return (nb * isneg);
	}
	return (nb * isneg);
}
