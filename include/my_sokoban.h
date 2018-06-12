/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef MY_SOKOBAN_H
#define MY_SOKOBAN_H

#include "struct.h"
#include "const.h"
#include "macro.h"
#include <ncurses.h>

//handle_map.c
int create_map(char const *file_name, map_t *map);
void display_map(map_t const *map);
//void display_map(map_t const *map, int const pos_p);

//game_loop.c
void game_loop(map_t *map);

//move.c
int move_p(map_t *map, int pos_p, int n);

//test_map.c
int test_walls(map_t const * const map);
int test_map(char const * const map);

#endif
