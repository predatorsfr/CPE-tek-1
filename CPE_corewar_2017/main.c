/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "include/my.h"
#define CHUNK 1024 /* read 1024 bytes at a time */

int main (int ac ,char **av )
{
char buf[CHUNK];
FILE *fp;
size_t nread;

fp = fopen(av[1], "r");
while( read(fp, buf, sizeof(fp)) < 0)
printf("1\n");
return 0;
}
