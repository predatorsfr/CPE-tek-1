/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void wheel_dir(sensors_t *sensors)
{
	float var = 0.0;

	if (sensors->sleft < 400) {
		var = 1 - (400/sensors->sleft);
		dprintf(STDERR_FILENO, "l > r\n");
		dprintf(STDOUT_FILENO, "WHEELS_DIR:%f\n", var);
	}
	if (sensors->sright < 400) {
		dprintf(STDERR_FILENO, "r < l\n");
		dprintf(STDOUT_FILENO, "WHEELS_DIR:-0.3\n");
	}
	if (sensors->smiddle <= 400) {
		dprintf(STDOUT_FILENO, "CAR_FORWARD:0,4\n");
	} else
		dprintf(STDOUT_FILENO, "CAR_FORWARD:1.0\n");
	dprintf(STDERR_FILENO, "r = %f\n", sensors->sleft);
	dprintf(STDERR_FILENO, "m = %f\n", sensors->smiddle);
	dprintf(STDERR_FILENO, "l = %f\n", sensors->sright);
}

void get_float_lidar(char *line, sensors_t *sensors)
{
	char **sensortab = count_input(line);

	sensors->sleft = atof(sensortab[4]);
	sensors->smiddle = atof(sensortab[18]);
	sensors->sright = atof(sensortab[33]);
	wheel_dir(sensors);
}

char **get_lidar(sensors_t *sensors)
{
	char *line = NULL;
	size_t len = 0;

	dprintf(STDOUT_FILENO, "GET_INFO_LIDAR\n");
	getline(&line, &len, stdin);
	for (int i = 0; line[i] != '\0'; i++)
		if (line[i] == '.')
			get_float_lidar(line, sensors);
	return (0);
}

void make_loop(void)
{
	sensors_t sensors;

	dprintf(STDOUT_FILENO, "START_SIMULATION\n");
	while (1) {
		dprintf(STDOUT_FILENO, "CAR_FORWARD:0,4\n");
		get_lidar(&sensors);
	}
	dprintf(STDOUT_FILENO, "STOP_SIMULATION\n");
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	make_loop();
	return (0);
}
