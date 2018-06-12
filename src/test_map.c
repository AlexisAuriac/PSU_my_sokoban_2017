/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Tests the map previously loaded.
*/

#include "struct.h"

int test_map(char const * const map)
{
	int nb_p = 0;
	int nb_o = 0;
	int nb_x = 0;

	for (int i = 0 ; map[i] ; i++) {
		if (map[i] == 'P')
			++nb_p;
		else if (map[i] == 'O')
			++nb_o;
		else if (map[i] == 'X')
			++nb_x;
		else if (map[i] != '#' && map[i] != ' ' && map[i] != '\n')
			return (84);
	}
	if (nb_p != 1 || nb_o > nb_x)
		return (84);
	return (0);
}
