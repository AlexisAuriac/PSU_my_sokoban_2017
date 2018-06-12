/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Contains functions that moves P.
*/

#include "struct.h"

static int move_box(map_t *map, int case1, int case2)
{
	if (map->str[case2] != '#' && map->str[case2] != 'X') {
		map->str[case1] = ' ';
		map->str[case2] = 'X';
		if (map->backup_str[case1] == 'O')
			map->str[case1] = 'O';
		return (1);
	} else
		return (0);
}

int move_p(map_t *map, int pos_p, int n)
{
	if (map->str[pos_p + n] == '#')
		return (pos_p);
	else if (map->str[pos_p + n] == 'X')
		pos_p += n * move_box(map, pos_p + n, pos_p + (n << 1));
	else
		pos_p += n;
	return (pos_p);
}
