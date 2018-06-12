/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Contains functions that handles the map string.
*/

#include <stdlib.h>
#include "my.h"
#include "my_sokoban.h"

char *create_str(FILE * const file)
{
	char *str = NULL;
	char *line = NULL;
	size_t alloc = 0;

	while (getline(&line, &alloc, file) != -1) {
		if (line == NULL) {
			free(str);
			return (NULL);
		}
		str = my_pushstr_back(str, line);
		if (str == NULL) {
			free(line);
			return (NULL);
		}
	}
	free(line);
	return (str);
}

char *load_str(char const *file_name, int *pos_p)
{
	int i = 0;
	char *str = NULL;
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
		return (NULL);
	str = create_str(file);
	if (str == NULL) {
		fclose(file);
		return (NULL);
	}
	if (test_map(str) == 84) {
		free(str);
		fclose(file);
		return(NULL);
	}
	for (i = 0 ; str[i] ; i++) {
		if (str[i] == 'P') {
			*pos_p = i;
			str[i] = ' ';
		}
	}
	fclose(file);
	return (str);
}

int get_dimensions(map_t *map)
{
	for (int i = 0 ; map->str[i] ; i++) {
		if (map->str[i] == '\n') {
			map->cols = i + 1;
			break;
		}
	}
	map->lines = 0;
	for (int i = 0 ; map->str[i] ; i++) {
		if (map->str[i] == '\n')
			map->lines++;
	}
	return (0);
}

int create_map(char const *file_name, map_t *map)
{
	map->str = load_str(file_name, &map->pos_p);
	if (map->str == NULL)
		return (84);
	if (get_dimensions(map) == 84) {
		free(map->str);
		return (84);
	}
	map->backup_str = my_strdup(map->str);
	if (map->backup_str == NULL) {
		free(map->str);
		return (84);
	}
	map->pos_init = map->pos_p;
	return (0);
}

void display_map(const  map_t *map)
{
	int len = my_strlen(map->str);
	int x = 0;
	int y = 0;

	move(LINES / 2 - map->lines / 2 - 1, COLS / 2 - map->cols / 2);
	for (int i = 0 ; i < len ; i++) {
		if (i == map->pos_p)
			printw("P");
		else
			printw("%c", map->str[i]);
		if (map->str[i] == '\n') {
			getyx(stdscr, x, y);
			y = COLS / 2 - map->cols / 2;
			move(x, y);
		}
	}
}