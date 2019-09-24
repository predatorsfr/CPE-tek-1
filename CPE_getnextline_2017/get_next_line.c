/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** raphael.dubois@epitech.eu
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	char *buff;
	int size;
	
	if (fd == -1  || READ_SIZE < 1 || buff == NULL)
		return (NULL);
	buff = malloc(sizeof(char) * READ_SIZE + 1);
	size = read (fd , buff , READ_SIZE);
	if ( size <= 0)
		return (NULL);
	buff[size] = '\0';
	return buff;
}
