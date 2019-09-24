/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

int get_input(void);
char **count_input(char *input);
char ** my_str_to_word_tab(char *lidar);

typedef struct sensors {
	float sleft;
	float smiddle;
	float sright;

} sensors_t;

#endif
