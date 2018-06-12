/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Main file.
*/

#include "my.h"
#include "my_sokoban.h"

void help(void)
{
	my_putstr("USAGE\n");
	my_putstr("     ./my_sokoban map\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("     map  file representing the warehouse map,");
	my_putstr(" containing '#' for walls,\n");
	my_putstr("          'P' for the player,");
	my_putstr(" 'X' for boxes and 'O' for storage locations\n");
}

int main(int ac, char **av)
{
	map_t map;

	if (ac != 2)
		return (84);
	if (my_strcmp(av[1], "-h") == 0) {
		help();
		return (0);
	}
	if (create_map(av[1], &map) == 84)
		return (84);
	game_loop(&map);
	free(map.str);
	free(map.backup_str);
	return (0);
}
